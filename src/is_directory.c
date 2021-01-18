/*
** EPITECH PROJECT, 2021
** indentation_check
** File description:
** is_directory
*/

#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "my.h"

int is_directory(char *path)
{
    DIR *directory = opendir(path);
    if (directory == NULL) {
        closedir(directory);
        return (0);
    }
    if (errno == ENOTDIR) {
        closedir(directory);
        return (0);
    }
    closedir(directory);
    return (1);
}