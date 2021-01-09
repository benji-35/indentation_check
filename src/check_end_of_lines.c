/*
** EPITECH PROJECT, 2021
** indentation_check
** File description:
** check_end_of_lines
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int lenght(char *str);
int good_extension(char *path, list *l);
int get_line_by_char(char *read, int c);

void display_end_of_line(char c, char *path, int index, char *read, int *nb_spaces)
{
    if (c != ' ')
        return;
    printf("[\e[1;5;31mEND SPACE\e[0m] line: %d, path : %s\n", get_line_by_char(read, index),
    path);
    *nb_spaces = *nb_spaces + 1;
}

void check_end_of_line(char *path, char *read, int inden, list *l, int *nb_space, list *ext_o)
{
    int size = lenght(read);
    if (read == NULL)
        return;
    if (good_extension(path, l) == 0)
        return;
    if (ext_o != NULL && good_extension(path, ext_o))
        return;
    for (int i = 0; i < size; i++) {
        if (read[i] == '\n' || i == size - 1)
            display_end_of_line(read[i - 1], path, i, read, nb_space);
    }
}