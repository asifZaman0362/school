#include <stdio.h>
#include <stdlib.h>

void main() {
	
	int a, b, c, min;
	
	system("clear"); // no conio on Linux
	printf("Enter a number : ");
	scanf("%d", &a);
	printf("Enter another number : ");
	scanf("%d", &b);
	printf("Enter another number : ");
	scanf("%d", &c);
	
	min = a < b ? (a < c ? a : c) : (b < c ? b : c);
	
	printf("\nThe minimum of the %d, %d, and %d is %d.\n\n", a, b, c, min);

	return;
	
}
