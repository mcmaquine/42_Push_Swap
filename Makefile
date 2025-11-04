NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -g

SRC =	src/main.c\
		src/parser.c\
		src/stack_functions_I.c\
		src/stack_functions_II.c\
		src/solver.c\
		src/ops_push_swap.c\
		src/ops_push_swap_II.c\
		src/push_swap_utils.c\
		src/lifo_func.c\
		src/sorting_util.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

LFLAGS = -L$(LIBFT_DIR) -lft

.PHONY: all clean fclean re main
all  : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	cc $^ -o $@ $(LFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all
