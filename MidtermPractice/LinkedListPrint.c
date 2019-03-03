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

void CustomPrint(LL_t * intlist){
    node_t * current = intlist->head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}



int main(){
    LL_t * intlist1 = LLcreate();
    LLappend(intlist1, 1);
    LLappend(intlist1, 2);
    LLappend(intlist1, 3);
    LLappend(intlist1, 4);
    LLappend(intlist1, 5);
    CustomPrint(intlist1);
    return 0;
}
