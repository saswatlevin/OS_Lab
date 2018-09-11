#include <stdio.h>
#include <pthread.h>
int n=0;
/*

    #include<stdio.h>
     
    main()
    {
       int n, i = 3, count, c;
     
       printf("Enter the number of prime numbers required\n");
       scanf("%d",&n);
     
       if ( n >= 1 )
       {
          printf("First %d prime numbers are :\n",n);
          printf("2\n");
       }
     
       for ( count = 2 ; count <= n ;  )
       {
          for ( c = 2 ; c <= i - 1 ; c++ )
          {
             if ( i%c == 0 )
                break;
          }
          if ( c == i )
          {
             printf("%d\n",i);
             count++;
          }
          i++;
       }         
     
       return 0;
     
*/

void *prime_generator(void *param)
{
   int i=3, count, c;
     
       
       if ( n >= 1 )
       {
          printf("First %d prime numbers are :\n",n);
          printf("2\n");
       }
     
       for ( count = 2 ; count <= n ;)
       {
          for ( c = 2 ; c <= i - 1 ; c++ )
          {
             if ( i%c == 0 )
                break;
          }
          if ( c == i )
          {
             printf("%d\n",i);
             count++;
          }
          i++;
       }         	
}

int main()
{
//prime_generator();
int ret_val=0;
pthread_t thread;

printf("Enter the number of prime numbers required\n");
scanf("%d",&n);
pthread_create(&thread,0,&prime_generator,0);	
pthread_join(thread,(void**)&ret_val);     

return 0;
}