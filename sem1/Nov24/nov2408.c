#include <stdio.h>

void printSalary(float BP, float HRA, float DA, float net) {
    printf("\n\n");
    printf("|---------------------------------------|\n");
    printf("|              SALARY SLIP              |\n");
    printf("|---------------------------------------|\n");
    printf("|Basic Pay\t\t : Rs. %.2f\t|\n", BP);
    printf("|House Rent Allowance\t : Rs. %.2f\t|\n", HRA * BP);
    printf("|Daily Allowance\t : Rs. %.2f\t|\n", DA * BP);
    printf("|---------------------------------------|\n");
    printf("|TOTAL\t\t\t : Rs. %.2f\t|\n", net);
    printf("|---------------------------------------|\n\n");
}

int main() {
    float BP, HRA, DA, net;
    printf("\n\n------------ SALARY CALCULATOR ----------\n\n");
    printf("Enter the Basic Pay amount (Rs) >> ");
    scanf("%f", &BP);
    if (BP <= 20000) {
        HRA = 0.12f;
        DA = 0.20f;
    } else if (BP <= 30000) {
        HRA = 0.18f;
        DA = 0.30f;
    } else {
        HRA = 0.25f;
        DA = 0.40f;
    }
    net = BP + (BP * (HRA + DA));
    printSalary(BP, HRA, DA, net);
    return 0;
}
