#include <stdio.h>
#include <stdlib.h>

// Node definition for doubly linked list
typedef struct _dllnode  {
    int data;
    struct _dllnode * next;
    struct _dllnode * prev;
} DLLnode_t;

// Definition of doubly linked list
typedef struct {
    DLLnode_t * head;
} DLL_t;

// Creates a doubly linked list
DLL_t * DLLCreate() {
    DLL_t * ret = malloc(sizeof(DLL_t));
    ret->head = NULL;
    return ret;
}

// Appends a DLLnode_t containing the value x into a DLL_t
void DLLAppend(DLL_t * intlist, int x) {
    // Create a DLLnode_t
    DLLnode_t * newNode = malloc(sizeof(DLLnode_t));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    // Point head to new node if list is empty
    if(intlist->head == NULL) {
        intlist->head = newNode;
        return;
    }
    
    DLLnode_t * temp =intlist->head;
    while(temp->next != NULL) {
        temp = temp->next; // Go To last Node
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}

// Prints the elements of a doubly linked list
void DLLPrint(DLL_t * intlist) {
    DLLnode_t * temp = intlist->head;
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Question 2
void DLLReverse(DLL_t * intlist){
    DLLnode_t* current = intlist->head;
    //    DLLnode_t* previous = NULL;
    //    DLLnode_t* nextnode = NULL;
    DLLnode_t* temp;
    if (current == NULL){
        //reversing empty list is just empty list
    }
    else{
        while ( current != NULL ){
            //printf("%d \n", current->data); will print first data
            //Link list points to previous element and next over
            //So lets swap the next node and prev node
            temp = current->prev; //temp is node before current (temp val)
            current->prev = current->next; //prev node be next
            current->next = temp; //next node be prev
            current = current->prev; //go back to prev node to reverse cause we changed next already
        }
        if (temp != NULL){
            intlist->head = temp->prev; //change head unless temp is NULL
        }
    }
}

void DLLRemove(DLL_t * intlist, int ind){
    //remove index node
    //linked lists start at 0
    DLLnode_t* current = intlist->head;
    for (int i = 0; (i < ind && current != NULL); i++) { //make sure current != NULL
        current = current->next; //get node corresponding to index
    }
    if (current != NULL){ // if we are not out of bounds
        //Now we have three conditions if node to be deleted is head
        if (current == intlist->head){
            intlist->head = current->next;
        }
        //make sure the next node is not NULL
        if (current -> next != NULL){ //if next is npot NULL Assign current's next previous node to current prev node
            // A->B->C will become A->C
            current->next->prev = current->prev;
        }
        //Make sure previous is not NULL
        if (current->prev != NULL){
            //if next is npot NULL Assign current's next previous node to current prev node
            // A->B->C->D will become B->D
            current->prev->next = current->next;
        }
        //free current
        free(current);
        
    }
}

int main(){
    //Creating and append doubly linked list
    DLL_t * intlist = DLLCreate();
    DLLAppend(intlist, 6);
    DLLAppend(intlist, 7);
    DLLAppend(intlist, 8);
    DLLAppend(intlist, 9);
    DLLAppend(intlist, 10);
    printf("Printing before Reversing: ");
    DLLPrint(intlist);
    printf("\n");
    DLLReverse(intlist);
    printf("Printing after Reversing: ");
    DLLPrint(intlist);
    //Asking user what index they want
    int indexremoval;
    printf("\n \n \nWhat index do you want to remove? ");
    scanf("%d", &indexremoval);
    printf("\n");
    printf("Printing before removal of index %d:  ", indexremoval);
    DLLPrint(intlist);
    DLLRemove(intlist, indexremoval);
    printf("\nPrinting after removal of index %d:  ", indexremoval);
    DLLPrint(intlist);
    printf("\n");
    return 0;
}


