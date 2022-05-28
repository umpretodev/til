#include <stdio.h>

typedef struct node {
    char name[30];
    double price;
    int token; 

    //pointer to next
    struct node* next;
} Node;


typedef struct list {
    //pointers
    Node* head; 
    Node* tail;
} List;


void pushNode() {};

void searchNode( int token) {};

void __list__( List* list) {};

int main() {


    return 0;
}