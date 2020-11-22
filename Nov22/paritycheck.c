#include <stdio.h>
#include <stdlib.h>


int main() {

    int number;

    printf("Enter a number >> ");
    scanf("%d", &number);

    if (number % 2) printf("The given number is odd.\n");
    else printf("The given number is even.\n");

    return 0;

}