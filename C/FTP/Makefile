##
## EPITECH PROJECT, 2022
## B-NWP-400-LYN-4-1-myftp-noe.baiocchi
## File description:
## Makefile
##

SRC		=	$(wildcard ./serveur/*.c)			\

OBJ		=	$(SRC:.c=.o)

NAME	=	myftp

CFLAGS	=	-W -Wall -Wextra -g

all:	$(NAME)
		@echo -e "\033[0;34m<$(NAME) has been created>\033[00m"

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME)
	@echo -e "\033[0;34m<deleted all .o>\033[00m"
	rm -f $(OBJ)

clean:
	@echo -e "\033[0;34m<Deleting useless files>\033[00m"
	rm -f $(OBJ)

fclean:    clean
	rm -f $(NAME)

re:	fclean all