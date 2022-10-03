##
## EPITECH PROJECT, 2022
## myTeams
## File description:
## Makefile
##

NAME		=	myteams_cli

CC			=	gcc

SRC_FOLDER	=	./src

SRC			=	$(wildcard $(SRC_FOLDER)/*.c)	\
				$(wildcard $(SRC_FOLDER)/command/*.c)

OBJ			=	$(SRC:.c=.o)

INCLUDE		=	-I ./includes

LIBINCLUDE	=	-I ../libs/myteams

MYTEAMSLIB	=	-L ../libs/myteams/ -lmyteams

UUIDLIB		=	-luuid

CFLAGS	=	-g -Wall -Wextra -Werror

CP			=	cp -f

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(SRC) $(INCLUDE) $(LIBINCLUDE) $(MYTEAMSLIB) \
		$(UUIDLIB) $(CFLAGS)
	$(CP) $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re:			fclean all

.PHONY:		all clean fclean re
