#include <stdio.h>

int main() {
    int num, i, count = 0;
    printf("Enter the number : ");
    scanf("%d", &num);
    if (i < 0) i *= -1;
    i = num;
    while (i > 0) {
        count++;
        i /= 10;
    }

    printf("Number of digits in %d = %d.\n", num, count);

    return 0;
}