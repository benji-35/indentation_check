/*
** EPITECH PROJECT, 2021
** check_indentation
** File description:
** display_help
*/

#include <stdio.h>

void display_help(void)
{
    printf("==========================\n");
    printf("     HELP INDENTATION\n");
    printf("==========================\n");
    printf("\nCommand :\n");
    printf("./indentation <options> <file 1> ...\n");
    printf("Options are optionnal\n");
    printf("You can put many files after options\n");
    printf("\n\nOptions :\n");
    printf("1. -* \e[32m<directory>\e[0m -> the script check all files in directory\n");
    printf("2. -h -> display help of command\n");
    printf("3. -u \e[32m<exentension>\e[0m -> don't check files with the extension\n");
    printf("4. -o \e[32m<extension>\e[0m -> only check files with those extensions\n");
    printf("5. -i \e[32m<indentation>\e[0m -> no -i equal 4 spaces for 1 indentation\n");
    printf("6. -s -> check spaces at the end of lines\n");
    printf("7. -c \e[32m<nb column>\e[0m -> check number of column in line\n");
    printf("8. -l \e[32m<nb column>\e[0m -> check number of line in fuction\n");
    printf("9. -r -> replace tabulations by spaces (4 spaces if you don't put -i option)\n");
    printf("10. -a -> auto corrector\n");
    printf("\n\nUsage :\n");
    printf(" Normal : ./indentation my_file\n");
    printf(" Many files : ./indentation my_file my_file2 my_file3\n");
    printf("\nWith options :\n");
    printf(" To check all files from directory :\n ./indentation -* directory/\n");
    printf("\tIn this case, binary will check all files in directory\n");
    printf(" To don't check extension :\n ./indentation -u .h .a .o\n");
    printf("\tIn this case, binary will note check .h .a .o extension\n");
    printf(" To check only extension :\n ./indentation -o .h .c\n");
    printf("\tIn this case, binary will check only .h and .c extension\n");
    printf(" To change initial indentation :\n ./indentation -i 3\n");
    printf("\tIn this case, indentation is set to 3 (initial indentation is 4)\n");
    printf(" To check max column in line :\n ./indentation -c 80\n");
    printf("\tIn this case, the program check if all lines get 80 or minus of column\n");
    printf("\nVersion : 1.7\n");
    printf("==========================\n");
}