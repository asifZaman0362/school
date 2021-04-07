#include <stdio.h>

void swap_val(int a, int b) {
    printf("Before swapping : \na = %d; b = %d\n", a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("Swapping by value : \na = %d; b = %d\n", a, b);
}

void swap_ref(int *a, int *b) {
    printf("Before swapping : \na = %d; b = %d\n", *a, *b);
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    printf("Swapping by value : \na = %d; b = %d\n", *a, *b);
}

int main() {
    int a, b;
    printf("Enter the numbers : \n");
    scanf("%d%d", &a, &b);
    swap_val(a, b);
    swap_ref(&a, &b);
    return 0;
}
