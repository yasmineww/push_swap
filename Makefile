NAME = push_swap

NAME_BONUS = checker

SRC = main.c parsing.c utils.c ft_split.c actions.c sorting.c algo.c utils_algo.c rotations.c

BONUS = bonus/push_swap_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c bonus/parsing_bonus.c bonus/utils_bonus.c bonus/ft_split_bonus.c bonus/actions_bonus.c

OBJ = $(SRC:.c=.o) 

BONUS_OBJ = $(BONUS:.c=.o)

FLAG = -Wall -Wextra -Werror

HEADER = push_swap.h

HEADER_BONUS = bonus/push_swap_bonus.h

all: $(NAME)

%_bonus.o: %_bonus.c $(HEADER_BONUS)
	$(CC) $(FLAG) -c $< -o $@

%.o: %.c $(HEADER)
	$(CC) $(FLAG) -c $<

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) -o $(NAME_BONUS)

bonus: $(BONUS_OBJ)
	$(CC) $(FLAG) $(BONUS_OBJ) -o $(NAME_BONUS)

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all