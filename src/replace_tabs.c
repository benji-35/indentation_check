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

int lenght(char *str);
int str_contain_char(char *str, char contain);
char *replace_char_in_str(char *str, char replace, char new_replace, int nb_replace);

void replace_tab(char *read, int nb_spaces, char *path)
{
    if (str_contain_char(read, '\t') == 0)
        return;
    char *result = replace_char_in_str(read, '\t', ' ', nb_spaces);
    int fd = open(path, O_WRONLY, stat);
    write(fd, result, lenght(result));
    free(result);
    close(fd);
}