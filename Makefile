
CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -I./Libft -g
NAME		= so_long.a

SRCS		= main.c
OBJS		= $(SRCS:.c=.o)
LIBFT_DIR 	= ./libft-projects
LIBFT 		= ./libft-projects/complete_libft.a

all: $(NAME) 

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	@@echo "Compiling gnl..."
#cp copies libft library to the final output
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)
#this tool creates and index for the static library
	@ranlib $(NAME)

$(LIBFT): $(LIBFT_SRC)
	@@echo "Compiling libft..."
#libft depends on libft_dir: if libft is out of date, make will update it
#this make refers to the libft makefile (-C tells make to change directory to libft_dir)
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	
%.o: %.c get_next_line.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@@echo "Removing objects..."
#/dev/null cleans commands from the output
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null
	@$(MAKE) clean -C $(PRINTF_DIR) > /dev/null
	@rm -f $(OBJS) 

fclean: clean
	@@echo "Removing library..."
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null
	@$(MAKE) fclean -C $(PRINTF_DIR) > /dev/null
	@rm -f $(NAME)

re: fclean $(NAME) all

.PHONY: all clean fclean re
