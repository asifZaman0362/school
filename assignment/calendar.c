#include <stdio.h>

int main() {
    int n, day;
    char days[7][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    printf("index of the starting day (1: Sun...7: Sat) : ");
    scanf("%d", &day);
    printf("enter the number of days in the month: ");
    scanf("%d", &n);
    for (int i=1;i<=n;i++) {
        printf("%d %s\n", i, days[(day-1)%7]);
        day++;
    }
    return 0;
}
