#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of items : ");
    scanf("%d", &n);
    i = n;
    while (i >= 1) printf("%d", i--);
    return 0;
}
