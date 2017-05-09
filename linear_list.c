#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_struct{
    int number;
    struct node_struct *previous_node;
    struct node_struct *next_node;
}node_number;

void node_exchange(node_number *a, node_number *b){
    node_number *tmp_node_exchange;
    //a = tmp;
    //a = b;
    a = tmp_node_exchange;
    a = b;
    a->previous_node = b;
    a->next_node->previous_node = b;

    //b = tmp;
    b = tmp_node_exchange;

}

void free_malloc_node(node_number *node){
    node_number *node_2 = node->next_node;
    free(node);
    if(node_2 == NULL){
        printf("End of freeing\n");
    }
    else{
        free_malloc_node(node_2);
    }
}

void printf_node(node_number *a){
    node_number *node_next = a->next_node; 
    printf("a->number:%d\n", a->number);
    if(node_next == NULL){
        printf("That is all\n");
    }
    else{
        printf_node(node_next);
    }
}

int main(){
    node_number *first_node;
    node_number *last_node;

    // Q1
    for(int i = 0;; i++){
        printf("Please input number, which will be the element of every node (if you put 0, terminated)\n");
        char buffer[5];
        fgets(buffer, 5, stdin);
        int element = atoi(buffer);
        if(element == 0){
            last_node->next_node = NULL;
            break;
        }
        else{
            if(i == 0){
                first_node = (node_number *)malloc(sizeof(node_number));

                first_node->number = element;
                first_node->previous_node = NULL;

                first_node->next_node = (node_number *)malloc(sizeof(node_number));
                first_node->next_node->previous_node = first_node;

                last_node = first_node->next_node;
                continue;
            }
            else{

                last_node->number = element;

                last_node->next_node = (node_number *)malloc(sizeof(node_number));
                last_node->next_node->previous_node = last_node;
                
                last_node = last_node->next_node;
                continue;
            }
        }
    }
    printf("Succeeded in malloc\n");

    //bubble_sort(first_node, last_node);

    printf_node(first_node);

    free_malloc_node(first_node);

    return 0;
}