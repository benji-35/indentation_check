/*
** EPITECH PROJECT, 2021
** indentation_check
** File description:
** auto_correct
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

int good_extension(char *path, list *l);

void auto_correct_spaces(char **line)
{

}

void auto_correct_inden(char **line)
{

}

void auto_correct(char *read, char *path, int indentation, list *l, list *ext_o)
{
    char back = '\n';
    if (read == NULL)
        return;
    if (good_extension(path, l) == 0)
        return;
    if (ext_o != NULL && good_extension(path, ext_o))
        return;
    char **lines = split_str(read, '\n');
    if (lines == NULL)
        return;
    for (int i = 0; lines[i][0] != 0; i++) {
        if (lines[i] != NULL) {
            auto_correct_spaces(&(lines[i]));
            auto_correct_inden(&(lines[i]));
        }
    }
    char *result = split_to_char(lines, &back);
    re_write(path, result);
    free_split(lines);
    free(result);
}