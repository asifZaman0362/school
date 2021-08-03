#include <stdio.h>

int main() {
    int N;
    printf("enter the number of rows: ");
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++)
            printf("%d ", j+1);
        printf("\n");
    }
    return 0;
}
