#include <stdio.h>

int main() {
    int n, i = 0;
    printf("Enter the number of items : ");
    scanf("%d", &n);
    while (i < n) printf("%d,", ++i);
    return 0;
}
