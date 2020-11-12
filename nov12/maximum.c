#include <stdio.h>
#include <stdlib.h>

void main() {
	
	int a, b, c, max;
	
	system("clear"); // no conio on Linux
	printf("Enter a number : ");
	scanf("%d", &a);
	printf("Enter another number : ");
	scanf("%d", &b);
	printf("Enter another number : ");
	scanf("%d", &c);
	
	max = a > b ? (a > c ? a : c) : (b > c ? b : c);
	
	printf("\nThe maximum of the %d, %d, and %d is %d.\n\n", a, b, c, max);

	return;
	
}
