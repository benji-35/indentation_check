/*
** EPITECH PROJECT, 2021
** check_indentation
** File description:
** good_extension
*/

#include <stdlib.h>
#include "my.h"

char *get_extension(char *path)
{
    int to_mal = 0;
    int size = lenght(path);
    char *ext = NULL;
    for (int i = size - 1; i >= 0; i--)
    {
        to_mal++;
        if (path[i] == '/')
            return (NULL);
        if (path[i] == '.')
            break;
    }
    ext = malloc(sizeof(char) * (to_mal + 1));
    for (int i = 0; i < to_mal; i++)
        ext[(to_mal - 1) - i] = path[size - 1 - i];
    ext[to_mal] = 0;
    return (ext);
}

int good_extension(char *path, list *l)
{
    char *extension = get_extension(path);
    if (extension == NULL)
        return (1);
    while (l != NULL)
    {
        if (str_equality(extension, l->extension)) {
            free(extension);
            return (0);
        }
        l = l->next;
    }
    free(extension);
    return (1);
}