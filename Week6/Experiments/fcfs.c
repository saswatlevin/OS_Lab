#include <stdio.h>
#include "structs.h"
#include <stdlib.h>

struct process proc[10];
struct gantt   g[10];
int n;
int sum=0;
void input()
{
	

	printf("\nEnter no. of processes");
    scanf("%d",&n);
    


    for(int i=0;i<n;++i)
    {
    	
    	printf("\nEnter process id of process%d\t",i);
    	scanf("%d",&proc[i].pid);
    	printf("\nEnter burst time of process%d\t",i);
    	scanf("%d",&proc[i].burst_t);
        printf("\nEnter arrival time of process%d\t",i);
        scanf("%d",&proc[i].arr_t);
        //fflush(stdin);
        //proc[i].burst_t=0;
        //printf("\nEnter waiting time o")
        
    }



}


void sort()
{

int key;
int i,j;

for(i=1;i<n;++i)
{	

	key=proc[i].arr_t;
    j=i-1;

    while(j>0 && proc[i].arr_t > key)
    {
    	proc[i+1].arr_t=proc[i].arr_t;
    
        j=i-1;
    }
    proc[i+1].arr_t=key;


}
printf("\nSorted");
}

/*void sched()
{


int i=0; 

while(i<n)
{
 

sum=sum+proc[i].burst_t;
proc[i].wt_t=sum-proc[i].burst_t;
proc[i].fi_t=proc[i].wt_t+proc[i-1].burst_t;
printf("\nWait time of process %d\t is=%d\t",i,proc[i].wt_t);
printf("\nFinish time of process %d\t is %d\t",i,proc[i].fi_t);


i=i+1;
}*/






void assign_gantt()
{
   int i;
   int start=0;
   while(i<n)
   {

    g[i].g_pid=proc[i].pid;
    g[i].start=start;
    g[i].end=g[i].start+proc[i].burst_t;
    start=g[i].end;
    proc[i].fi_t=g[i].end;
    //g[i].g_burst=proc[i].burst_t;
    //g[i].g_wt_t=proc[i].wt_t;
   }


}

void output()
{
	int i=0;

	printf("\nProcess id:");
	for(i=0;i<n;++i)
	{
		printf("%d\t|",proc[i].pid);
	}
    
    //i=0;
    
    /*printf("\nWaiting time:");

for(i=0;i<n;++i)
	{
		printf("%d\t|",proc[i].wt_t);
	}*/
    
    //i=0;
    printf("\nArrival time");
    for(i=0;i<n;++i)
	{
		printf("%d\t|",proc[i].arr_t);
	}
    
    printf("\nBurst time");

    for(i=0;i<n;++i)
    {
      printf("%d\t|",proc[i].burst_t);
	
    }


}

void main()
{

input();
sort();
//sched();
assign_gantt();
//output();


}
