#include <stdio.h>

int IsEven(int num) { 
	return !(num % 2); 
}

int main() {
	int num;
	
	printf("Enter a number : ");
	scanf("%d", &num);
	printf("%d is %s.\n", num, IsEven(num) ? "even" : "odd");
	
	return 0;
}
