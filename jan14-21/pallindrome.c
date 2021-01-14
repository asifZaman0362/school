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

    if (rev == orig) printf("%d is a pallindrome.\n", orig);
    else printf("%d is not a pallindrome.\n", orig);

    return 0;
}