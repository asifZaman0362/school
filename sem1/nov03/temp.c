// Question 7

#include <stdio.h>

void main() {
    
    float centigrade, fahrenheit;
    
    printf("\nEnter the temperature in centigrades : ");
    scanf("%f", &centigrade);
    
    fahrenheit = (centigrade * 1.8f) + 32;
    
    printf("%f degrees centigrade = %f degrees fahrenheit\n", centigrade, fahrenheit);
    
    return;
    
}
