#include <stdio.h>
#include <math.h>

int main(){
    //Calculating REAL roots of quadratic equation
    printf("Make sure your equation is in the form ax^2 + bx + c \n");
    double a, b, c, discriminant, dividing_factor, root_1, root_2; //Declaring Vars
    printf("Enter a b c: ");
    scanf("%lf %lf %lf",&a, &b, &c); //assigning values to vars
    discriminant = b*b-4*a*c; //seeing if square root is negative
    dividing_factor = 2*a; //checking to see if we are dividing by zero
    
    if (dividing_factor == 0){
        printf("Error, a can't be 0 \n");
        return 1;
    }
    if (discriminant < 0){
        printf("The discriminant is less than 0, no real roots possible \n");
        return 1;
    }
    root_1 = (-(b) + sqrt(discriminant)) / (2*a);
    root_2 = (-(b) - sqrt(discriminant)) / (2*a);
    printf("Root 1: %.4lf \n", root_1);
    printf("Root 2: %.4lf \n", root_2);
    return 0;
    
    
    
    
    
}
