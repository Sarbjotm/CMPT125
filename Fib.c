#include <stdio.h>


int FibIter(int k) {
    unsigned int n1 = 1;
    unsigned int n2 = 1;
    unsigned int n3 = 1; //if the user doesn't enter <= 2, return n3 as beign 1
    for (int i = 2; i < k; i++){
        n3 = n1+n2; //adding two previous numbers
        n1 = n2; //set n1 to n2
        n2 = n3; //set n2 to n3
        printf("%u ", n3);
    }
    return n3;
}



int main(){
    
    int k;
    scanf("%d", &k);
    printf("\n");
    FibIter(k);
    printf("\n");
    
    
}
