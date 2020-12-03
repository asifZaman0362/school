#include <stdio.h>

void main() {
    int score1, score2, score3;
    printf("Enter the marks of three students : ");
    scanf("%d%d%d", &score1, &score2, &score3);
    if (score1 < 0 || score2 < 0 || score3 < 0 || score1 > 100 || score2 > 100 || score3 > 100)
        printf("Marks cannot be less than 0 or more than 100!\n");
    else {
        int highest = 0;
        if (score1 >= score2) {
            if (score1 >= score3) highest = score1;
            else highest = score3;
        } else {
            if (score2 >= score3) highest = score2;
            else highest = score3;
        }
        printf("Highest mark is : %d\n", highest);
    }
}
