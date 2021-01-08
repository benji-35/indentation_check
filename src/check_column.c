/*
** EPITECH PROJECT, 2021
** indentation_check
** File description:
** check_column
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int get_line_by_char(char *read, int c);

void display_column(char *path, int max_col, int col, int *nb, char *read, int i)
{
    if (col <= max_col)
        return;
    *nb = *nb + 1;
    printf("[\e[1;5;33mCOLUMN\e[0m] line: %d, path : %s get %d column, want : %d\n", get_line_by_char(read, i),
    path, col, max_col);
}

void check_column(char *path, char *read, int *nb, int col)
{
    int curr = 0;
    for (int i = 0; i < lenght(read); i++) {
        if (read[i] == '\n') {
            display_column(path, col, curr, nb, read, i);
            curr = 0;
        } else {
            curr++;
        }
    }
    display_column(path, col, curr, nb, read, (lenght(read) - 1));
}