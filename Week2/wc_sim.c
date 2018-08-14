#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#define MAX 100

int main()
{
FILE *fp;
char file[20],ch;
int c=0,w=0,l=0;

printf("\nEnter Filename\t");
scanf("%s",file);
fp=fopen(file,"r");

if(fp==NULL)
{
	printf("\nCan't read file. Exiting...");
    exit(1);
}

while(1)
{
	ch=fgetc(fp);
	c++;
	if(ch==EOF)
		break;
	else if(ch==' ')
		w++;
	else if(ch=='\n')
	{
		l++;
		w++;
	}

}	

printf("\nNo. of characters=\t%d",c);
printf("\nNo. of lines=\t%d",l);
printf("\nNo. of words=\t%d",w);


return 0;
}
