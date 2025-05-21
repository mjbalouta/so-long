
CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -I./Libft -g
NAME		= complete_libft.a

SRCS		= ./get-next-line/get_next_line.c ./get-next-line/get_next_line_utils.c
OBJS		= $(SRCS:.c=.o)
LIBFT_DIR 	= ./libft
LIBFT 		= ./libft/libft.a
PRINTF_DIR 	= ./printf
PRINTF 		= ./printf/libftprintf.a

all: $(NAME) 

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	@@echo "Compiling gnl..."
#cp copies libft library to the final output
	@cp $(LIBFT) $(NAME)
	@cp $(PRINTF) $(NAME)
	@ar rcs $(NAME) $(OBJS)
#this tool creates and index for the static library
	@ranlib $(NAME)

$(LIBFT): $(LIBFT_SRC)
	@@echo "Compiling libft..."
#libft depends on libft_dir: if libft is out of date, make will update it
#this make refers to the libft makefile (-C tells make to change directory to libft_dir)
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	
$(PRINTF): $(PRINTF_SRC)
	@@echo "Compiling printf..."
#libft depends on libft_dir: if libft is out of date, make will update it
#this make refers to the libft makefile (-C tells make to change directory to libft_dir)
	@$(MAKE) -C $(PRINTF_DIR) > /dev/null

%.o: %.c ./get-next-line/get_next_line.h
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
