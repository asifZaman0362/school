#include <stdio.h>

int main() {
    int n, i = 0, j = 1;
    printf("Enter the limit : ");
    scanf("%d", &n);
    printf("The fibonacci series upto %d is : \n", n);
    do {
        printf("%d%s", i, i == 5 ? "\n" : ", ");
        int x = i;
        i = j;
        j += x;
    } while (i <= n);
    return 0;
}