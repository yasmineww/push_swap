NAME = push_swap

NAME_BONUS = checker

SRC = main.c parsing.c utils.c utils_2.c ft_split.c actions.c sorting.c algo.c utils_algo.c rotations.c

BONUS = push_swap_bonus.c get_next_line.c get_next_line_utils.c parsing.c utils.c utils_2.c ft_split.c actions.c sorting.c algo.c utils_algo.c rotations.c

OBJ = $(SRC:.c=.o) 

BONUS_OBJ = $(BONUS:.c=.o) 

FLAG = -Wall -Wextra -Werror -g

HEADER = push_swap.h

all: $(NAME)

%.o: %.c $(HEADER)
	cc $(FLAG) -c $<

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJ)
	cc $(BONUS_OBJ) -o $(NAME_BONUS)
	
bonus: $(NAME_BONUS)  

clean:
	rm -rf $(OBJ) $(BONUS_OBJ) 

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all