##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Made by enzo lenzi
##

SRC     =   $(wildcard ./Core/*.cpp)			\
            main.cpp		\
			$(wildcard ./Event/*.cpp)			\
			$(wildcard ./Component/*.cpp)			\

CFLAGS	=	-Wall -Wextra -Werror -I ../include/ -std=c++17 -g3

LDFLAGS	=	 -ldl

OBJ     =	$(SRC:.cpp=.o)

NAME	=   arcade

all:	$(NAME) games graphicals core

$(NAME):	$(OBJ)
	mkdir -p ./lib

	
	g++ $(OBJ) -o $(NAME) $(LDFLAGS)

%.o:	%.cpp
	g++ -c $(CFLAGS) $< -o $@

core: $(NAME)
$(NAME):	$(OBJ)
	g++ $(OBJ) -o $(NAME) $(LDFLAGS)
games: 
	mkdir -p ./lib

	make -C Games/Nibbler
	cp ./Games/Nibbler/arcade_nibbler.so ./lib/.

	make -C Games/Pacman
	cp ./Games/Pacman/arcade_pacman.so ./lib/.

	make -C Games/Menu
	cp ./Games/Menu/arcade_menu.so ./lib/.
graphicals:
	mkdir -p ./lib
	make -C Ncurses
	make -C Sdl2
	make -C Sfml
	cp ./Ncurses/arcade_ncurses.so ./lib/.
	cp ./Sfml/arcade_sfml.so ./lib/.
	cp ./Sdl2/arcade_sdl2.so ./lib/.
clean:
	make clean -C Ncurses
	make clean -C Sdl2
	make clean -C Sfml

	make clean -C Games/Nibbler
	make clean -C Games/Pacman
	make clean -C Games/Menu

	rm -f $(OBJ)

fclean:	clean
	make fclean -C Ncurses
	make fclean -C Sdl2
	make fclean -C Sfml

	make fclean -C Games/Nibbler
	make fclean -C Games/Pacman
	make fclean -C Games/Menu
	rm -f $(NAME)
	rm -f ./lib/*.so

re:	fclean all
	make re -C Ncurses
	make re -C Sdl2
	make re -C Sfml

	make re -C Games/Nibbler
	make re -C Games/Nibbler
	make re -C Games/Nibbler

.PHONY: all clean fclean re
