##
## EPITECH PROJECT, 2022
## B-OOP-400-LYN-4-1-arcade-abdelkarim.bengrine
## File description:
## Makefile
##

SRC     =   libNcurses.cpp	\
			../Event/Event.cpp	\
			libManagement.cpp

CFLAGS	+=	-fPIC -Wextra -Wall -Werror

CFLAGS	+=	-I ../../include/

OBJ     =	$(SRC:.c=.o)

NAME	=   arcade_ncurses.so

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ $(OBJ) -o $(NAME) -shared -fPIC -lncurses

clean:
	rm -f $(NAME)

fclean:	clean

re:	fclean all

.PHONY: all clean fclean re
