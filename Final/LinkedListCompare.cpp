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


/* First code the append and print function */

void LLappend(LL_t * intlist, int value) {
    node_t* temp = new node_t;
    temp->data = value;
    temp->next = NULL;
    //Firdt we have to check if intlist head is empty
    if(intlist->head == NULL){
        intlist->head = temp;
        intlist->tail = temp;
    }
    //otherwise if its not empty, assign whatever tail is pointing to, to the temp
    intlist->tail->next = temp;
    intlist->tail = temp;
}


void PrintLinkedList(LL_t * intlist){
    node_t* current = new node_t;
    current = intlist->head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/* Write a function that compares 2 linked lists, returns 0 if different, otherwise returns 1*/
/*The order of elements doesn't matter*/
//So sum of elements 1 = sum of elements 2;
// product of elements 1 = products of elements 2;

int CompareLinkedLists(LL_t * intlist1, LL_t* intlist2){
    node_t* current_l1 = new node_t;
    node_t* current_l2 = new node_t;
    current_l1 = intlist1->head;
    current_l2 = intlist2->head;
    int sum_c1 = 0;
    int sum_c2 = 0;
    int mul_c1 = 1;
    int mul_c2 = 1;
    if (current_l1 == NULL && current_l2 == NULL){
        printf("Both lists are empty, therefore no need to run through lists \n");
        return 1;
    }
    else if((current_l1 == NULL && current_l2 != NULL) || (current_l1 != NULL && current_l2 == NULL)){
        printf("One of the list is empty while the other isn't, therefore different \n");
        return 0;
    }
    else{
        while(current_l1 != NULL){
            sum_c1 = sum_c1 + current_l1->data;
            mul_c1 = mul_c1 * current_l1->data;
            current_l1 = current_l1->next;
        }
        while(current_l2 != NULL){
            sum_c2 = sum_c2 + current_l2->data;
            mul_c2 = mul_c2 * current_l2->data;
            current_l2 = current_l2->next;
            
        }
        if(sum_c1 == sum_c2 && mul_c1 == mul_c2){
            printf("The linked list have the same elements \n");
            return 1;
        }
        else{
            printf("Not same elements \n");
            return 0;
        }
       
        
    }

}




int main(){
    LL_t * intlist = LLcreate();
    LL_t * intlist2 = LLcreate();
    int same = CompareLinkedLists(intlist, intlist2);
    printf("When both lists are empty: %d \n", same);
    LLappend(intlist, 5);
    same = CompareLinkedLists(intlist, intlist2);
    printf("When one list is empty: %d \n", same);
    LLappend(intlist, 5);
    LLappend(intlist2, 5);
    same = CompareLinkedLists(intlist, intlist2);
    printf("%d \n", same);
    return 0;
   
    
}

