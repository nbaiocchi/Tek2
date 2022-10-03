##
## EPITECH PROJECT, 2022
## Assembly
## File description:
## Makefile
##

SRC =	$(wildcard *.asm)			\


OBJ =	$(SRC:.asm=.o)

%.o: %.asm
	nasm -f elf64 -shared $< -o $@

NAME =	libasm.so

all:	$(NAME)
		@echo -e "\033[0;34m<$(NAME) has been created>\033[00m"

$(NAME):	$(OBJ)
	ld -fPIC -o $(NAME) -shared  $(OBJ)
	@echo -e "\033[0;34m<deleted all .o>\033[00m"
	rm -f $(OBJ)

clean:
	@echo -e "\033[0;34m<Deleting useless files>\033[00m"
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all 