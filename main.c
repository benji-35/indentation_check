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
    int auto_c = 0;
    int replace = 0;
    int indentation = 4;
    int size = 0;
    int size_o = 0;
    int check_end = 0;
    int nb_spaces = 0;
    int nb_inden = 0;
    int max_col = 0;
    int nb_col = 0;
    int error_line = 0;
    int nb_line = 0;
    list *ext = NULL;
    list *ext_o = NULL;
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
        if (str_equality(argv[i], "-o"))
            add_ext(i, argv, argc, &ext_o, &size_o);
        if (str_equality(argv[i], "-u"))
            add_ext(i, argv, argc, &ext, &size);
        if (str_equality(argv[i], "-h")) {
            free_list(ext);
            display_help();
            return (0);
        }
        if (str_equality(argv[i], "-s"))
            check_end = 1;
        if (str_equality(argv[i], "-r"))
            replace = 1;
        if (str_equality(argv[i], "-a")) {
            replace = 1;
            auto_c = 1;
        }
        if (str_equality(argv[i], "-l"))
            nb_line = get_number(argv[i + 1]);
    }
    if (nb_line <= 0)
        nb_line = 20;
    display_wont(ext);
    display_want(ext_o);
    for (int i = 1; i < argc; i++) {
        if (str_equality(argv[i], "-o")) {
            i += size_o;
        } else if (str_equality(argv[i], "-r")) {
            //wait
        } else if (str_equality(argv[i], "-c")) {
            i ++;
        } else if (str_equality(argv[i], "-s")) {
            //wait
        } else if (str_equality(argv[i], "-a")) {
            //wait
        } else if (str_equality(argv[i], "-u")) {
            i += size;
        } else if (str_equality(argv[i], "-i") || str_equality(argv[i], "-l")) {
            i++;
        } else if (str_equality(argv[i], "-*")) {
            i++;
            check_directory(argv[i], indentation, ext, check_end, &nb_inden, &nb_spaces, max_col, &nb_col, ext_o, replace, auto_c, nb_line, &error_line);
        } else if (can_open(argv[i])) {
            char *read = read_file(argv[i]);
            check_indentation(argv[i], read, indentation, ext, &nb_inden, ext_o);
            if (check_end)
                check_end_of_line(argv[i], read, indentation, ext, &nb_spaces, ext_o);
            if (max_col != 0)
                check_column(argv[i], read, &nb_col, max_col, ext, ext_o);
            if (replace)
                replace_tab(read, indentation, argv[i], ext, ext_o);
            if (auto_c)
                auto_correct(read, argv[i], indentation, ext, ext_o);
            if (nb_line)
                check_line(read, argv[i], ext, ext_o, nb_line, &error_line);
            free(read);
        }
    }
    free_list(ext);
    free_list(ext_o);
    if (auto_c)
        printf("\nAuto correction done");
    display_resume(nb_inden, nb_spaces, check_end, max_col, nb_col, nb_line, error_line);
    return (0);
}