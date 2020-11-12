// Question 6

#include <stdio.h>

void main() {
    
    float principal, duration, rate, simpleInterest;
    
    printf("\nEnter the principal amount : ");
    scanf("%f", &principal);
    printf("Enter the duration (in years) : ");
    scanf("%f", &duration);
    printf("Enter the rate of interest : ");
    scanf("%f", &rate);
    
    simpleInterest = principal * duration * rate / 100;
    
    printf("\nSimple interest = %f\n", simpleInterest);
    
    return;
    
}
