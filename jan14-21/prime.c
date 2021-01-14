#include <stdio.h>


int main() {
    int num, isPrime = 1;
    printf("Enter a number : ");
    scanf("%d", &num);

    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            isPrime = 0;
            break;
        } else continue;
    }

    printf("%d is ", num, isPrime ? "a prime." : "not a prime.");
    
    return 0;
}