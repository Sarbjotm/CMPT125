//Pyramid
#include <stdio.h>


void pyramid(int *a){
    int linenumber = *a;
    int dots = 1;
    int tmp = linenumber;
    for (int rows = 1; rows <=linenumber; rows++){
        for (int j = 1; j <=tmp; j++){
            //For each line print tmp spaces
            printf(" ");
        }
        tmp--;
        for (int i = 1; i <=dots; i++){
            //print stars
            printf("*");
        }
        printf("\n");
        //each line is +2 dots
        dots = dots +2;
        
    }
}

int main(){
    int lines;
    printf("Enter the number of lines in the pyramid/triangle you want: ");
    scanf("%d", &lines);
    printf("\n");
    pyramid(&lines);
    printf("\n");
    return 0;
    
}
