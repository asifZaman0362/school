#include <stdio.h>
#include <stdlib.h>

void main() {
	
	int age;
	const char* msgEligible = "The person is eligible for voting.";
	const char* msgIneligible = "The person is not old enough to vote yet.";
	
	system("clear"); // no conio on Linux
	printf("Enter the age of the person : ");
	scanf("%d", &age);
	printf("\n%s\n\n", age >= 18 ? msgEligible : msgIneligible);
	
	return;
	
}
