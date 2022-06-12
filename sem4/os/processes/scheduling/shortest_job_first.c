#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int wait_time;
    int turnaround_time;
} process_t;

int max(int x, int y) { return x > y ? x : y; }

void schedule (process_t *proc_arr, size_t count) {
    size_t n = count;
    bool swapped = false;
    while (!swapped) {
        swapped = false;
        for (size_t i = 1; i < n - 1; i++) {
            if (proc_arr[i - 1].burst_time > proc_arr[i].burst_time) {
                process_t temp = proc_arr[i];
                proc_arr[i] = proc_arr[i - 1];
                proc_arr[i - 1] = temp;
                swapped = true;
            }
        }
        n = n - 1;
    }
    int elapsed = 0;
    for (size_t i = 0; i < count; i++) {
        proc_arr[i].wait_time = max(elapsed - proc_arr[i].arrival_time, 0);
        elapsed += proc_arr[i].burst_time;
    }
}

int main (void) {
    size_t count;
    printf("Enter the number of processes to schedule: ");
    scanf("%d", &count);
    printf("Enter the process details:\n");
    process_t process[count];
    for (int i = 0; i < count; i++) {
        process[i].pid = i;
        printf("Enter the arrival time of process[%d]: ", i + 1);
        scanf("%d", &process[i].arrival_time);
        printf("Enter the burst time of process[%d]: ", i + 1);
        scanf("%d", &process[i].burst_time);
    }
    schedule(process, count);
    printf("Scheduled processes (SJF):\n");
    printf("┌───────┬───────┬───────┬───────┐\n");
    printf("│ PID\t│ AT\t│ BT\t│ WT\t│\n");
    printf("├───────┼───────┼───────┼───────┤\n");
    for (int i = 0; i < count; i++) {
        printf("│ %d\t│ %d\t│ %d\t│ %d\t│\n", process[i].pid, 
                process[i].arrival_time, process[i].burst_time, process[i].wait_time);
    }
    printf("└───────┴───────┴───────┴───────┘\n");
    return 0;
}
