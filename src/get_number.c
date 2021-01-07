/*
** EPITECH PROJECT, 2021
** check_indentation
** File description:
** get_number
*/

int is_number(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int get_number(char *str)
{
    int result = 0;

    for (int i = 0; is_number(str[i]); i++)
        result = (result * 10) + str[i] - 48;
    return (result);
}