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

int LLcomp(LL_t* intlist1, LL_t* intlist2){
    // return 1 if same order and same elements
    //return 2 if other wise;
    int similiar;
    node_t* currentl1 = intlist1->head;
    node_t* currentl2 = intlist2->head;
    //First lets check if both !- Null
    if (currentl1 == NULL && currentl2 == NULL){
        similiar = 1;
        return similiar;
    }
    else if ( (currentl1 == NULL && currentl2 != NULL) ||(currentl1 != NULL && currentl2 == NULL) ){
        similiar = 0;
        return 0;
    }
    else{
        while(currentl1 != NULL){
            if (currentl2 == NULL){
                similiar = 0;
                break;
            }
            if(currentl1->data == currentl2->data){
                similiar = 1;
                currentl1 = currentl1->next;
                currentl2 = currentl2->next;
            }
            else{
                similiar = 0;
                break;
            }
        }
        if (currentl2 == NULL){
            similiar = 1;
        }
        
        else{
            similiar = 0;
        }
        
    }
    return similiar;
}


int main(){
    LL_t * intlist1 = LLcreate();
    LL_t * intlist2 = LLcreate();
    LLappend(intlist1, 5);
    LLappend(intlist2, 5);
    LLappend(intlist1, 6);
    LLappend(intlist2, 6);
    LLappend(intlist1, 5);
    LLappend(intlist2, 5);
    LLappend(intlist2, 5);
    int same = LLcomp(intlist1, intlist2);
    printf("%d \n", same);
    return 0;
}
