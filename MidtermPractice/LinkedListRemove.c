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
    LL_t * ret = malloc(sizeof(LL_t));
    ret->head = NULL;
    ret->tail = NULL;
    return ret;
}

void LLappend(LL_t * intlist, int value) {
    node_t * newNode = malloc(sizeof(node_t));
    
    newNode->data = value;
    newNode->next = NULL;
    
    if (intlist->head == NULL) {
        intlist->head = newNode;
        intlist->tail = newNode;
    } else {
        intlist->tail->next = newNode;
        intlist->tail = newNode;
    }
}


void LLprint(LL_t * list) {
    if (list) {
        node_t * sequence = list->head;
        while(sequence) {
            if (sequence != list->head) { putchar(' '); }
            printf("%d", sequence->data);
            sequence = sequence->next;
        }
    }
    putchar('\n');
}

//Given a sorted linked list remove duplicates
// 1 2 3 4 5 5
// 1 2 3 4 5 it'll remove the second 5.
void LLRemoveDuplicates(LL_t * intlist){
    node_t * current = intlist->head;
    while(current != NULL){
        if((current->next != NULL &&current->data == current->next->data)){
            node_t * temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        else{
            current = current->next;
        }
    }
    
}

int main(){
    LL_t * intlist1 = LLcreate();
    LLappend(intlist1, 1);
    LLappend(intlist1, 1);
    LLappend(intlist1, 2);
    LLappend(intlist1, 3);
    LLappend(intlist1, 5);
    LLappend(intlist1, 5);
    LLappend(intlist1, 7);
    LLprint(intlist1);
    LLRemoveDuplicates(intlist1);
    LLprint(intlist1);
    return 0;
}
