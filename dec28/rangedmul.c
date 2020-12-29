#include <stdio.h>

int main() {
    int n, x, y;
    printf("Enter the number : ");
    scanf("%d", &n);
    printf("Enter the upper limit of the range : ");
    scanf("%d", &y);
    printf("Enter the lower limit of the range : ");
    scanf("%d", &x);

    for (int i = x; i <= y; i++) printf("%d * %d = %d\n", n, i, n * i);

    return 0;
}
