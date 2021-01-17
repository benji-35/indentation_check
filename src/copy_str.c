/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** copy_str
*/

#include <stdlib.h>

int lenght(char *str);

char *copy_str(char *str)
{
    int size = lenght(str);
    char *result = malloc(sizeof(char) * (size + 1));

    for (int i = 0; i < size; i++)
        result[i] = str[i];
    result[size] = 0;
    return (result);
}