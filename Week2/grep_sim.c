#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char filn[10],pattern[10],temp[200];
  int number=0;
  FILE *fptr;
  printf("\nEnter the File Name\t");
  scanf("%s",filn);
  printf("\nEnter pattern to search");
  scanf("%s",pattern);
  fptr=fopen(filn,"r");
  if(fptr==NULL)
  {
  	printf("\nCannot Open File. Exiting...");
  	exit(1);
  }
  while(!feof(fptr))
  {
  	fgets(temp,50,fptr);
  	if(strstr(temp,pattern))
  	{
  		printf("%s",temp);
  	}
  }	
fclose(fptr);
return 0;
}