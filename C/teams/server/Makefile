##
## EPITECH PROJECT, 2022
## myTeams
## File description:
## Makefile
##

NAME		=	myteams_server

CC			=	gcc

SRC_FOLDER	=	./src

SRC			=	$(wildcard $(SRC_FOLDER)/*.c) 					\
				$(wildcard $(SRC_FOLDER)/commands/*.c) 			\
				$(wildcard $(SRC_FOLDER)/events/*.c) 			\
				$(wildcard $(SRC_FOLDER)/middleware/*.c) 		\
				$(wildcard $(SRC_FOLDER)/teams/*.c)				\
				$(wildcard $(SRC_FOLDER)/teams/channels/*.c)	\
				$(wildcard $(SRC_FOLDER)/teams/replies/*.c)		\
				$(wildcard $(SRC_FOLDER)/teams/teams/*.c)		\
				$(wildcard $(SRC_FOLDER)/teams/threads/*.c)		\
				$(wildcard $(SRC_FOLDER)/user/*.c) 				\
				$(wildcard $(SRC_FOLDER)/utils/*.c)

OBJ			=	$(SRC:.c=.o)

INCLUDE		=	-I ./includes

LIBINCLUDE	=	-I ../libs/myteams

MYTEAMSLIB	=	-L ../libs/myteams/ -lmyteams

UUIDLIB		=	-luuid

CCFLAGS		=	-g -Wall -Wextra -Werror

CP			=	cp -f

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(SRC) $(INCLUDE) $(LIBINCLUDE) $(MYTEAMSLIB) \
		$(UUIDLIB) $(CCFLAGS)
	$(CP) $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re:			fclean all

.PHONY:		all clean fclean re
