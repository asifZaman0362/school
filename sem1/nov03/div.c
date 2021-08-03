// Question 3

#include <stdio.h>

void main() {

	int num1, num2, rem;
	float quot;
	
	printf("\nEnter the first number : ");
	scanf("%d", &num1);
	printf("Enter the second number : ");
	scanf("%d", &num2);
	
	quot = (float) num1 / num2;
	rem = num1 % num2;
	
	printf("%d / %d = %f\n", num1, num2, quot);
	printf("%d %% %d = %d\n", num1, num2, rem);
	
	return;
	
}
