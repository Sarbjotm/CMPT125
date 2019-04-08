#include <stdio.h>
#include <stdlib.h>

//We just want to ask the user for a value twince and replace it using pointers


int main(){
    int x;
    printf("Enter a value user: ");
    scanf("%d", &x);
    printf("\nx is equal to %d changing it to 2001 \n", x);
    int* px = &x;
    *px = 2001;
    printf("\nx is equal to %d \n", x);
    
    return 0;
}
