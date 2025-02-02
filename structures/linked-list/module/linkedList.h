#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char *name;
    double price;
    int token;

    struct node *next;
} Node;

typedef struct list {
    Node *head;
    Node *tail;
} List;


//add node
void pushNode( List* list, char* name, double price, int token);

//Search node
void seachNode(Node* pointer, int token);

//clear memory
void freeList(Node* pointer);

//represent list 
void __repr__(Node* pointer);


//show menu
void __menu__();