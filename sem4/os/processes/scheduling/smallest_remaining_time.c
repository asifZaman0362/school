#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define max(a, b) return a > b ? a : b

typedef struct {
	int arrival_time;
	int wait_time;
	int burst_time;
	int turnaround_time;
	int finish_time;
	int remaining_time;
	int completion_time = -1;
} process_t;

void schedule(process_t *arr, size_t count) {
	size_t time = 0;
	bool completed = false;
	int smallest = 0;
	while (!completed) {
		completed = true;
		for (size_t i = 0; i < count; i++) {
			if (arr[i].remaining_time > 0) {
				completed = false;
				if (arr[i].arrival_time < time) continue;
				if (arr[i].remaining_time < arr[smallest].remaining_time) smallest = i;
			}
			arr[smallest].remaining_time--;
			if (arr[smallest].remaining_time == 0) arr[smallest].completion_time = time;
		}
	}
	for (size_t i = 0; i < count; i++) {
		arr[i].wait_time = max(arr[i].completion_time - arr[i].arrival_time - arr[i].burst_time, 0);
		arr[i].turnaround_time = arr[i].completion_time - arr[i].arrival_time;
	}
}

int main (void) {
	size_t count;
	printf("Enter the number of processes: ");
	scanf("%lu", &count);
	printf("Enter AT, BT\n");
	process_t process[count];
	// Get the list of processes
	for (size_t i = 0; i < count; i++) {
		printf("process[%lu]:");
		scanf("%d%d", &process[i].arrival_time, &process[i].burst_time);
		process[i].remaining_time = process[i].burst_time;
	}
	schedule(process, count);
	return 0;
}
