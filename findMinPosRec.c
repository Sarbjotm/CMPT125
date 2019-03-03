#include <stdio.h>

///////////////////////////////////////
            //Question 1b
///////////////////////////////////////

unsigned int FibIter(unsigned int k) {
    unsigned int n1 = 1;
    unsigned int n2 = 1;
    unsigned int n3 = 1; //if the user doesn't enter <= 2, return n3 as beign 1
    for (unsigned int i = 2; i < k; i++){
        n3 = n1+n2; //adding two previous numbers
        n1 = n2; //set n1 to n2
        n2 = n3; //set n2 to n3
    }
    return n3;
}

///////////////////////////////////////
            //Question 2a
///////////////////////////////////////

int findMinpos(int arr[], int mid, int len){
    
    static int index; //let index be a static int so it is intialized once and doesn't lose its value :)
    if (mid == len){ //Remember that in a array we can't from 0
        return index;
    }
    
    else if (arr[mid] <= arr[mid+1]){
        index = mid;                     //since arr[mid] is less than mid+1 (the next element) record the index as mid;
        //printf("%d ", index);           //for testing purposes.
        findMinpos(arr, mid+1, len);
    }
    else if(arr[mid] > arr[mid+1]){
        index = mid+1;               //since mid is greater then the next element, set index to the next element.
        //printf("%d ", index);        //For testing purposes
        findMinpos(arr, mid+1, len);
    }
   
    return index;   //this is because my complier was issuing a warning and returning memory to minpos if i didnt do this
}

///////////////////////////////////////
            //Question 2b
///////////////////////////////////////
void swapMinpos(int arr[], int mid, int len) {
    // Swaps minimum of subarray arr[mid...len-1] with arr[mid]
    //We just coded this function! Let's use it!
    int minindex = findMinpos(arr, mid, len);
    int temp = arr[minindex];
    arr[minindex] = arr[mid];
    arr[mid] = temp;
    
}

///////////////////////////////////////
            //Question 2c
///////////////////////////////////////


/* Main is used to test my program, feel free to edit the values of the array as I have calculated the length and mid*/

int main(){
    //Test code for fib:
    unsigned int k; //used unsigned int since fib is positive and increases quickly so more data values are allowed
    printf("Enter a value please to get the value corresponding to the fib sequence: ");
    scanf("%ud", &k);
    unsigned int n = FibIter(k);
    printf("%u \n \n \n \n", n);
    
    
    //Testing code for Q2:
    int arr[] = {2,3,1,4,5, 10, 3, 15, 30, 5};
    int len = (sizeof(arr)/sizeof(int)); //to find length of the array
    //printf("%d \n", len); //used for debugging: Length counts from 1
    int mid = len / 2; //Find the middle element len/2
    int minpos = findMinpos(arr, mid, len);
    for (int i = mid; i < len; i++){  //printing the array before swapping
        printf("%d ", arr[i]);
    }
    printf("\nThe smallest position as swapped with mid now \n");
    swapMinpos(arr,mid,len-1);
    for (int i = mid; i < len; i++){  //printing the array from mid to len-1 to show it swapped
        printf("%d ", arr[i]);
    }
    printf("\n");
   
    
    //Testing code for Q2c since mid is given as 14 not actual mid
    
    
    //int array[14] = {488888, 3, 5, 0, 23, 12124, 6, 7, 2, 1121, 0, 92, 5, 8};
    
    
   
    return 0;
    
    
    
}
