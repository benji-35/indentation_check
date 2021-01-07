/*
** EPITECH PROJECT, 2021
** check_indentation
** File description:
** add_node
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void display_wont(list *l)
{
    while (l != NULL)
    {
        printf("extension won't check detect : %s\n", l->extension);
        l = l->next;
    }
}

void add_node(list **l, char *extension)
{
    list *new_node = malloc(sizeof(list));
    new_node->extension = duplicate_str(extension);
    new_node->next = *l;
    *l = new_node;
}