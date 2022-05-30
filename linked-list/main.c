#include "module/linkedList.c"

int main() {
    int option;
    
    //node aux
    char* name;
    double price;
    int token;

    List list; 

    do {
        __menu__();

        scanf("%d", &option);
        printf("\n");


        switch(option) {
            
            case 0:
                printf("\n");
                freeList(list.head);
                break;

            case 1: 
                printf("name: ");
                scanf("%s", &name);

                printf("price: ");
                scanf("%lf", &price);

                printf("token: ");
                scanf("%d", &token);

                pushNode(&list, name, price, token);
                break;

            case 2: 
                printf("token: ");
                scanf("%d", &token);

                searchNode(list.head, token);
                break;
        }

        if(option == 0) {
            printf("\nlist: -> /\n");
        }

        else {
            printf("\nlist: ");
            __repr__(list.head);
            printf("\n");
        }  

    } while (option);


        return 0;
}