#include <stdio.h>

int main() {
    int marks[4], tot = 0;
    printf("Enter the marks:\n");
    for (int i = 0; i < 4; i++) {
        scanf("%d", marks+i);
        tot += marks[i];
    }
    float percent = tot / 4.0f;
    if (percent >= 75)
        printf("Grade: Distinction");
    else if (percent >= 60)
        printf("Grade: First Division");
    else if (percent >= 50)
        printf("Grade: Second Division");
    else if (percent >= 40)
        printf("Grade: Third Division");
    else
        printf("Grade: Fail");
    return 0;
}

