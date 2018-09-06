#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int fib[24],n;
void *child_thread(void *param)
{
	int i;
	fib[0]=0;
	fib[1]=1;
	for(i=2;i<24;++i)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
}

int main(int argc,char **argv[])
{
	pthread_t thread;
	pthread_attr_t attributes;
	pthread_attr_init(&attributes);
	pthread_create(&thread,0,&child_thread,0);
	int i=0;
	pthread_join(thread,0);
	printf("\nIn main Thread");
	printf("\nEnter limit\t");
	scanf("%d",&n);
	printf("\n%d\n",fib[0]);
	printf("\n%d\n",fib[1]);
	for(i=2;i<n;++i)
		printf("\n%d\n",fib[i]);

	return 0;
    
}