#include <stdio.h>

int main() {
	int x, y, sum = 0;
	printf("Enter the lower limit : ");
	scanf("%d", &x);
	printf("Enter the upper limit : ");
	scanf("%d", &y);

	printf("Even numbers in the range : \n");
	for (int i = x; i < y; i++) {
		if (!(i % 2)) {
			printf("%d;", i);
			sum += i;
		}	
	}

	printf("\nSum of the even numbers : %d\n", sum);
	return 0;
}
