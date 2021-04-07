#include <stdio.h>

int main() {
    int mat[3][3];
    printf("Enter the matrix elements :\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("(%d,%d) >> ", i+1, j+1);
            scanf("%d", mat[i]+j);
        }
    }
    printf("\n\n\n");
    for (int i = 0; i < 3; i++) {
        printf("|\t");
        for (int j = 0; j < 3; j++) printf("%d\t", mat[i][j]);
        printf("|\n");
    }
    printf("\n\n\n");
    return 0;
}
