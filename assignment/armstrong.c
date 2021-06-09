#include <stdio.h>

#define cube(n) n * n * n;

int main() {
    int num, i, count = 0, sum = 0;
    printf("Enter the number : ");
    scanf("%d", &num);
    if (i < 0) i *= -1;
    i = num;
    while (i > 0) {
        count++;
        sum += cube((i % 10));
        i /= 10;
    }

    if (sum == num) printf("%d is an Armstrong number.\n", num);
    else printf("%d is not an Armstrong number.\n", num);

    return 0;
}