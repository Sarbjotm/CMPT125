#include <stdio.h>

void strcopy2(char *s1, char *s2) {
    //Commented code was used to test my function
    for (int i = 0; i < 10; i++){
        s1[i] = s2[i];
    }
    /*printf("S2: ");
    for (int i = 0; i < 10; i++){
        printf("%c", s2[i]);
    }
    printf("\n");
     printf("S1: ");
    for (int i = 0; i < 10; i++){
        printf("%c", s1[i]);
    }
    printf("\n");
    */
    
    
    
}
int main () {
    char s2[10] = "copy this";
    char s1[10];
    strcopy2(s1, s2);
}
