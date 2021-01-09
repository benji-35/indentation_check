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
    printf("1. -* -> you put directory after it and the script check all files\n");
    printf("2. -h -> display help of command\n");
    printf("3. -u <exentension> -> don't check files with the extension\n");
    printf("4. -o <extension> -> only check files with those extensions\n");
    printf("5. -i <indentation> -> no -i equal 4 spaces for 1 indentation\n");
    printf("6. -s -> check spaces at the end of lines\n");
    printf("7. -c <nb column> -> check number of column in line\n");
    printf("\n\nUsage :\n");
    printf(" Normal : ./indentation my_file\n");
    printf(" Many files : ./indentation my_file my_file2 my_file3\n");
    printf("\nWith options :\n");
    printf(" To check all files from directory : ./indentation -* directory/\n");
    printf("\tIn this case, binary will check all files in directory\n");
    printf(" To don't check extension : ./indentation -u .h .a .o\n");
    printf("\tIn this case, binary will note check .h .a .o extension\n");
    printf(" To check only extension : ./indentation -o .h .c\n");
    printf("\tIn this case, binary will check only .h and .c extension\n");
    printf(" To change initial indentation : ./indentation -i 3\n");
    printf("\tIn this case, indentation is set to 3 (initial indentation is 4)\n");
    printf(" To check max column in line : ./indentation -c 80\n");
    printf("\tIn this case, the program check if all lines get 80 or minus of column\n");
    printf("\nVersion : 1.1\n");
    printf("==========================\n");
}