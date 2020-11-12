// Question 5

#include <stdio.h>

void main() {
    int b;                              // declares an integer identified by 'b'
    printf("Please enter the number "); // prints the quoted line to the console
    scanf("%f", &b);                    // takes in a float and tries to assign it to 'b' but fails to parse due to unexpected type
}
