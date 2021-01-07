/*
** EPITECH PROJECT, 2021
** check_indentation
** File description:
** contain_str
*/

int lenght(char *str);

int conatin_str(char *str, char *container)
{
    int curr = 0;
    int size_str = lenght(str);
    if (lenght(container) > size_str)
        return (0);
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] != container[curr] && curr != 0) {
            curr = 0;
        } else {
            curr++;
        }
        if (curr == lenght(container))
            return (1);
    }
    return (0);
}