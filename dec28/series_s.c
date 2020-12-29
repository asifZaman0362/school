#include <stdio.h>

int main() {
    int n, i = 0, sum = 0;
    printf("Enter the number of items : ");
    scanf("%d", &n);
    while (i < n) sum += ++i;
    printf("The sum is = %d\n", sum);
    return 0;
}
