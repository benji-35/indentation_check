/*
** EPITECH PROJECT, 2021
** indentation_check
** File description:
** rewrite_file
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

void re_write(char * path, char *buffer)
{
    remove(path);
    int fd = open(path, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    write(fd, buffer, lenght(buffer));
    close(fd);
}