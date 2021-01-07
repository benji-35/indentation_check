/*
** EPITECH PROJECT, 2021
** check_indentation
** File description:
** str_equality
*/

#include <stdlib.h>

int lenght(char *str)
{
    int i = 0;

    if (str == NULL)
        return (i);
    while (str[i] != 0)
        i++;
    return (i);
}

int str_equality(char *str1, char *str2)
{
    int s1 = lenght(str1);
    if (s1 != lenght(str2))
        return (0);
    for (int i = 0; i < s1; i++) {
        if (str1[i] != str2[i])
            return (0);
    }
    return (1);
}