#include <stdio.h>

void main() {
    float radius = 0, area = 0;
    printf("Enter the radius of the circle : ");
    scanf("%f", &radius);
    if (radius < 0) printf("Radius must be positive!\n");
    else {
        area = 2.0f * 3.14159f * radius;
        printf("Area of the circle is %.2f units.\n", area);
    }
}
