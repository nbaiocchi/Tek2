NAME = wolfram

.PHONY: all
all: $(NAME)

$(NAME): $(shell find src -type f -name "*.hs") app/Main.hs
	stack build

.PHONY: clean
clean:
	stack clean

.PHONY: fclean
fclean: clean
	stack purge
	$(RM) $(NAME)

.PHONY: tests_run
tests_run:
	stack test

.PHONY: re
re: fclean all
