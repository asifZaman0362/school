#include <stdio.h>

void main() {
    float BP, HRA, DA, net;
    printf("Enter the Basic Pay amount (Rs) >> ");
    scanf("%f", &BP);

    if (BP < 5000) {
        printf("Salary has to be more than 5000 and less than 60000!\n");
        return;
    } else if (BP <= 25000) {
        HRA = 0.18f;
        DA = 0.22f;
    } else if (BP <= 35000) {
        HRA = 0.25f;
        DA = 0.28f;
    } else if (BP <= 40000) {
        HRA = 0.32f;
        DA = 0.34f;
    } else if (BP <= 60000) {
        HRA = 0.39f;
        DA = 0.40f;
    } else {
        printf("Salary has to be more than 5000 and less than 60000!\n");
        return;
    }

    net = BP + (BP * (HRA + DA));
    printf("The net salary of the employee = %.2f\n", net);
}