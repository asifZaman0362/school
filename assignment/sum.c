#include <stdio.h>

int main() {
    int a, b, sum = 0;
    printf("enter the start: ");
    scanf("%d", &a);
    printf("enter the end: ");
    scanf("%d", &b);
    for (int i = a; i <= b; i++) {
        sum += i;
    }
    printf("sum = %d\n", sum);
    return 0;
}
