// C Program to find the area of a circle given its radius

#include <stdio.h>

#define PI 3.14159f

void main() {
	
	float radius, area = 0;
	
	printf("Enter the radius of the circle >> ");
	scanf("%f", &radius);
	
	area = PI * radius * radius;
	
	printf("Area of the circle is %f\n", area);
	
	return;
	
}