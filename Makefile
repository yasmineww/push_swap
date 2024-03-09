NAME = push_swap

SRC = main.c parsing.c utils.c ft_split.c actions.c sorting.c algo.c utils_algo.c rotations.c

BONUS =

OBJ = $(SRC:.c=.o) 

BONUS_OBJ = 

FLAG = -Wall -Wextra -Werror -g

HEADER = push_swap.h

all: $(NAME)

%.o: %.c $(HEADER)
	cc $(FLAG) -c $<

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME)
	
bonus: $(BONUS_OBJ)
	$(NAME) $(BONUS_OBJ)

clean:
	rm -rf $(OBJ) $(BONUS_OBJ) 

fclean: clean
	rm -rf $(NAME)

re: fclean all