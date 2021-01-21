#include <stdio.h>

int main() {
	int x;
	
	printf("Enter the number of rows to print : ");
	scanf("%d", &x);
	
	for (int i = 0; i < x; i++) {
		for (int j = 0; j <= i; j++) printf("1");
		printf("\n");
	}

	return 0;
}
