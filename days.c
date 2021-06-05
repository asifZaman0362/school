#include <stdio.h>

int main() {
    int year;
    printf("Enter the year : ");
    scanf("%d", &year);
    int days = year % 4 ? 28 : 29;
    printf("February has %d days in %d", days, year);
    return 0;
}
