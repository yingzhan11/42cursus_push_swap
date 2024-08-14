NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c check_argc.c stack_init.c stack_update.c stack_move.c stack_tools.c \
	small_sort.c tools.c free.c ft_split.c op_push.c op_rev_rotate.c op_rotate.c op_swap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@cc $(CFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)\n"


$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
