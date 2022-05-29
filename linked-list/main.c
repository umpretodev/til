#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char* name;
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


//add pointer recursive
void pushNode( List* list, char* name, double price, int token) {
    if(!list->head) {
        list->head = (Node *)malloc(sizeof(Node));
        list->tail = (Node *)malloc(sizeof(Node));
        
        list->head->name = name;
        list->head->price = price;
        list->head->token = token;

        list->tail = list->head;
    }

    else {
        list->tail->next = (Node *)malloc(sizeof(Node));
        list->tail = list->tail->next;
        
        list->tail->name = name;
        list->tail->price = price;
        list->tail->token = token;
    }
}

//search pointer recursive
void searchNode(Node* pointer, int token) {
    if(pointer) {
        if(pointer->token == token) {
            printf("product: %s",pointer->name);
        }

        else searchNode(pointer->next, token);
    }
}

//show list
void __printf__( Node* pointer) {
    if(pointer) {
        printf("token: %d -> ", pointer->token);
        __printf__(pointer->next);
    }

    else printf("/\n");
}


int main() {
    List list; 

    pushNode(&list, "arroz", 5.00, 1);
    pushNode(&list, "feijão", 5.00, 2);
    pushNode(&list, "feijão", 5.00, 3);
    pushNode(&list, "feijão", 5.00, 4);
    
    __printf__(list.head);



    return 0;
}