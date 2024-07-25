NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

HEADERS = -I $(LIBFT_DIR)

SRCS = main.c check_argc.c push_swap.c update_node.c sort_three.c \
		tools.c free.c op_push.c op_rev_rotate.c op_rotate.c op_swap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@cc $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"


$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	cc $(OBJS) $(LIBFT_A) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: clean all

.PHONY: all clean fclean re