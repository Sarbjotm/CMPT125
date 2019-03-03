#include <stdio.h>
#include <stdlib.h>


int max(const int arr[], int n){
    int index = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[index]){
            index = i;
        }
    }
    return index;
}

int main(){
    const int array[] = {2286,1434,1427,2289,2993,792,2001,1952,2717,1187,2076,1566,1631,2328,510,2307,183,1621,1806,608,517,2669,345,391,553,777,631,1286,74,897,2325,1124,2219,2773,2909,737,2207,1020,1049,100,1848,2038,2399,2856,716,2256,920,2400,1560,24};
    int max_value = max(array, 50);
    printf("%d is max value \n", array[max_value]);
}
