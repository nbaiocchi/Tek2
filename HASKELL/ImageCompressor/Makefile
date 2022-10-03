##
## EPITECH PROJECT, 2022
## ImageCompressor
## File description:
## Makefile
##

NAME = imageCompressor

all: $(NAME)

$(NAME): $(shell find src -type f -name "*.hs") app/Main.hs
	@printf "\n\e[1;33mBuilding project...\e[0m\n"
	@stack build
	@printf "\e[1;32mProject successfully built !\e[0m\n\n"

clean:
	@printf "\n\e[1;33mCleaning directory...\e[0m\n"
	@stack clean
	@find -name "*.o" -delete -o -name "*.hi" -delete
	@printf "\e[1;32mDirectory cleaned !\e[0m\n"

fclean: clean
	@printf "\e[1;33mPurging existing files...\e[0m\n"
	@stack purge
	@$(RM) $(NAME)
	@printf "\e[1;32mOld compiled files deleted !\e[0m\n"

tests_run:
	@stack test

re: fclean all

.PHONY: all clean fclean re tests_run