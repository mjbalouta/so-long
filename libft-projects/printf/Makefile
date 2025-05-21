
CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -I./Libft -g
NAME		= libftprintf.a

SRCS		= libftprintf.c ft_printletters.c ft_printnumbers.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS)
	@@echo "Compiling all files..."
	@ar rcs $(NAME) $(OBJS)

%.o: %.c libftprintf.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@@echo "Removing objects..."
	@rm -f $(OBJS)
	
fclean: clean #removes objects and library
	@@echo "Removing library..."
	@rm -f $(NAME)

re: fclean $(NAME) all

.PHONY: all clean fclean re
