// Question 2

#include <stdio.h>

void main() {

	float number1, number2, sum, sub, product;
	
	printf("\nEnter the first number : ");
	scanf("%f", &number1);
	printf("Enter the second number : ");
	scanf("%f", &number2);
	
	sum = number1 + number2;
	sub = number1 - number2;
	product = number1 * number2;
	
	printf("\n%f + %f = %f", number1, number2, sum);
	printf("\n%f - %f = %f", number1, number2, sub);
	printf("\n%f * %f = %f", number1, number2, product);
	printf("\n\n");
	
	return;
	
}
