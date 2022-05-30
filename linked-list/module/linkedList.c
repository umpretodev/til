#include "linkedList.h"

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
            printf("product: %s\n", pointer->name);
        }

        else searchNode(pointer->next, token);
    }
}

void freeList(Node *pointer) {
    if(pointer) {
        freeList(pointer->next);
        printf("free(%s)\n", pointer->name);
        free(pointer);
    }
}

//show list
void __repr__(Node *pointer) {
    if(pointer) {
        printf("token: %d -> ", pointer->token);
        __repr__(pointer->next);
    }

    else printf("/\n");
}

void __menu__() {
    printf("--------------------------------\n");
    printf("|      Gestor de Produtos:     |\n");
    printf("--------------------------------\n");
    printf("| 0 - sair do menu             |\n");
    printf("| 1 - add item                 |\n");
    printf("| 2 - Consultar item por token |\n");
    printf("--------------------------------\n");
    printf("Resp: ");
}