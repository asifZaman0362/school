#include <stdio.h>

void main() {
    int chocolates = 56;
    int chocolatesPerStudent = 3;
    int students = 17;
    int remainingChocolates = chocolates - (chocolatesPerStudent * students);
    printf("Nayan has %d chocolates left for himself.\n", remainingChocolates);
}
