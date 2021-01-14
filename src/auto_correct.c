/*
** EPITECH PROJECT, 2021
** indentation_check
** File description:
** auto_correct
*/

#include <stdio.h>
#include "my.h"
int good_extension(char *path, list *l);

void auto_correct(char *read, char *path, int indentation, list *l, list *ext_o)
{
    if (read == NULL)
        return;
    if (good_extension(path, l) == 0)
        return;
    if (ext_o != NULL && good_extension(path, ext_o))
        return;
    printf("auto correct -> %s\n", path);
}