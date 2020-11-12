#include <stdio.h>
#include <stdlib.h>

void main() {
	
	int a, b;
	
	system("clear"); // no conio on Linux
	printf("Enter the first number : ");
	scanf("%d", &a);
	printf("Enter the second number : ");
	scanf("%d", &b);
	
	printf("\n\nThe numbers are %s.\n\n", a == b ? "equal" : "not equal");
	
	return;
	
}
