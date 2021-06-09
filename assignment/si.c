#include <stdio.h>

float si(float p, float r, float t) {
    return p * r * t / 100;
}

int main() {
    float p,t;
    int age;
    printf("Enter the principal amount: ");
    scanf("%f", &p);
    printf("Enter the time period in years: ");
    scanf("%f", &t);
    scanf(" Enter the age: ");
    scanf("%d", &age);
    float r = age >= 60 ? 0.12f : 0.1f;
    printf("SI = Rs. %f", si(p, r, t));
    return 0;
}
