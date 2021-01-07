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
    printf("4. -i <indentation> -> no -i equal 4 spaces for 1 indentation\n");
    printf("\n\nUsage :\n");
    printf(" Normal : ./indentation my_file\n");
    printf(" Many files : ./indentation my_file my_file2 my_file3\n");
    printf("\nWith options :\n");
    printf(" To check all files from directory : ./indentation -* directory/\n");
    printf("\tIn this case, binary will check all files in directory\n");
    printf(" To don't check extension : ./indentation -u .h .a .o\n");
    printf("\tIn this case, binary will note check .h .a .o extension\n");
    printf(" To change initial indentation : ./indentation 3\n");
    printf("\tIn this case, indentation is set to 3 (initial indentation is 4)\n");
    printf("\nVersion : 1.0\n");
    printf("==========================\n");
}