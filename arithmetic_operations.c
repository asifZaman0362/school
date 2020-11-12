#include <stdio.h>

void main() {

    int operand1, operand2;
    
    printf("Enter the first number : ");
    scanf("%d", &operand1);
    printf("Enter the second number : ");
    scanf("%d", &operand2);

    int addition = operand1 + operand2;
    int subtraction = operand1 - operand2;
    int product = operand1 * operand2;
    float quotient = (float)operand1 / operand2;
    int remainder = operand1 % operand2;

    printf("\n\n");
    printf("%d + %d = %d\n", operand1, operand2, addition);
    printf("%d - %d = %d\n", operand1, operand2, subtraction);
    printf("%d * %d = %d\n", operand1, operand2, product);
    printf("%d / %d = %f\n", operand1, operand2, quotient);
    printf("%d %% %d = %d\n", operand1, operand2, remainder);
    printf("\n\n");    

    return;

}
