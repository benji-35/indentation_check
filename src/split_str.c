/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** split_str
*/

#include <stdlib.h>

int lenght(char *str);

int nb_split(char *str, char splitter)
{
    int size = lenght(str);
    int result = 0;

    if (str[size - 1] == splitter)
        result--;
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == splitter)
            result++;
    }
    return (result);
}

int size_before_splitter(char *str, char splitter)
{
    int i = 0;
    while (str[i] != 0) {
        if (str[i] == splitter)
            break;
        i++;
    }
    return (i);
}

void complete_str_split(char *str, int size, char *result)
{
    for (int i = 0; i < size; i++)
        result[i] = str[i];
    result[size] = 0;
}

char **split_str(char *str, char spliter)
{
    int size = lenght(str);
    int nbsplit = nb_split(str, spliter);
    char **result = malloc(sizeof(char *) * (nbsplit + 2));
    int curr = 0;
    for (int i = 0; i < size; i++) {
        int to_mal = size_before_splitter(str + i, spliter);
        result[curr] = malloc(sizeof(char) * (to_mal + 1));
        complete_str_split(str + i, to_mal, result[curr]);
        curr ++;
        i += to_mal;
    }
    result[nbsplit + 1] = malloc(sizeof(char));
    result[nbsplit + 1][0] = 0;
    return (result);
}