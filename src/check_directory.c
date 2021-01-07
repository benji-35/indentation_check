/*
** EPITECH PROJECT, 2021
** check_indentation
** File description:
** check_directory
*/

#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

char *create_good_path(char *path, struct dirent *entry)
{
    int check = 0;
    int tot = 0;
    int size_path = lenght(path);
    int size_name = lenght(entry->d_name);
    char *new_path = NULL;
    if (entry->d_name[0] == '.')
        return NULL;
    if (path[size_path - 1] != '/') {
        check = 1;
    }
    tot = check + size_path + size_name;
    new_path = malloc(sizeof(char) * (tot + 1));
    for (int i = 0; i < size_path; i++) {
        new_path[i] = path[i];
    }
    if (check)
        new_path[size_path] = '/';
    for (int i = 0; i < size_name; i++) {
        new_path[i + size_path + check] = entry->d_name[i];
    }
    new_path[tot] = 0;
    return (new_path);
}

void check_directory(char *path, int inden, list *l, int check_end, int *nb_inden, int *nb_space)
{
    struct dirent *entry;
    struct stat st;
    struct stat *_st;
    char *new_path = NULL;
    char *read = NULL;
    DIR *dir;
    time_t time;
    stat(path, &st);
    dir = opendir(path);
    entry = readdir(dir);
    while (entry != NULL) {
        new_path = create_good_path(path, entry);
        if (new_path != NULL) {
            _st = malloc(sizeof(struct stat));
            stat(new_path, _st);
            if (S_ISDIR(_st->st_mode)) {
                check_directory(new_path, inden, l, check_end, nb_inden, nb_space);
            } else if (can_open(new_path)) {
                read = read_file(new_path);
                check_indentation(new_path, read, inden, l, nb_inden);
                if (check_end)
                    check_end_of_line(path, read, inden, l, nb_space);
                free(read);
            }
            free(_st);
            free(new_path);
        }
        entry = readdir(dir);
    }
    closedir(dir);
}