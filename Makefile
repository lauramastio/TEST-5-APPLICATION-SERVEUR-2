##
## SYSNAV PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC = $(shell echo src/*.c)

OBJ = $(SRC:.c=.o)

NAME = escapefire
all: $(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ) -g

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
