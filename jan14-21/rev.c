#include <stdio.h>

int main() {
    int num, orig, rev = 0;
    printf("Enter a number : ");
    scanf("%d", &num);
    orig = num;
    if (num < 0) num *= -1;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }

    printf("Reverse of %d = %d\n", orig, rev);

    return 0;
}