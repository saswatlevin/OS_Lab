#include <stdio.h>
#include <stdlib.h>

int main()
{

char fn[1000],snt[1000];
FILE *fptr;
printf("\nEnter file name");
scanf("%s",fn);

if(fptr==NULL)
{
	printf("\nError!");
	exit(1);
}	

printf("\nEnter a sentence");
scanf("%s",snt);

return 0;

}