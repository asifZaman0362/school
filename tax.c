#include <stdio.h>

int main() {
    int salary;
    float tax;
    printf("Enter salary amount : ");
    scanf("%d", &salary);
    if (salary <= 150000)
        tax = 0;
    else if (salary <= 300000)
        tax = salary * 0.1f;
    else if (salary <= 500000)
        tax = salary * 0.2f;
    else if (salary > 500000)
        tax = salary * 0.3f;
    printf("You owe %f in tax", tax);
    return 0;
}
