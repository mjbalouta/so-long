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

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -I$(LIBFT_DIR)
NAME        = so_long
SRCS        = main.c validate_map.c so_long_utils.c check_path.c render_window.c move_player.c
OBJS        = $(SRCS:.c=.o)
LIBFT_DIR   = ./libft-projects
LIBFT       = $(LIBFT_DIR)/complete_libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -I/usr/include -O3 -c $< -o $@

clean:
	@echo "Removing objects..."
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing executable..."
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
