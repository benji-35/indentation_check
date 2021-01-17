/*
** EPITECH PROJECT, 2021
** indentation_check
** File description:
** move_str
*/

#include <stdlib.h>
int lenght(char *str);

char *move_str_left(char *str, int nb)
{
    int size = lenght(str);
    int new_size = size - nb;
    char *result = malloc(sizeof(char) * (new_size + 1));

    for (int i = nb - 1; i < size; i++)
        result[i - (nb - 1)] = str[i];
    result[new_size] = 0;
    return (result);
}