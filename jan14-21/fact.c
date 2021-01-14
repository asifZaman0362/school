#include <stdio.h>

int main() {
    int n, fact = 1;
    printf("Enter a number : ");
    scanf("%d", &n);

    for (int i = n; i > 1; i--) fact *= i;
    printf("Factorial(%d) = %d\n", n, fact);

    return 0;
}