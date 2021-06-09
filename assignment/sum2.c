#include <stdio.h>

int main() {
    int n;
    float series=0;
    printf("Enter the number of terms : ");
    scanf("%d", &n);
    for (int i=0;i<=n;i++) {
        series += (float)i/(i+1.0f);
    }
    printf("sum = %f", series);
    return 0;
}
