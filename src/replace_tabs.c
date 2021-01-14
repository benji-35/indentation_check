/*
** EPITECH PROJECT, 2021
** indentation_check
** File description:
** replace_tabs
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int lenght(char *str);
int str_contain_char(char *str, char contain);
char *replace_char_in_str(char *str, char replace, char new_replace, int nb_replace);
int good_extension(char *path, list *l);

void replace_tab(char *read, int nb_spaces, char *path, list *l, list *ext_o)
{
    if (read == NULL)
        return;
    if (good_extension(path, l) == 0)
        return;
    if (ext_o != NULL && good_extension(path, ext_o))
        return;
    if (str_contain_char(read, '\t') == 0)
        return;
    char *result = replace_char_in_str(read, '\t', ' ', nb_spaces);
    int fd = open(path, O_WRONLY, stat);
    write(fd, result, lenght(result));
    free(result);
    close(fd);
}