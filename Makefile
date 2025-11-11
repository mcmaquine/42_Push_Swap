NAME = push_swap
BONUS = checker

CFLAGS = -Wall -Wextra -Werror -g

SRC =	src/main.c\
		src/parser.c\
		src/stack_functions_I.c\
		src/stack_functions_II.c\
		src/solver.c\
		src/ops_push_swap.c\
		src/ops_push_swap_II.c\
		src/push_swap_utils.c\
		src/turck.c
	
BONUS_SRC = bonus/bonus.c\
			bonus/stack_functions_I_bonus.c\
			bonus/stack_functions_II_bonus.c\
			bonus/ops_push_swap_bonus.c\
			bonus/ops_push_swap_II_bonus.c\
			bonus/parser_bonus.c\
			bonus/parser_com_list_bonus.c\
			bonus/utils_bonus.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

LFLAGS = -L$(LIBFT_DIR) -lft

.PHONY: all clean fclean re main bonus
all  : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $^ -o $@ $(LFLAGS)

bonus: $(BONUS_OBJ) $(LIBFT)
	$(CC) $^ -o $(BONUS) $(LFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

clean :
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all
