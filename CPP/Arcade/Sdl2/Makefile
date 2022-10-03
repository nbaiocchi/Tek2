##
## EPITECH PROJECT, 2022
## B-OOP-400-LYN-4-1-arcade-abdelkarim.bengrine
## File description:
## Makefile
##

SRC     =   libSdl.cpp \
			../Event/Event.cpp	\
			libManagement.cpp

CFLAGS	+=	-fPIC -Wextra -Wall -Werror -

CFLAGS	+=	-I ../../include/

OBJ     =	$(SRC:.c=.o)

NAME	=   arcade_sdl2.so

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ $(OBJ) -o $(NAME) -shared -fPIC -lSDL2 -lSDL2_ttf -lSDL2_image -std=c++17

clean:
	rm -f $(NAME)

fclean:	clean

re:	fclean all

.PHONY: all clean fclean re
