#include <stdio.h>

int main() {
    int bin, mod, dec = 0;
    printf("enter unsigned binary number: ");
    scanf("%d", &bin);
    mod = 1;
    while (bin > 0) {
        dec += bin % 2 * mod;
        mod *= 2;
        bin /= 10;
    }
    printf("decimal = %d", dec);
    return 0;
}
