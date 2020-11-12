// Question 1

#include <stdio.h>

void main() {

	int number1, number2, sum, sub, product;
	
	printf("\nEnter the first number : ");
	scanf("%d", &number1);
	printf("Enter the second number : ");
	scanf("%d", &number2);
	
	sum = number1 + number2;
	sub = number1 - number2;
	product = number1 * number2;
	
	printf("\n%d + %d = %d", number1, number2, sum);
	printf("\n%d - %d = %d", number1, number2, sub);
	printf("\n%d * %d = %d", number1, number2, product);
	printf("\n\n");
	
	return;
	
}
