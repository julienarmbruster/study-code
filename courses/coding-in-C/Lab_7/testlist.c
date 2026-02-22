#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int value;
    struct node *next;
} node;

typedef struct {
    node *head;
} list;

void add_node(list *l, int value){
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        return;
    }

    new_node->value = value;
    new_node->next = NULL;

    if (l->head == NULL) {
        l->head = new_node;
        return;
    }

    node *current = l->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

int main(){
    list l = { NULL };
    add_node(&l, 1);
    add_node(&l, 2);
    add_node(&l, 3);

    node *current = l.head;
    while(current!=NULL){
        printf("%d\n",current->value);
        current=current->next;
    }
        

}