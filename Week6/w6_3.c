#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 127

FILE *gantt;

typedef enum { NO, YES } BOOL;

typedef struct process {
	int id;		// process id
	int at;		// arrival time
	int bt;		// burst time
	int rt;		// remaining time, sorted by this when a new process is added
	int wt;		// wait time
	int tat;	// turnaround time
} process_t, *process_p_t;

double awt, atat; // Average wait time and average turnaround time

int n; // Curent number of process
int k; // Currently being exegguted
process_p_t *pross; // List of processes

int time; // Current time
int ktime; // Time for which current process has been executed
int quantum; // Quantum of time allotted to a process

void init () {

	gantt = fopen("gantt.txt", "w+");
	fprintf(gantt, "TIME ||   \n");
	fprintf(gantt, " - - || - - - - - - - - - - -\n");

	int i;
	pross = (process_p_t *)calloc(MAX, sizeof(process_p_t));
	for (i = 0; i < MAX; ++i) {
		*(pross + i) = (process_p_t)malloc(sizeof(process_t));
	}
}

void addProcess (int at, int bt) {
	process_p_t p = *(pross + n);
	p->id = n;
	p->at = at;
	p->bt = bt;
	p->rt = bt;
	p->wt = 0;
	p->tat = 0;
	n += 1;
}

void printCurrent () {
	int i;
	printf("\nTime [%d]:\n    ID |   AT |   RT |   WT |   TAT\n", time);
	for (i = 0; i < n; ++i) {
		process_p_t p = *(pross+i);
		printf("  %3d  |  %3d |  %3d |  %3d |  %3d\n", p->id, p->at, p->rt, p->wt, p->tat);
	}
	printf("\n");
}

void executeOneTime () {
	
	printCurrent();

	time += 1;
	ktime += 1;
	int i;

	// Allot to the next process that has pending operations
	process_p_t p = *(pross + k);
	if (ktime % quantum == 0 || p->rt <= 0) {
		ktime = 0;
		k = (k + 1) % n;
		p = *(pross + k);
		int kk = k;
		while (p->rt <= 0) {
			k = (k + 1) % n;
			p = *(pross + k);
			if (k == kk) {
				printf("-- NO PENDING PROCESSES --\n");
				return;
			}
		}
	}
	
	for (i = 0; i < n; ++i) {
		p = *(pross + i);
		if (i == k) {
			printf("Servicing process %d [AT = %d, RT = %d]\n", p->id, p->at, p->rt);
			fprintf(gantt, "%4d ||", time);
			int l;
			for (l = 0; l < n; ++l) {
				if (l == p->id)
					fprintf(gantt, " * |");
				else
					fprintf(gantt, "   |");
			}
			fprintf(gantt, "\n");
			p->rt -= 1;
			p->tat += 1;
		} else {
			if (p->rt > 0) {
				p->wt += 1;
				p->tat += 1;
			}
		}
	}

}


int main (int argc, char const *argv[]) {

	init();

	int ch;
	time = 0;
	k = 0;

	printf("Enter the time quantum: ");
	scanf(" %d", &quantum);


	do {

		printf("\nTime = [%.2d]; 1. Input new process(es)\n", time);
		if (time > 0)
			printf("             2. Continue exeggution\n");
		printf("             0. Exit\n");
		printf("                Choice: ");
		scanf(" %d", &ch);

		if (ch < 1 || ch > 2) {
			printf("Terminating...\n");
			break;
		}

		if (ch == 1) {

			int bbt;
			char mander;
			do {
				printf("Enter burst time of process entering at time = %d: ", time);
				scanf(" %d", &bbt);
				addProcess(time, bbt);
				printf("Add another (y/n): ");
				scanf(" %c", &mander);
			} while (mander == 'y');

		}

		executeOneTime();

	} while (ch >= 1 && ch <= 2);
	
	awt = 0.0;
	atat = 0.0;

	fprintf(gantt, " - - || - - - - - - - - - - -\n");
	fprintf(gantt, "  ID ||");
	int i;
	printf("\nFinally:\n    ID |   AT |   BT |   WT |   TAT\n");
	for (i = 0; i < n; ++i) {
		process_p_t p = *(pross+i);
		awt += p->wt;
		atat += p->tat;
		fprintf(gantt, "%2d |", p->id);
		printf("  %3d  |  %3d |  %3d |  %3d |  %3d\n", p->id, p->at, p->bt, p->wt, p->tat);
	}

	awt /= n;
	atat /= n;

	printf("\n      Average wait time = %.2lf\n", awt);
	printf("Average turnaround time = %.2lf\n", atat);

	fprintf(gantt, "\n");
	fclose(gantt);
	printf("Gantt chart: \n");
	system("cat gantt.txt");
	system("rm gantt.txt"); // Yeah, it's a jugaad, snprintf wasn't working for some reason :p

	return 0;
}