/*
** EPITECH PROJECT, 2021
** check_indentation
** File description:
** main
*/

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void add_ext(int index, char **argv, int argc, list **l, int *size)
{
    for (int i = index + 1; i < argc; i++) {
        if (argv[i][0] != '.')
            break;
        *size = *size + 1;
        add_node(l, argv[i]);
    }
}

int main(int argc, char **argv)
{
    int indentation = 4;
    int size = 0;
    int check_end = 0;
    int nb_spaces = 0;
    int nb_inden = 0;
    int max_col = 0;
    int nb_col = 0;
    list *ext = NULL;
    if (argc < 2) {
        printf("[\e[5;31mERROR\e[0m] ./indentation <file> ...\n");
        return (84);
    }
    for (int i = 1; i < argc; i++) {
        if (str_equality(argv[i], "-i")) {
            indentation = get_number(argv[i + 1]);
            if (indentation <= 0)
                indentation = 4;
        }
        if (str_equality(argv[i], "-c")) {
            max_col = get_number(argv[i + 1]);
            if (max_col <= 0)
                max_col = 80;
        }
        if (str_equality(argv[i], "-u"))
            add_ext(i, argv, argc, &ext, &size);
        if (str_equality(argv[i], "-h")) {
            free_list(ext);
            display_help();
            return (0);
        }
        if (str_equality(argv[i], "-s"))
            check_end = 1;
    }
    display_wont(ext);
    for (int i = 1; i < argc; i++) {
        if (str_equality(argv[i], "-c"))
            i += 2;
        if (str_equality(argv[i], "-s"))
            i++;
        if (str_equality(argv[i], "-u"))
            i+= 1 + size;
        if (str_equality(argv[i], "-i"))
            i+=2;
        if (str_equality(argv[i], "-*")) {
            i++;
            check_directory(argv[i], indentation, ext, check_end, &nb_inden, &nb_spaces, max_col, &nb_col);
        } else if (can_open(argv[i])) {
            char *read = read_file(argv[i]);
            check_indentation(argv[i], read, indentation, ext, &nb_inden);
            if (check_end)
                check_end_of_line(argv[i], read, indentation, ext, &nb_spaces);
            if (max_col != 0)
                check_column(argv[i], read, &nb_col, max_col);
            free(read);
        }
    }
    free_list(ext);
    display_resume(nb_inden, nb_spaces, check_end, max_col, nb_col);
    return (0);
}