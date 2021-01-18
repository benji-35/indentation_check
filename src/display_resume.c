/*
** EPITECH PROJECT, 2021
** indentation_check
** File description:
** display_resume
*/

#include <stdio.h>

void display_resume(int nb_inden, int nb_spaces, int verif_space, int verif_col, int col, int nb_line, int nb_error_line)
{
    printf("\n===========================\n");
    printf("    SUMMARY INDENTATION\n");
    printf("===========================\n");
    printf("Indentation : %d\n", nb_inden);
    if (verif_space)
        printf("Spaces at end : %d\n", nb_spaces);
    if (verif_col)
        printf("Column error : %d\n", col);
    if (nb_line)
        printf("Line in function error : %d\n", nb_error_line);
    printf("\nversion : 1.9\n");
    printf("===========================\n");
}