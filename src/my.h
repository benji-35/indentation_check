/*
** EPITECH PROJECT, 2021
** check_indentation
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

typedef struct list_s
{
    char *extension;
    struct list_s *next;
} list;

void add_node(list **l, char *extension);
void free_list(list *l);
int can_open(char *path);
char *read_file(char *path);
void check_indentation(char *path, char *read, int inden, list *l);
int str_equality(char *str1, char *str2);
int lenght(char *str);
void display_help(void);
void check_directory(char *path, int inden, list *l);
int conatin_str(char *str, char *container);
int get_number(char *str);
char *duplicate_str(char *str);
void display_wont(list *l);

#endif /* !MY_H_ */
