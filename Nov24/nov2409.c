#include <stdio.h>

float calculateCharge(int units) {
    if (units <= 30) return units * 2.5f;
    else if (units <= 100) return (units - 30) * 3.7f + calculateCharge(30);
    else if (units <= 200) return (units - 100) * 4.85f + calculateCharge(100);
    else if (units <= 300) return (units - 200) * 5.0f + calculateCharge(200);
    else return (units - 300) * 7.0f + calculateCharge(300);
}

int main() {
    float pReading, nReading, consumed;
    float arrear, eDuty, fixed;
    float totalTax, netCharge;
    printf("Enter the previous meter reading : ");
    scanf("%f", &pReading);
    printf("Enter the present meter reading : ");
    scanf("%f", &nReading);
    printf("Enter the fixed charge amount : ");
    scanf("%f", &fixed);
    printf("Enter the tax rate : ");
    scanf("%f", &eDuty);
    printf("Enter pending payment amount : ");
    scanf("%f", &arrear);

    consumed = nReading - pReading;
    totalTax = consumed * eDuty;
    float cost = calculateCharge(consumed);
    netCharge = arrear + fixed + cost + totalTax;
    
    printf("\n");
    printf("\tELECTRICITY BILL\n");
    printf("----------------------------------\n");
    printf("Prev. Reading\t = Rs. %.2f\n", pReading);
    printf("Pres. Reading\t = Rs. %.2f\n", nReading);
    printf("Current charge\t = Rs. %.2f\n", cost);
    printf("Fixed charge\t = Rs. %.2f\n", fixed);
    printf("Elec. Duty\t = Rs. %.2f\n", totalTax);
    printf("Total Arrear\t = Rs. %.2f\n", arrear);
    printf("----------------------------------\n");
    printf("NET PAYABLE\t = Rs. %.2f\n\n", netCharge);

    return 0;
}
