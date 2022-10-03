##
## EPITECH PROJECT, 2021
## day01
## File description: Makefile lib
## piscinecpp
##

SRC		=	$(wildcard ./src/*.cpp)			\
			$(wildcard ./src/Components/*.cpp)			\
			$(wildcard ./src/Pins/*.cpp)			\
			$(wildcard ./src/Tools/*.cpp)			\
			$(wildcard ./src/Circuit/*.cpp)			\
			$(wildcard ./src/SpecialComponents/*.cpp)			\
			$(wildcard ./src/Factory/*.cpp)			\
			$(wildcard ./src/Gates/*.cpp)			\

OBJ		= 	$(SRC:.cpp=.o)

CFLAGS	+=	-Iinclude --std=c++20 -Wall -Wextra -Werror

NAME	=	nanotekspice

all:	$(NAME)

.cpp.o:
	g++ $(CFLAGS) -c $< -o $@

$(NAME):    $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "\033[0;34m<deleted all .o>\033[00m"
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)
	rm -rf *.txt

fclean: clean
	rm -f $(NAME)

re: fclean all
