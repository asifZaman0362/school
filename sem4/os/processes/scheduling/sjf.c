#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int wt, at, bt, tat
} process_t;

int main (void) {
    process_t p[10];
    int bt[10];
    size_t count = 0;
    size_t scheduled = 0;
    uint64_t time = 0;
    printf("n >> ");
    scanf("%lu", count);
    float tot_wt = 0, tot_tat = 0, avg_wt, avg_tat;
    printf("Enter the arrival and burst times\n");
    for (size_t i = 0; i < count; i++) {
        printf("p[%d] AT, WT>> ", i);
        scanf("%d%d", &p[i].at, &p[i].bt);
        bt[i] = p[i].bt; // store burst times for scheduler calculations
    }
    // initialising the burst time of the last process with the maximum
    p[9].bt = 10000;
    for (time; count != scheduled; time++) {
        size_t shortest = 9;
        for (size_t i = 0; i < count; i++) {
            if (p[i].bt < p[shortest].bt && (p[i].at <= time && p[i].bt > 0)) {
                shortest = i;
            }
        }
        p[shortest].bt--;
        if (p[shortest].bt == 0) {
            count++;
            p[shortest].wt = (time + 1) - p[shortest].at - bt[shortest];
            p[shortest].tat = (time + 1) - p[shortest].at;
            tot_wt += p[shortest].wt;
            tot_tat += p[shortest].tat;
        }
    }

    return 0;
}
