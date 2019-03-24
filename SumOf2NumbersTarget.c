#include <stdio.h>

int FindAdding(int array[], int target, int len){
    int i;
    int j;
	for(int i = 0; i < len; i++){
		for(int j = i+1; j < len; j++){
			if(array[i] + array[j] == target){
                return i;

			}
			else{
                i = -1;
				j = -1;
			} 
		}
	}
    return i;
}






int main(){
	int arr[] = {9,6,5,3,4,1,2,4};
	int length = (sizeof(arr) / sizeof(arr[0]));
	int target = 8;
    int twonumbers = FindAdding(arr, target, length);
    printf("%d \n", twonumbers);
    return 0;
}
