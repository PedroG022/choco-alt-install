#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_STR_SIZE 50

typedef struct Item {
    char title[MAX_STR_SIZE] ;
    struct Item* dataLink ;
} Item ;

//------------------------------------------------
// # Node Utility Methods
//------------------------------------------------

//Pushes a node to the top and then returns it
Item* pushNode(Item* head, char title[]) {
    Item* newNode = (Item*) malloc(sizeof(Item));

    strcpy(newNode -> title, title);
    newNode -> dataLink = head ;

    head = newNode ;
}

//Returns the bottom node
Item* getLastNode(Item* node) {
    Item* aux = node ;

    while (aux -> dataLink) {
        aux = aux -> dataLink ;
    }

    return aux ;
}

//Inserts a node at the last position
Item* insertNodeAtEnd(Item* head, char title[]) {
    if (!head)
        return pushNode(head, title);

    Item* lastNode = getLastNode(head);
    Item* newNode = malloc(sizeof(Item));

    strcpy(newNode -> title, title);
    newNode -> dataLink = NULL ;

    lastNode -> dataLink = newNode ;

    return head ;
}

//Returns a node's index given its title
int nodeIndexByTitle(Item* head, char title[]) {
    Item* aux = head ; 
    int counter = 0 ;
    int result = -1 ;

    while (aux) {
        counter ++ ;

        if (!strcmp(aux -> title, title)) {
            result = counter ;
            break ;
        }
        aux = aux -> dataLink ;
    }

    return result ;
}

//Returns a node given an index
Item* getNodeByIndex(Item* head, int index) {
    Item* aux = head ; 
    Item* result = malloc(sizeof(Item)) ;

    int counter = 0 ;

    while (aux) {
        counter ++ ;

        if (counter == index) {
            result = aux ;
            break ;
        }
        aux = aux -> dataLink ;
    }

    return result ;
}

//Removes a node given its link
Item* removeNode(Item* head, char title[]) {
    Item* aux = head ; 
    
    //For the first item
    if (!strcmp(head -> title, title)) {
        Item* second = head -> dataLink ;
        free(head);
        return(second);
    }

    while (aux && aux -> dataLink) {
        int nextNodeIndex = nodeIndexByTitle(head, aux -> title) + 1 ;
        Item* next = (Item*) getNodeByIndex(head, nextNodeIndex);
        
        if (!strcmp(next -> title, title)) {
            aux -> dataLink = next -> dataLink ;
            free(next);
        }

        aux = aux -> dataLink ;
    }

    return head ;
}


//------------------------------------------------
// # Main Methods
//------------------------------------------------

//Shows the chain
void showNodeChain(Item* head) {
    Item* aux = head ;

    while (aux) {
        printf("Title: %s\n", aux -> title);
        aux = aux -> dataLink ;
    }
}