# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 15:16:30 by mjoao-fr          #+#    #+#              #
#    Updated: 2025/06/02 15:16:30 by mjoao-fr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -g -I./libft-projects
NAME		= so_long
SRCS		= main.c validate_map.c
OBJS		= $(SRCS:.c=.o)
LIBFT_DIR 	= ./libft-projects
LIBFT 		= ./libft-projects/complete_libft.a

all: $(NAME) 

$(NAME): $(LIBFT) $(OBJS)
	@@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	
%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@@echo "Removing objects..."
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(OBJS) 

fclean: clean
	@@echo "Removing executable..."
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
