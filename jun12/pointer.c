#include <stdio.h>

void square(int *a) {
    *a *= *a;
}

int main() {
    int a, *a_ptr = &a;
    printf("enter a number: ");
    scanf("%d", a_ptr);
    square(a_ptr);
    printf("%d", a);
    return 0;
}
