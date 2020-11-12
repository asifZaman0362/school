// C program to find the simple interest for the given period, principal amount and the interest rate

#include <stdio.h>

void main() {

	float principal, rate, time;
	float simpleInterest = 0;

	printf("Enter the principal amount >> ");
	scanf("%f", &principal);
	printf("Enter the rate of interest (in percentage) >> ");
	scanf("%f", &rate);
	printf("Enter the duration of interest (in years) >> ");
	scanf("%f", &time);

	simpleInterest = principal * rate * time / 100;

	printf("The amount of simple interest to be paid : %f\n", simpleInterest);

	return;

}