##
## EPITECH PROJECT, 2021
## check_indentation
## File description:
## Makefile
##

LIBS = -I includes/

INCLUDES = -L libs/ -lmy

SRC =

NAME = indentation

all:	$(NAME)

$(NAME):
	$(MAKE) -C src/
	gcc main.c -o $(NAME) $(SRC) $(LIBS) $(INCLUDES) -w -W -Werror -g

fclean_others:
	make fclean -C src/

clean:
	find -name "vgcore.*" -delete

fclean:	clean
	make fclean -C src/
	rm -f $(NAME)

re:	fclean all