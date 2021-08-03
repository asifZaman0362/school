// Question 5

#include <stdio.h>

void main() {

	float base, height, area;
	
	printf("\nEnter the base of the triangle : ");
	scanf("%f", &base);
	printf("Enter the height of the triangle : ");
	scanf("%f", &height);
	
	area = 0.5f * base * height;
	
	printf("The area of the triangle is = %f\n", area);
	
	return;
	
}
