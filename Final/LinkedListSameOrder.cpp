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


int CompartSameOrder(LL_t* intlist, LL_t* intlist2){
    //Must be in the same order
    node_t* current_l1 = new node_t;
    node_t* current_l2 = new node_t;
    current_l1 = intlist->head;
    current_l2 = intlist2->head;
    while(current_l1 != NULL){
        if(current_l2 == NULL){
            return 0;
        }
        else if(current_l1->data != current_l2->data){
            return 0;
        }
        current_l1 = current_l1->next;
        current_l2 = current_l2->next;

    }
    //Now lets check if intlist2 is null if not, then they're different
    if (current_l2 != NULL){
        return 0;
    }
    return 1;

    
}

int main(){
    LL_t * intlist = LLcreate();
    LL_t * intlist2 = LLcreate();
    LLappend(intlist, 23);
    LLappend(intlist, 10);
 
    int same = CompartSameOrder(intlist, intlist2);
    printf("%d", same);
    printf("\n");
}

