/*
** EPITECH PROJECT, 2021
** check_indentation
** File description:
** can_open
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int can_open(char *path)
{
    if (path == NULL)
        return (0);
    struct stat st;
    char *buf;
    int r = 0;
    int fd = open(path, O_RDONLY, stat);
    if (fd == -1) {
        printf("[\e[5;31mERROR\e[0m] can't open %s\n", path);
        close(fd);
        return (0);
    }
    stat(path, &st);
    buf = malloc(sizeof(char) * (st.st_size + 1));
    r = read(fd, buf, st.st_size);
    free(buf);
    close(fd);
    if (r == -1) {
        printf("[\e[5;31mERROR\e[0m] can't read %s\n", path);
        return (0);
    }
    return (1);
}