#include <stdio.h>

int main() {
    int n, i = 0;
    printf("Enter the limit : ");
    scanf("%d", &n);
    
    printf("In Ascending order :\n");
    while (i < n) printf("%d\n", ++i);

    printf("In Descending order :\n");
    while (i > 0) printf("%d\n", i--);

    return 0;
}