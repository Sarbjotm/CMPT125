#include <stdio.h>
#include <assert.h>
#include <stdbool.h> //So we can use boolean

bool CheckIfSorted(int arr[], int length){
    /*If for any i+1 the value before is greater then
     then we know it is not sorted so we can't do binary search
     therefore return false*/
    for (int i = 0; i < length; i++){
        if (arr[i] > arr[i+1]){ // > because if we had 5 6 6 this would fail
                                //when in reality it is true.
            return false; //If at least one is out of place return false
        }
    }
    return true; //Return true if array is ordered
}


int BinarySearch(int arr[], int len, int target) {
    assert(CheckIfSorted(arr, len));
    //...
    return 0;
}


int main(){
    //Testing our program
    int arr2[] = {1,2,3,5,4,6,7,8};
    BinarySearch(arr2, 8, 4);
    return 0;
    
}
