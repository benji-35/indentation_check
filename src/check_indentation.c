/*
** EPITECH PROJECT, 2021
** check_indentation
** File description:
** check_indentation
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int lenght(char *str);
int good_extension(char *path, list *l);

int divisible_by(int nb, int div)
{
    int get = nb / div;
    float get_f = (float)nb / (float)div;
    if (get_f == (float)get)
        return (1);
    return (0);
}

int get_line_by_char(char *read, int c)
{
    int nb = 1;
    for (int i = 0; i < c; i++) {
        if (read[i] == 0)
            break;
        if (read[i] == '\n')
            nb++;
    }
    return (nb);
}

void display_checking(int __char, int number, char *path, char *read, int inden, int *nb_inden)
{
    if (divisible_by(number, inden) || number == 0)
        return;
    printf("[\e[1;5;32mINDENTATION\e[0m] line: %d, path : %s:%d get %d spaces, want : %d\n", get_line_by_char(read, __char),
    path, get_line_by_char(read, __char), number, inden);
    *nb_inden = *nb_inden + 1;
}

void verif(char *read, int *i, int *curr_spaces, char *path, int size, int inden, int *nb_inden)
{
    if (read[*i] == '\n') {
        *curr_spaces = 0;
        return;
    }
    if (read[*i] == ' ' || read[*i] == '\t') {
        if (read[*i] == '\t') {
            *curr_spaces = *curr_spaces + 4;
        } else {
            *curr_spaces = *curr_spaces + 1;
        }
        return;
    }
    display_checking(*i, *curr_spaces, path, read, inden, nb_inden);
    for (; read[*i] != 0; *i = *i + 1) {
        if (read[*i] == '\n') {
            *i = *i + 1;
            break;
        }
    }
    *curr_spaces = 0;
    if (read[*i] == 0)
        return;
    verif(read, i, curr_spaces, path, size, inden, nb_inden);
}

void check_indentation(char *path, char *read, int inden, list *l, int *nb_inde, list *ext_o)
{
    int size = lenght(read);
    int curr_spaces = 0;
    if (read == NULL)
        return;
    if (good_extension(path, l) == 0)
        return;
    if (ext_o != NULL && good_extension(path, ext_o))
        return;
    for (int i = 0; i < size; i++)
        verif(read, &i, &curr_spaces, path, size, inden, nb_inde);
}