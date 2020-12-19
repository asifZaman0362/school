#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32_) || defined(_WIN64_)
#define clear() system("cls")
#endif
#ifdef linux
#define clear() system("clear")
#endif


int getChoice() {

    clear();

    int choice;
    printf("\n\n");
    printf("\t╔═══════════════════════════════════════╗\n");
    printf("\t║ Chose a task from the listed options: ║\n");
    printf("\t╠═══╤═══════════════════════════════════╣\n");
    printf("\t║ 1.│ Calculator.                       ║\n");
    printf("\t╟╌╌╌┼╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╢\n");
    printf("\t║ 2.│ Check parity of a number.         ║\n");
    printf("\t╟╌╌╌┼╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╢\n");
    printf("\t║ 3.│ Check the sign of a number.       ║\n");
    printf("\t╟╌╌╌┼╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╢\n");
    printf("\t║ 0.│ Exit.                             ║\n");
    printf("\t╚═══╧═══════════════════════════════════╝\n");
    
    printf("\t:");
    scanf("%d", &choice);

    return choice;

}

int calculate() {

    float a, b, res;
    char op, p_op;

    clear();
    printf("\n\n");
    printf("\tArithmetic operations\n");
    printf("\t------------------------------\n");
    printf("\tEnter two numbers : \n");
    
    printf("\t-> ");
    scanf("%f", &a);
    printf("\t-> ");
    scanf("%f", &b);

    clear();
    printf("\n\n");
    printf("\t╔═══════════════════════════════════════╗\n");
    printf("\t║ Chose an arithmetic operation:        ║\n");
    printf("\t╠═══╤═══════════════════════════════════╣\n");
    printf("\t║ 1.│ Addition        (%.1f + %.1f)\t║\n", a, b);
    printf("\t╟╌╌╌┼╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╢\n");
    printf("\t║ 2.│ Subtraction     (%.1f - %.1f)\t║\n", a, b);
    printf("\t╟╌╌╌┼╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╢\n");
    printf("\t║ 3.│ Multiplication  (%.1f * %.1f)\t║\n", a, b);
    printf("\t╟╌╌╌┼╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╢\n");
    printf("\t║ 4.│ Division        (%.1f / %.1f)\t║\n", a, b);
    printf("\t╟╌╌╌┼╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╢\n");
    printf("\t║ 5.│ Modulo          (%.1f %% %.1f)\t║\n", a, b);
    printf("\t╚═══╧═══════════════════════════════════╝\n");

    printf("\t:");
    scanf(" %c", &op);
    
    switch(op) {
        case '1':
        case '+':
            p_op = '+';
            res = a + b;
            break;
        case '2':
        case '-':
            p_op = '-';
            res = a - b;
            break;
        case '3':
        case '*':
            p_op = '*';
            res = a * b;
            break;
        case '4':
        case '/':
        case '\\':
            p_op = '/';
            res = a / b;
            break;
        case '5':
        case '%':
            p_op = '%';
            res = (int)a % (int)b;
            break;
        default:
            printf("\tUnexpected input! Please try again.\n");
            return 1;
    }

    clear();
    printf("\n\n");
    printf("\t    %.2f\n", a);
    printf("\t(%c) %.2f\n", p_op, b);
    printf("\t--------------------\n");
    printf("\t    %.2f\n\n\n", res);
    
    printf("\tEnter (1) to conitnue and (0) to exit...\n\t:");
    int returnCode;
    scanf("%d", &returnCode);

    return returnCode;

}

int checkParity() {

    int num;

    clear();
    printf("\n\n\tChecking parity of a number :\n");
    printf("\t--------------------------------------\n");
    printf("\tEnter a number -> ");
    scanf("%d", &num);
    
    if (num % 2 == 0) printf("\t%d is even.\n", num);
    else printf("\t%d is odd.\n", num);

    int returnCode;
    printf("\n\n\tEnter (1) to continue or (0) to exit...\n\t:");
    scanf("%d", &returnCode);

    return returnCode;

}

int checkSign() {

    int num;

    clear();
    printf("\n\n\tChecking the sign of a number : \n");
    printf("\t------------------------------------\n");
    printf("\tEnter a number -> ");
    scanf("%d", &num);

    if (num == 0) printf("\t0 is neither positive nor negative.\n");
    else if (num < 0) printf("\t%d is negative.\n", num);
    else printf("\t%d is positive.\n\n\n", num);

    int returnCode;
    printf("\tEnter (1) to continue and (0) to exit...\n\t:");
    scanf("%d", &returnCode);
    return returnCode;

}

int main() {

    int task = 1;

    while (task) {
        task = getChoice();

        switch(task) {
            case 0:
                break;
            case 1:
                if(calculate()) continue;
                break;
            case 2:
                if(checkParity()) continue;
                break;
            case 3:
                if (checkSign()) continue;
                break;
            default:
                printf("\tInvalid Choice! Try again...");
        }

        break;
    }

    clear();
    return 0;

}
