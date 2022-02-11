/*
** EPITECH PROJECT, 2021
** indentation_check
** File description:
** check_lines
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int good_extension(char *path, list *l);
int get_line_by_char(char *read, int c);

void disp_lines(char *path, int nb, int theorics, int index, char *read, int *errors)
{
    int line = get_line_by_char(read, (index - nb));
    int curr = 1;
    for (int i = index - nb; i < index; i++) {
        if (read[i] == '\n')
            curr++;
    }
    if (curr <= theorics + 1)
        return;
    *errors = *errors + 1;
    printf("[\e[1;5;36mLINES IN FUNCTION\e[0m] line = %d, path = %s:%d -> get : %d, want : %d\n", line, path, line, curr - 1, theorics);
}

void check_line(char *read, char *path, list *l, list *ext_o, int theorics, int *errors)
{
    int size = 0;
    int braket = 0;
    if (read == NULL)
        return;
    if (good_extension(path, l) == 0)
        return;
    if (ext_o != NULL && good_extension(path, ext_o))
        return;
    for (int i = 0; i < lenght(read); i++) {
        if (read[i] == '{') {
            braket ++;
        } else if (read[i] == '}') {
            braket--;
            if (braket == 0) {
                disp_lines(path, size, theorics, i, read, errors);
                size = 0;
            }
        } else {
            if (braket > 0)
                size++;
        }
    }
}