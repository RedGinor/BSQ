##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makesfiles
##

SRC	=	file_data.c	\
		main.c

NAME 	=	bsq

all:	$(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME)

clean:

fclean:	clean
	rm -f $(NAME)

re: 	fclean all

## tests_clean:
##	rm -f *.gcda
##	rm -f *.gcno
##	rm -f unit_tests

## tests_run:
##	gcc -o unit_tests $(SRC) tests/test_myprintf.c --coverage -lcriterion
##	./unit_tests
