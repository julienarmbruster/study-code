#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    double value;
    struct node* nextnode;

}node;

node *createnode(double value);

int main(){
    node *head= NULL;
    for(int i=0; i<10; i++){
        double value = i;
        node *newnode = createnode(value);

        if (head == NULL) {
            head = newnode;
        } else {
            node *current = head;
            while ((*current).nextnode != NULL) {
                current = (*current).nextnode;
            }
            current->nextnode = newnode;
        }
    }
    node *current=head;
    while(current!=NULL){
        printf("Value: %f\n",(*current).value);
        current=(*current).nextnode;
    }
    current = head;
    while(current!=NULL){
        node *next=(*current).nextnode;
        free(current);
        current=next;
    }


}
node *createnode(double value){
    node *nextnode = malloc(sizeof(node));
    nextnode->value = value;
    nextnode->nextnode = NULL;
    return nextnode;
}

