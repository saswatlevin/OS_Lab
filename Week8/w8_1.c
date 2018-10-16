#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int buf[15],f,r;

sem_t mutex,full,empty,count;
int m,e;
void *produce(void *arg){
	
	int i;
	for(i=0;i<10;++i){
		//printf("\nproduce i=%d",i);
		//printf("\nInside Produce\n");
		sleep(rand()%2);
		sem_wait(&empty);
		sem_wait(&count);
		//e=sem_getvalue(&empty);
		//printf("\nempty_wait_prod=%d\n",e);
		sem_wait(&mutex);
	    //sem_getvalue(&mutex,&m);
		//printf("\nmutex_wait_prod=%d\n",m);
		printf("\nProduced item is %d\n",i);
		buf[(++r)%5]=i;
		//sleep(1);
		sem_post(&mutex);
		//sem_getvalue(&mutex,&m);
		//printf("\nmutex_post_prod=%d\n",m);
		sem_post(&full);
		//sem_getvalue(&full,&f);
		//sem_post(&mutex);
		//sem_post(&full);
		//printf("\nfull_Post_prod= %d\n",f);
	}
}

void *consume(void *arg){
	int item,i;
	for(i=0;i<10;++i){
		sleep(rand()%3);
		//printf("\nInside Consume\n");
		//printf("\nconsume i=%d",i);
		sem_wait(&full);
		//sem_getvalue(&full,&f);
		//printf("\nfull_wait_cons %d`\n",f);
		sem_wait(&mutex);
		item=buf[(++f)%15];
		printf("\nConsumed item is %d\n",item); 
		//sleep(1);
		sem_post(&mutex);
		sem_post(&count);
		//sem_getvalue(&mutex,&m);
		//printf("\nmutex_post_cons=%d\n",m);
		sem_post(&empty);
		//sem_getvalue(&empty,&e);
		//printf("\nempty_post_cons=%d\n",e);

		//sem_post(&mutex);
		//sem_post(&empty);

	}
}

int main()
{
	pthread_t tid1,tid2;
	sem_init(&mutex,0,1);
	sem_init(&full,0,1);
	sem_init(&empty,0,15);
	sem_init(&count,0,10);
	pthread_create(&tid1,NULL,produce,NULL);
	pthread_create(&tid2,NULL,consume,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
}