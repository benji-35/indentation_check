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
	duplicate_str.c	\
	check_end_of_lines.c	\
	display_resume.c	\
	check_column.c	\
	replace_tabs.c	\
	str_contain.c	\
	replace_char_in_str.c	\
	auto_correct.c	\
	concat_str.c	\
	copy_str.c	\
	split_str.c	\
	split_to_str.c

OBJ = $(SRC:.c=.o)

HEADER = my.h

NAME = libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	rm -f $(OBJ)
	cp $(NAME) ../libs/$(NAME)
	cp $(HEADER) ../includes/$(HEADER)
	rm -f $(NAME)

fclean:
	rm -f ../libs/$(NAME)
	rm -f ../includes/$(HEADER)

re:	fclean all