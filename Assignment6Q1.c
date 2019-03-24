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


//Max Function
int LLMax(LL_t * intlist){
    int max; //set an index for max
    node_t* current = intlist->head; //set current to head
    if(current == NULL){
        printf("Empty List! \n"); //if no elements in list, print empty list and have max = -5 as an error code
        max = -5
    }
    else{
        max = current->data; //set max to current data
        while(current != NULL){ //while current isn't null
            int tmp = current->data; //temp pointer to get data of current
            if (max <= tmp ){ //if max is kess than tmp's data set max to tmp
                max = tmp;
            }
            current = current->next;
        }
    }
    // printf("Max is %d \n", max); //for testing
    return max;
}

void LLDelete(LL_t * intlist, int target){
    //If we have the array of 2 3 4 5 6 and we want to remove 4 lets overwrite
    //the elements with 2 3 5 5 6 then
    // 2 3 5 6 and recheck positions
    // 2 3 6
    int s = 0;
    node_t* current = intlist->head; //set current to head node
    node_t* previous = current; //set previous to current
    if (current == NULL){
        printf("Target not found! \n");
    }
    else{
        while(current != NULL){
            if(current->data == target && current->next != NULL){
                s = 1;
                node_t* temp = current->next; //Assign node to next element over
                current->data = current->next->data; //Assign our current data element to next elements
                current->next = temp->next; //Set next node to temp nodes next
                free(temp); //free next
                
            }
            else if(current->data == target && current->next == NULL){
                //int value = current->data;
                intlist->tail = previous; //set tail to previous
                previous->next = NULL; //no element further
                current = NULL; //current = NULL to exit while loop
                
                
            }
            else{
                previous = current; //keep track of previous  element
                current = current->next; //only increase if target is not in our next.
            }
            
        }
        
    }
    if(s != 1){
        printf("Target not found! ");
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


int main(){
    LL_t * intlist = LLcreate();
    LLappend(intlist, 23);
    LLappend(intlist, 10);
    LLappend(intlist, 5);
    LLappend(intlist, 6);
    LLappend(intlist, 10);
    LLappend(intlist, 11);
    LLappend(intlist, 5);
    LLappend(intlist, 5);
    LLappend(intlist, 7);
    LLappend(intlist, 5);
    LLappend(intlist, 5);
    LLprint(intlist); //Printing before deleting #5
    int llistmax = LLMax(intlist);
    printf("Max value is the list is %d \n", llistmax);
    LLDelete(intlist,5);
    LLprint(intlist); //Printing after deleting #5
    
    
    return 0;
}
