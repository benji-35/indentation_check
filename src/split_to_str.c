/*
** EPITECH PROJECT, 2021
** mystrlib
** File description:
** split_to_str
*/

#include <stdlib.h>

int lenght(char *str);
char *concat_str(char *str1, char *str2);
char *copy_str(char *str);

char *split_to_char(char **split, char *separator)
{
    int curr = 0;
    char *result = copy_str("\0");
    char *tampon = NULL;
    char *good_sep = NULL;

    if (separator != NULL) {
        good_sep = malloc(sizeof(char) * 2);
        good_sep[0] = *separator;
        good_sep[1] = 0;
    }
    for (int i = 0; split[i][0] != 0; i++) {
        tampon = concat_str(result, split[i]);
        free(result);
        result = tampon;
        if (separator != NULL && split[i + 1][0] != 0) {
            tampon = concat_str(result, good_sep);
            free(result);
            result = tampon;
        }
    }
    return (result);
}