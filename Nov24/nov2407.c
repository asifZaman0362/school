#include <stdio.h>

int main() {
    int year, days = 28;
    printf("Enter the year : ");
    scanf("%d", &year);
    if (year % 4 == 0) days = 29;
    printf("The number of days in February, %d is : %d.\n", year, days);
    return 0;
}
