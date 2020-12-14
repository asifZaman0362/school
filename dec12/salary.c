#include <stdio.h>
#include <stdlib.h>


#if defined(_WIN32_) || defined(_WIN64_)
#define clear() system("cls")
#endif
#ifdef linux
#define clear() system("clear")
#endif


void printSalary(float BP, float HRA, float DA, float net) {
    clear();
    printf("\n\n");
    printf("\t╔═══════════════════════════════════════╗\n");
    printf("\t║ SALARY SLIP                           ║\n");
    printf("\t╠════════════════════════╤══════════════╣\n");
    printf("\t║ Basic Pay\t\t │ Rs. %.2f\t║\n", BP);
    printf("\t╟╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌┼╌╌╌╌╌╌╌╌╌╌╌╌╌╌╢\n");
    printf("\t║ House Rent Allowance\t │ Rs. %.2f\t║\n", HRA * BP);
    printf("\t╟╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌┼╌╌╌╌╌╌╌╌╌╌╌╌╌╌╢\n");
    printf("\t║ Daily Allowance\t │ Rs. %.2f\t║\n", DA * BP);
    printf("\t╟╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌┼╌╌╌╌╌╌╌╌╌╌╌╌╌╌╢\n");
    printf("\t║ TOTAL\t\t\t │ Rs. %.2f\t║\n", net);
    printf("\t╚════════════════════════╧══════════════╝\n\n");
}


int main() {
    int BP;
    float HRA, DA, net;
    printf("\n\n------------ SALARY CALCULATOR ----------\n\n");
    printf("Enter the Basic Pay amount (Rs) >> ");
    scanf("%d", &BP);
    if (BP < 0) { printf("Invalid input!"); return 1; }
    switch(BP / 10000) {
        case 0:
        case 1:
            HRA = 0.12f;
            DA = 0.20f;
            break;
        case 2:
            HRA = 0.18f;
            DA = 0.30f;
            break;
        default:
            HRA = 0.25f;
            DA = 0.40f;
            break;
    }
    net = BP + (BP * (HRA + DA));
    printSalary(BP, HRA, DA, net);
    return 0;
}
