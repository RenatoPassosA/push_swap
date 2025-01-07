NAME = push_swap
CC = cc
CCFLAGS = -Wall -Wextra -Werror -g
SRC = push_swap.o small_numbers.o input_handling.o moves.o moves2.o moves3.o utils1.o utils2.o utils3.o

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
