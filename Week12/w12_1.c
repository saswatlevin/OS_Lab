#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *input(int size,int *queue)
{

queue=(int *)calloc(size,sizeof(int));
printf("\nEnter the cylinders to be traversed");
for(int i=0;i<size;++i)
scanf("%d",&queue[i]);
return queue;

}

/*int *sort(int size,int *arr) 
{ 
   int i, key, j; 
   for (i = 1; i < size; i++) 
   { 
       key = arr[i]; 
       j = i-1; 
  
       
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   } 
  return arr;
}*/ 

void display(int size,int *queue)
{
	printf("\nThe queue is:");
	for(int i=0;i<size;++i)
		printf("%d\t",queue[i]);
}


int subtract(int a,int b)
{
  return abs(b-a);
}




int fcfs(int size,int *queue)
{
int diff=0,sum=0;

for(int i=0;i<size;++i)
{
diff=queue[i+1]-queue[i];
sum=sum+abs(diff);
}
return sum;

}


int sstf(int size,int *queue)
{
	int sum=0;
  int *diff=(int *)calloc(size,sizeof(int));
    //queue=sort(size,queue);
    printf("\nAfter sorting queue:");
    display(size,queue);
    

for(int i=0;i<size;++i)
{
diff[i]=subtract(queue[i],queue[i+1]);

}

//diff=sort(size,diff);
for(int i=0;i<size;++i)
{

if(diff[i]<diff[i+1])
{
 sum=sum+diff[i]; 
}

}
return sum;
}

int scan(int size,int *queue)
{ 
  int *diff=(int *)calloc(size,sizeof(int));
	//int *flags=(int *)calloc(size,sizeof(int));
    
   
    int i,k,sum,a;
	for(i=0;i<size;++i){
		
      if(queue[i]<queue[i+1])
      {
         diff[i]=subtract(queue[i],queue[i+1]);
         sum+=diff[i];
         //flags[i]=1;
         if(queue[i]>queue[i+1])
         {
            k=i;
            do{
             a=subtract(queue[k],queue[size-1]);
             //flags[k]=1;
             sum=sum+a;
            printf("\nsum=%d",sum);
            }while(k=0);

         } 
      }

    }
  

    
  return sum;
}



void main()
{
int size=0,*Q,sum=0;
printf("\nEnter the size of the queue");
scanf("%d",&size);
Q=input(size,Q);
printf("\nThe queue is:");
display(size,Q);


sum=fcfs(size,Q);
printf("\nThe total distance traversed in fcfs=%d\t",sum);
sum=sstf(size,Q);
printf("\nThe total distance traversed in sstf=%d\t",sum);
sum=scan(size,Q);
printf("\nThe total distance traversed in scan=%d\t",sum);
}
