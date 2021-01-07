/*
** EPITECH PROJECT, 2021
** indentation_check
** File description:
** display_resume
*/

#include <stdio.h>

void display_resume(int nb_inden, int nb_spaces, int verif_space)
{
    printf("\n===========================\n");
    printf("    SUMMARY INDENTATION\n");
    printf("===========================\n");
    printf("Indentation : %d\n", nb_inden);
    if (verif_space)
        printf("Spaces at end : %d\n", nb_spaces);
    printf("===========================\n");
}