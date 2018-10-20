#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int mem_part[5];
int pr_siz[4];
int pr_no[4];
int flags[4];
int n;




void input()
{

int i,j;

printf("\nEnter the number of processes");
scanf("%d",&n);

printf("\nEnter the process numbers");
for(i=0;i<n;++i)
{
scanf("%d",&pr_no[i]);
}

printf("\nEnter the memory partition sizes");

for(i=0;i<5;++i){
	scanf("%d",&mem_part[i]);
}

printf("\nEnter the process sizes");
for(i=0;i<n;++i){
	scanf("%d",&pr_siz[i]);
}

//printf("\nInitializing flags to 0");
for(i=0;i<n;++i)
{
	flags[i]=0;
}

}


 


void disp_init()
{
int i,j;
printf("\nInitially the memory partitions are:");

for(i=0;i<n;++i){
	printf("%d\t",mem_part[i]);
}


printf("\nInitially,the process numbers are:");

for(i=0;i<n;++i)
{
printf("%d\t",pr_no[i]);
}


printf("\nThe process sizes are:");

for(i=0;i<n;++i)
{
printf("%d\t",pr_siz[i]);
}

}


void first_fit()
{
int i,j;
//printf("\nFIRST FIT\n");

for(i=0;i<n;++i)
{

if(pr_siz[i]<=mem_part[i] && flags[i]==0)
{

mem_part[i]=mem_part[i]-pr_siz[i];
flags[i]=1;

}

else
{
	printf("\nFailed to allocate partition for process %d size %d\n",pr_no[i],pr_siz[i]);
    flags[i]=0;
}

}


fflush(stdout);
for(i=0;i<5;++i)
{

if(flags[i]==1)
{
printf("\nprocess %d allocated %d \n",pr_no[i],mem_part[i]);
}
}

//printf("\n");
printf("\nThe free holes remaining are:");

for(i=0;i<n;++i)
{
if(flags[i]==0)
printf("%d\t",mem_part[i]);
}



}





void best_fit()
{
//printf("\nBEST FIT\n");
//sort_mem();
int small,i,j;
small=600;

for(i=0;i<5;++i)
{
	if(mem_part[i]<small)
	{
		small=mem_part[i];
	}
}


for(i=0;i<5;++i)
{
	if(mem_part[i]==small && pr_siz[i]<=mem_part[i] && flags[i]==0)
	{
    mem_part[i]=mem_part[i]-pr_siz[i];
	flags[i]=1;
	
	}

    else
    {
     
     printf("\nFailed to allocate partition for process %d size %d \n",pr_no[i],pr_siz[i]);
     flags[i]=0;
    }
}


fflush(stdout);
for(i=0;i<5;++i)
{

if(flags[i]==1)
{
printf("\nprocess %d allocated %d \n",pr_no[i],mem_part[i]);
}
}



printf("\nThe free holes remaining are:");
for(i=0;i<n;++i)
{
if(flags[i]==0)
printf("%d\t",mem_part[i]);
}


}




void worst_fit()
{
//printf("\nWORST FIT\n");
int i,j;
int large=0;
for(i=0;i<5;++i)
{
	if(mem_part[i]>large)
	{

	large=mem_part[i];
	//break;
	}
}

//fflush(stdout);
//printf("\nLargest memory partition=%d\t",large);

for(i=0;i<n;++i)
{
  if(mem_part[i]==large && flags[i]==0)
  {
    flags[i]=1;
    mem_part[i]=mem_part[i]-pr_siz[i];
    break;
  }




}




//printf("\nWorst fit loop2:");
for(i=0;i<n;++i)
{  
   if(pr_siz[i]<=mem_part[i] && flags[i]==0)
    {

     mem_part[i]=mem_part[i]-pr_siz[i];
     flags[i]=1;
    }

else
{
	printf("\nFailed to allocate partition for process %d size %d\n",pr_no[i],pr_siz[i]);
    flags[i]=0;
}
}





for(i=0;i<5;++i)
{

if(flags[i]==1)
{
printf("\nprocess %d allocated %d \n",pr_no[i],mem_part[i]);
}
}

printf("\nThe free holes are:");

for(i=0;i<5;++i)
{
	if(flags[i]==0)
	{
    printf("%d\t",mem_part[i]);
    }
}

}

int main()
{

input();
disp_init();
first_fit();

input();
disp_init();
best_fit();

input();
disp_init();
worst_fit();


return 0;
}


