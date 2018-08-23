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
}	

else
{
	printf("\nThis is the parent\n");
	printf("\nParent ID=%d\t",pid);
	wait(NULL);
	exit(0);
}
return 0;
}
