#include <stdio.h>

float div(float a, float b) {
	return a / b;	
}

int main() {
	float a, b;
	printf("Enter a number : ");
	scanf("%f", &a);
	printf("Enter another number : ");
	scanf("%f", &b);
	printf("%f / %f = %f", a, b, div(a, b));
	return 0;
}
