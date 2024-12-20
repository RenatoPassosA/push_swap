NAME = push_swap
CC = cc
CCFLAGS = -Wall -Wextra -Werror -g
SRC = push_swap.o small_numbers.o ft_atol.o ft_join.o ft_splitlst.o input_handling.o moves.o struct_utils.o

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CCFLAGS) -o $(NAME) $(SRC)

.o:.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(SRC)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all bonus clean fclean
