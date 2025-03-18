##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SFML = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm -g3

SRC = $(shell find ./src/ -name '*.c')

OBJ = $(SRC:.c=.o)

NAME = my_hunter

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(SFML)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

play: re
	./$(NAME)
	make fclean
