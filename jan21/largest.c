#include <stdio.h>

int main() {
	int a, b, c, greatest;
	
	printf("Enter three numbers : \n");
	printf(">> ");
	scanf("%d", &a);
	printf(">> ");
	scanf("%d", &b);
	printf(">> ");
	scanf("%d", &c);
	
	greatest = a > b ? (a > c ? a : c) : b > c ? b : c;
	printf("The greatest number is : %d\n", greatest);

	return 0;
}
