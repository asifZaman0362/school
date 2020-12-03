#include <stdio.h>

void main() {
    int a, b;
    printf("Enter two numbers : ");
    scanf("%d%d", &a, &b);
    if (a % 2 == 0 && b % 2 == 0) printf("%d + %d = %d\n", a, b, a + b);
    else printf("The numbers are not even. Please try again...\n");
}
