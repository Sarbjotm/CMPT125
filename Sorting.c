#include <stdio.h>

int main(){
    int array[10] = {5,4,1,9,7,2,19, 20, 30, 1};
    int length = (sizeof(array) / sizeof(array[0]));
    int tmp;
    for (int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    for (int i = 0; i < length-1; i++){
        for(int j = i+1; j <= 9; j++){
            if (array[j] <= array[i]){
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            }
        }
    for (int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    
    
    
}
