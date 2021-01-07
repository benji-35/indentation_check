##
## EPITECH PROJECT, 2021
## check_indentation
## File description:
## Makefile
##

SRC = can_open.c	\
	check_indentation.c	\
	read_file.c	\
	str_equality.c	\
	display_help.c	\
	check_directory.c	\
	contain_str.c	\
	get_number.c	\
	add_node.c	\
	free_list.c	\
	good_extension.c	\
	duplicate_str.c

OBJ = $(SRC:.c=.o)

HEADER = my.h

NAME = libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	rm -f $(OBJ)
	cp $(NAME) ../$(NAME)
	cp $(HEADER) ../includes/$(HEADER)
	rm -f $(NAME)

fclean:
	rm -f ../$(NAME)
	rm -f ../includes/$(HEADER)

re:	fclean all