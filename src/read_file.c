/*
** EPITECH PROJECT, 2021
** check_indentation
** File description:
** read_file
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

char *read_file(char *path)
{
    struct stat st;
    char *buf;
    int r = 0;
    int fd = open(path, O_RDONLY, stat);
    stat(path, &st);
    buf = malloc(sizeof(char) * (st.st_size + 1));
    r = read(fd, buf, st.st_size);
    close(fd);
    buf[st.st_size] = 0;
    return (buf);
}