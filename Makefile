NAME = get
SRC = get_next_line.c get_next_line_utils.c main.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -I . -Wall -Werror -Wextra -g3 -fsanitize=address

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all
