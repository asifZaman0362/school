#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_PROCESS 100

typedef struct {
	int id;
	int arrival_time;
	int burst_time;
	int wait_time;
	int turnaround_time;
} process_t;

int max(int a, int b) {
	return a > b ? a : b;
}

void get_processes(process_t *process_list, int *size) {
	printf("Enter the number of processes to be scheduled: ");
	scanf("%d", size);
	for (int i = 0; i < *size; i++) {
		printf("Enter process id: ");
		scanf("%d", &process_list[i].id);
		printf("Enter the arrival time: ");
		scanf("%d", &process_list[i].arrival_time);
		printf("Enter the burst time: ");
		scanf("%d", &process_list[i].burst_time);
	}
}

void schedule(process_t *process_queue, const int size) {
	bool sorted = false;
	int i = 0;
	while ((++i < size) && !sorted) {
		sorted = true;
		for (int j = 0; j < size - i; j++) {
			if (process_queue[j + 1].arrival_time < process_queue[j].arrival_time) {
				process_t temp = process_queue[j + 1];
				process_queue[j + 1] = process_queue[j];
				process_queue[j] = temp;
				sorted = false;
			}
		}
	}
}

void calc_time(process_t *sorted, const int size, int *total_wait, int *total_turnaround) {
	int compl_time = 0;
	for (int i = 0; i < size; i++) {
		if (i == 0) sorted[i].wait_time = 0;
		else sorted[i].wait_time = max(compl_time - sorted[i].arrival_time, 0);
		sorted[i].turnaround_time = sorted[i].burst_time + sorted[i].wait_time;
		*total_wait += sorted[i].wait_time;
		*total_turnaround += sorted[i].turnaround_time;
		compl_time += sorted[i].burst_time;
	}
}

void print_queue(process_t *process_queue, const int size) {
	system("clear");
	printf("After scheduling using the FCFS algorithm:\n");
	printf("---------------------------------------------------------------------------------\n");
	printf("| ID\t\t| Arrival\t| Burst\t\t| Wait\t\t| Turnaround\t|\n");
	printf("---------------------------------------------------------------------------------\n");
	for (int i = 0; i < size; i++) {
		process_t *p = process_queue + i;
		printf("| %d\t\t| %d\t\t| %d\t\t| %d\t\t| %d\t\t|\n", p->id, p->arrival_time, p->burst_time, p->wait_time, p->turnaround_time);
	}
	printf("---------------------------------------------------------------------------------\n");
}

int main(void) {
	process_t processes[MAX_PROCESS];
	int count;
	int total_wait = 0, total_turnaround = 0;
	get_processes(processes, &count);
	schedule(processes, count);
	calc_time(processes, count, &total_wait, &total_turnaround);
	print_queue(processes, count);
	printf("Average wait time: %f\n", (float) total_wait / count);
	printf("Average turnaround time: %f\n", (float) total_turnaround / count);
	return 0;
}
