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

int isSorted(LL_t* intlist){
    node_t* current = intlist->head;
    while (current->next != NULL){
        if(current->data > current->next->data){
            return 0; //Not sorted
        }
        current = current->next;
    }
    return 1;
}



void sortlinkedlist(LL_t* intlist){
    node_t* current = intlist->head;
    //But we don't want to run the function if the linked list is sorted or is NULL
    if(current == NULL){
        return; //Return 1 since an empty list is technically sorted
    }
    while(current->next != NULL){
        if(current->data > current->next->data){
            int temp = current->data;
            current->data = current->next->data;
            current->next->data = temp;
            current = current->next;
        }
    }
//    int sorted = isSorted(intlist);
//    if(sorted != 1){
//        sortlinkedlist(intlist);
//    }
    printf("trafaff \n");
    
    
}

int main(){
    LL_t * intlist = LLcreate();
    LLappend(intlist, 23);
    LLappend(intlist, 10);
    LLappend(intlist, 3);
    PrintLinkedList(intlist);
    printf("\n");
    sortlinkedlist(intlist);
    sortlinkedlist(intlist);
    sortlinkedlist(intlist);
    PrintLinkedList(intlist);
    
}

