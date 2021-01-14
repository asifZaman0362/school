#include <stdio.h>

int main() {
    int n, x, i = 0, sumE = 0, sumO = 0, sumExp = 1;
    printf("Enter a limit : ");
    scanf("%d", &n);
    printf("Enter a number : ");
    scanf("%d", &x);
    while (++i <= n) {
        if (i % 2 == 0) sumE += i;
        else sumO += i;
        int e = x;
        for (int j = 1; j < i; j++) e *= x;
        sumExp += e;
    }
    printf("The sum of evens is = %d\n", sumE);
    printf("The sum of odds is = %d\n", sumO);
    printf("1+2+...+n = %d\n", sumE + sumO);
    printf("Sum of exponential series = %d\n", sumExp);
    return 0;
}