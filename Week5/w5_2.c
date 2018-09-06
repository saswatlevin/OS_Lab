#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int fib[24],n;
void *child_thread(void *param)
{
	int i;
	int x=(int)param;
	
	for(i=0;i<=n;++i)
	{   if(fib[i]>0)
		  x=x+fib[i];
	}
    printf("\nx=%i",x);
    
    //printf("\nx_param=%i",x);
    
    //printf("\nId in child_thread=%i",(int)param);
    return (void *)x ;
}

int main(int argc,char **argv[])
{
	pthread_t thread;
	int i=0,ret_val;
	printf("\nIn main Thread");
	printf("\nEnter limit\t");
	scanf("%d",&n);
	printf("\nEnter the array");
    for(i=0;i<n;++i)
    	scanf("%d",&fib[i]);
	//printf("\n%d\n",fib[1]);
	//for(i=0;i<n;++i)
     pthread_create(&thread,0,&child_thread,0);	
   
	 pthread_join(thread,(void**)&ret_val);
	 printf("\nSum=%i",ret_val);
	
}