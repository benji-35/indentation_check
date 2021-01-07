/*
** EPITECH PROJECT, 2021
** check_indentation
** File description:
** duplicate_str
*/

#include <stdlib.h>

int lenght(char *str);

char *duplicate_str(char *str)
{
    int size = lenght(str);
    char *new_str = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < size; i++)
        new_str[i] = str[i];
    new_str[size] = 0;
    return (new_str);
}