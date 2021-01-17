/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** concat_str
*/

#include <stdlib.h>

int lenght(char *str);

char *concat_str(char *str1, char *str2)
{
    int s1 = lenght(str1);
    int s2 = lenght(str2);
    char *result = malloc(sizeof(char) * (s1 + s2 + 1));

    for (int i = 0; i < s1; i++)
        result[i] = str1[i];
    for (int i = s1; i < s1 + s2; i++)
        result[i] = str2[i - s1];
    result[s1 + s2] = 0;
    return (result);
}