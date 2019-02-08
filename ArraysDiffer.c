#include <stdio.h>

int ArrDiffer(int arr[], int arr2[], int length_arr){
    int index;
    for(int i = 0; i < length_arr; i++){
		if(arr[i] != arr2[i]){
			index = i;
			break;
		}
		else{
			index = -1;
		}
	}
     return index;
}
	





int main(){
    //Assume length of arrays are the same.
    int arr[] = {6,7,8,5,2,1,3,4,7,10};
    int arr2[] = {6,7,8,5,2,1,3,4,7,11};
    
//We want to check if arrays differ and if they do where is the first difference
    //First lets check if the lengths are the same if not no need to compare the arrays since they are different already
	int differ = ArrDiffer(arr, arr2, 10);
	if (differ != -1){
		printf("Arrays differ at index %d \n", differ);
		}
	else{
		printf("Arrays are the same \n");
		}
	return 0;
}



