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
        intlist->tail->next = newnode;
        intlist->tail = newnode;
        
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



int main(){
    LL_t * intlist = LLcreate();
    LLappend(intlist, 23);
    LLappend(intlist, 10);
    LLappend(intlist, 3);
    PrintLinkedList(intlist);
    
}

