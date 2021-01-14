/*
** EPITECH PROJECT, 2021
** indentation_check
** File description:
** replace_char_in_str
*/

#include <stdlib.h>
int lenght(char *str);

int nb_char_in_str(char *str, char c)
{
    int r = 0;

    for (int i = 0; i < lenght(str); i++) {
        if (str[i] == c)
            r++;
    }
    return (r);
}

char *replace_char_in_str(char *str, char replace, char new_replace, int nb_replace)
{
    int size = lenght(str);
    int nb = nb_char_in_str(str, replace);
    int new_size = (size - nb) + (nb * nb_replace);
    char *new_char = malloc(sizeof(char) * (new_size + 1));
    int curr = 0;

    for (int i = 0; i < size; i++) {
        if (str[i] == replace) {
            for (int a = 0; a < nb_replace; a++)
                new_char[curr + a] = new_replace;
            curr+=nb_replace;
        } else {
            new_char[curr] = str[i];
            curr++;
        }
    }
    new_char[new_size] = 0;
    return (new_char);
}