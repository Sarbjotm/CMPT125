#include <stdio.h>


//Return 1 if target found, other wise return 0;




int BinarySearch(int arr[], int len, int target){
    static int j;
    if(len == 1){
        if(arr[0] == target){
            j = 1;
        }
        else{
            j = 0;
        }
    }
    else{
        int mid = len/2;
        if (target >= arr[mid]){
            //this means arr[mid] is greater then target so check first half
            BinarySearch(arr+mid,len-mid+1,target);
        }
        else if(target < arr[mid]){
            BinarySearch(arr,mid,target);
        }
    }
    return j;
}


int main(){
    int array[] = {15,20,25,30}; //in an binary search the array is sorted
    int is_in = BinarySearch(array, 4, 13);
    printf("%d \n", is_in);
    return 0;
    
    
    
    
}


//n! is basically
