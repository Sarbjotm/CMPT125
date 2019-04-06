#include <stdio.h>
#include <stdlib.h>


typedef struct _node {
    int data;
    struct _node * next;
} node_t;

typedef struct {
    node_t * head;
    node_t * tail;
} LL_t;

LL_t * LLcreate() {
    LL_t * ret = new LL_t;
    ret->head = NULL;
    ret->tail = NULL;
    return ret;
}


void LLappend(LL_t * intlist, int value) {
//Theres two cases if it is empty and if it is not
    node_t* newnode = new node_t;
    newnode->data = value;
    newnode->next = NULL;
    
    if(intlist->head == NULL){
        intlist->head = newnode;
        intlist->tail = newnode;
    }
    else{
    
    node_t* current = intlist->head;
    while(current->next != NULL){
        current = current->next;
    }
        current->next = newnode;
    }
}


void PrintLinkedList(LL_t * intlist){
    node_t* current = intlist->head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    delete current;
}

int HighestValue(LL_t* intlist){
    int max = 0;
    if (intlist->head == NULL){
        printf("List is empty, returning -1337 \n");
        max = -1337;
    }
    else{
        max = intlist->head->data;
        for(node_t * curr = intlist->head; curr->next !=NULL; curr = curr->next){
            if (curr->next->data > max){
                max = curr->next->data;
            }
            
        }
    }
    return max;
    
}
int main(){
    LL_t * intlist = LLcreate();
    LLappend(intlist, 23);
    LLappend(intlist, 241);
    LLappend(intlist, 3);
    int highest = HighestValue(intlist);
    PrintLinkedList(intlist);
    printf("\n");
    printf("The highest value in the linked list is %d \n", highest);
    return 0;
   
    
}

