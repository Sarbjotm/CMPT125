//Pyramid
#include <stdio.h>



int main(){
    printf("Welcome user, please select a beverage by entering its number \n");
    printf("Your choices are as follows \n");
    printf("\t0:Coke\n");
    printf("\t1:Mug Root Beer\n");
    printf("\t2:Dr.Pepper\n");
    printf("\t3:Sprite\n");
    printf("\t4:Pepsi\n");
    int tries = 3;
    int number;
    
    while (tries != 0){
        printf("\n\nPlease make a selection: ");
        scanf("%d", &number);
        if(number == 0){
            printf("Selected Drink: Coke \n");
            printf("Calorie Count: 140 Calories \n");
            break;
        }
        else if(number == 1){
            printf("Selected Drink: Mug Root Beer \n");
            printf("Calorie Count: 160 Calories \n");
            break;
        }
        
        else if(number == 2){
            printf("Selected Drink: Dr. Pepper \n");
            printf("Calorie Count: 150 Calories \n");
            break;
        }
        else if(number == 3){
            printf("Selected Drink: Sprite \n");
            printf("Calorie Count: 39 Calories \n");
            break;
        }
        else if(number == 4){
            printf("Selected Drink: Pepsi \n");
            printf("Calorie Count: 150 Calories \n");
            break;
        }
        else{
            tries--;
            if (tries == 0){
                printf("Invalid \n");
                printf("%d tries left \n", tries);
            }
            else{
                printf("Invalid, try again \n");
                printf("You have %d tries left", tries);
            }
        }
        
    }
    return 0;
    
}
