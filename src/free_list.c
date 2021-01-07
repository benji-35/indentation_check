/*
** EPITECH PROJECT, 2021
** check_indentation
** File description:
** free_list
*/

#include <stdlib.h>
#include "my.h"

void free_list(list *l)
{
    if (l == NULL)
        return;
    list *next = l->next;
    while (l != NULL) {
        free(l->extension);
        free(l);
        l = next;
        if (next != NULL)
            next = next->next;
    }
}