#include <stdio.h>
/*
 If 2 strings are the same word then we will return 1 otherwise return 0
 */


int same_string(char string1[], char string2[]){
    int i = 0;
    int result = 1;
    while (string1[i] != '\0'){
        if(string1[i] == string2[i]){
            i = i+1;
        }
        else{
            result = 0;
            break;
        }
    //This won't check lengths so lets check if string1 has extra characters or not.
    }
    if(string1[i] == '\0' && string2[i] != '\0'){
        return result;
    }
    return result;
    
}


int main(){
    char string1[] = "Hello";
    char string2[] = "Hell";
    int similiar = same_string(string1, string2);
    if (similiar == 1){
        printf("The strings are the same \n");
    }
    else{
        printf("Not the same \n");
    }
    
    
    return 0;
}
