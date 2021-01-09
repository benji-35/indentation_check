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

void display_resume(int nb_inden, int nb_spaces, int verif_space, int verif_col, int col);
void add_node(list **l, char *extension);
void free_list(list *l);
int can_open(char *path);
char *read_file(char *path);
void check_indentation(char *path, char *read, int inden, list *l, int *nb_inden, list *ext_o);
int str_equality(char *str1, char *str2);
int lenght(char *str);
void display_help(void);
void check_directory(char *path, int inden, list *l, int check_end, int *nb_inden, int *nb_space, int max_col, int *col, list *ext_o);
int conatin_str(char *str, char *container);
int get_number(char *str);
char *duplicate_str(char *str);
void display_wont(list *l);
void check_end_of_line(char *path, char *read, int inden, list *l, int *nb_spaces, list *ext_o);
void check_column(char *path, char *read, int *nb, int col, list *l, list *ext_o);
void display_want(list *l);

#endif /* !MY_H_ */
