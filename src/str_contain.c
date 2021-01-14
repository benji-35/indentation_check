/*
** EPITECH PROJECT, 2021
** indentation_check
** File description:
** str_contain
*/

int lenght(char *str);

int str_contain(char *str, char *contain)
{
    int curr = 0;
    int s1 = lenght(str);

    if (s1 < lenght(contain))
        return (0);
    for (int i = 0; i < s1; i++) {
        if (str[i] == contain[curr]) {
            curr++;
        } else {
            curr = 0;
        }
    }
    if (curr == lenght(contain))
        return (1);
    return (0);
}

int str_contain_char(char *str, char contain)
{
    for (int i = 0; i < lenght(str); i++) {
        if (str[i] == contain)
            return (1);
    }
    return (0);
}