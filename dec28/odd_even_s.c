#include <stdio.h>

int main() {
    int n, i = 0, sumE = 0, sumO = 0;
    printf("Enter the number of items : ");
    scanf("%d", &n);
    while (++i <= n) {
        if (i % 2 == 0) sumE += i;
        else sumO += i;
    }
    printf("The sum of evens is = %d\n", sumE);
    printf("The sum of odds is = %d\n", sumO);
    return 0;
}
