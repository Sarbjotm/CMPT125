#include <stdio.h>


int CheckIfSorted(int arr[], int len){
    for (int i = 0; i < len-1; i++){
        if(arr[i] > arr[i+1]){ //Element [i] is greater then [i+1] so its not sorted so false.
            return 1;
        }
    }
    return 0;
}


void swap(int arr[], int i, int j){
    //Sorting from [i.....j]
    int temp = arr[i]; //Swapping elements
    arr[i] = arr[j];
    arr[j] = temp;
    
}

void BubbleSort(int arr[], int len){
    //Checked if Sorted
    int sorted = CheckIfSorted(arr, len);
    if (sorted == 0){
        return;
    }
    else{
        for (int j = 0; j < len-1; j++){
            if (arr[j+1] < arr[j]){ //Comparing [i] with one to the right, if the one on the left is smaller swap
                swap(arr, j, j+1);
            }
        }
        BubbleSort(arr, len); //Call bubblesort
    }
    
}

int main(){
    int arr[] =  {2286,1434,1427,2289,2993,792,2001,1952,2717,1187,2076,1566,1631,2328,510,2307,183,1621,1806,608,517,2669,345,391,553,777,631,1286,74,897,2325,1124,2219,2773,2909,737,2207,1020,1049,100,1848,2038,2399,2856,716,2256,920,2400,1560,24};
	int len = (sizeof(arr)/sizeof(int));
    BubbleSort(arr, len);
    //Calling assert to check if asserted
    for (int i = 0; i < len; i++){
        printf("%d \n", arr[i]);
    }
    printf("\n");
	return 0;





}
