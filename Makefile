NAME = get
SRC = draft3.c get_next_line_utils.c main.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
