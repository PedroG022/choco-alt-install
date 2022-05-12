#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylib.c"

#define MAX_STRING_SIZE 30

int main() {
    Item* item = NULL ;

    int stop = 0 ;
    do {
        char arg[MAX_STRING_SIZE] ;
        scanf(" %[^\n]s", &arg);

        if (!strcmp(arg, "##end")) {
            stop = 1 ;
            break ; 
        }

        if (strncmp(arg, "//", 2) != 0)
            item = pushNode(item, arg);
    } while (stop == 0);

    Item* aux = item ;
    int count = 0 ;
    while (aux){
        count ++ ;
        aux = aux -> dataLink ;
    }

    printf("Installing %d package(s)...\n", count);
    
    int MAX_COMMAND_SIZE = count * MAX_STRING_SIZE ;
    char command[MAX_COMMAND_SIZE] ;

    strcpy(command, "choco install ");

    aux = item ;
    while (aux){
        strcat(command, aux -> title);
        strcat(command, " ");
        aux = aux -> dataLink ;
    }

    strcat(command, "-y");
    system(command);

    return 0 ;
}