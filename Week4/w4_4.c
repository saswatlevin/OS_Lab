#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main()
{
pid_t pid;
pid=fork();

if(pid<0)
{	
	printf("\n Fork failed. Exiting");
    exit(1);
}
else if(pid==0)
{
	printf("\nChild ID=%d\t",pid);
	printf("\nIt is the Child\n");
    exit(0);
}	

else
{
	printf("\nThis is the parent\n");
	printf("\nParent ID=%d\t",pid);
	sleep(1000);
	exit(0);
}
return 0;
}
