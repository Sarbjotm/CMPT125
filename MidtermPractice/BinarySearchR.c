#include <stdio.h>


int BinarySearch(int arr[], int len, int target){
//    for (int i = 0; i < len; i++){
//        printf("%d ", arr[i]);
//    }                             //To bring new arrays
//    printf("\n");
    static int j = 0;
    if (len == 1){
        if (arr[0] == target){
            j = 1;
        }
        else{
            j = 0;
        }
    }
    else{
        int mid = len / 2;
        if (target < arr[mid]){
            BinarySearch(arr, mid, target);
        }
        else if (target > arr[mid]){
            BinarySearch(arr+mid,len-mid+1, target);
        }
        
    }
    return j;
    
}



int main(){
    int array[] = {15,20,25,30}; //in an binary search the array is sorted
    int is_in = BinarySearch(array, 4, 15);
    printf("%d \n", is_in);
    return 0;
    
    
    
    
}
