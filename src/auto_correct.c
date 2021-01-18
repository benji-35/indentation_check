/*
** EPITECH PROJECT, 2021
** indentation_check
** File description:
** auto_correct
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

int good_extension(char *path, list *l);
int divisible_by(int nb, int div);

int to_add_indentation(int nb, int indentation)
{
    if (divisible_by(nb, indentation))
        return (0);
    float calc = (float)nb / (float)indentation;
    while (calc > 1.0f)
        calc = calc - 1.0f;
    float r = (1.0f - calc) * indentation;
    if (calc <= 0.5f) {
        r = calc * indentation;
        r = -r;
        return ((int)r);
    }
    if (r < 0)
        r = r * -1;
    return (r);
}

void auto_correct_spaces(char **line)
{
    char *l = *line;
    int size = lenght(l);
    int nb = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (l[i] != ' ' && l[i] != '\t')
            break;
        nb++;
    }
    if (nb == 0)
        return;
    (*line)[size - nb] = 0;
}

void auto_correct_inden(char **line, int indentation)
{
    char *l = *line;
    int size = lenght(l);
    int nb = 0;
    int to_add = 0;
    char *tampon = NULL;
    for (int i = 0; i < size; i++) {
        if (l[i] != ' ' && l[i] != '\t')
            break;
        if (l[i] == '\t')
            nb += indentation;
        if (l[i] == ' ')
            nb++;
    }
    to_add = to_add_indentation(nb, indentation);
    if (to_add == 0)
        return;
    if (to_add < 0) {
        tampon = move_str_left(l, (to_add * -1));
        free(*line);
        (*line) = tampon;
    } else {
        char *spaces = malloc(sizeof(char) * (to_add + 1));
        for (int i = 0; i < to_add; i++)
            spaces[i] = ' ';
        spaces[to_add] = 0;
        tampon = concat_str(spaces, l);
        free(spaces);
        free(*line);
        (*line) = tampon;
    }
}

void auto_correct(char *read, char *path, int indentation, list *l, list *ext_o)
{
    char back = '\n';
    char *back_str = "\n";
    if (read == NULL)
        return;
    if (good_extension(path, l) == 0)
        return;
    if (ext_o != NULL && good_extension(path, ext_o))
        return;
    char **lines = split_str(read, '\n');
    if (lines == NULL)
        return;
    char *tampon = NULL;
    char *result = malloc(sizeof(char));
    result[0] = 0;
    for (int i = 0; lines[i][0] != 0; i++) {
        if (lines[i] != NULL) {
            auto_correct_spaces(&(lines[i]));
            auto_correct_inden(&(lines[i]), indentation);
            tampon = concat_str(result, lines[i]);
            free(result);
            result = tampon;
            tampon = concat_str(result, back_str);
            free(result);
            result = tampon;
        }
    }
    if (read[lenght(read) - 1] != '\n')
        result[lenght(result) - 1] = 0;
    re_write(path, result);
    free_split(lines);
    free(result);
}