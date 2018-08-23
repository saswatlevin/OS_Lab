#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
extern int errno;

int main()
{


int file_descriptor,read_flag,file_copy,write_flag,copy_flag,choice,ENTER,option;
char file_name[100],buffer[100],file_copy_name[100],read_write_buffer[100];
FILE *file_pointer,*file_copy_pointer;

//int *rw_ptr=read_write_buffer;
  printf("\nEnter filename from which you would like to copy\t");
  scanf("%s",file_name);

  file_descriptor=open(file_name,O_RDWR|O_APPEND|O_TRUNC);

 if(file_descriptor==-1)
 {
	perror("\nError ");
    printf("\nError Number= %d",errno);
	printf("\nThe File Does not exist. Would you like to create it ?[1/0]\n");
    scanf("%d",&choice);
	if(choice==1)
    {
    	file_descriptor=creat(file_name,O_RDWR|O_APPEND|O_TRUNC);
        printf("%s created",file_name);


    }
    else
    {
    	printf("\nCannot open file that does not exist. Exiting...\n");
    	exit(1);
    }    
 }





fflush(stdin);  

printf("\nEnter the name of the file which you want to copy to\t");
scanf("%s",file_copy_name);



	

file_copy=open(file_copy_name,O_RDWR|O_APPEND|O_TRUNC);

if(file_copy==-1)
{
	perror("\nError ");
	printf("\nError Number= %d",errno);
	
	printf("\nThe File Does not exist. Would you like to create it ?[1/0]\n");
    scanf("%d",&choice);
	if(choice==1)
    {
    	file_copy=creat(file_copy_name,O_RDWR|O_APPEND|O_TRUNC);
        printf("%s created",file_copy_name);
        //printf("\nEnter data in your file\t");
        //scanf("%s",buffer);

    }

   else
    {
    	printf("\nCannot open file that does not exist. Exiting...\n");
    	exit(1);
    }   

}

printf("\nWould you like to enter something into your file[1/0] ?");
scanf("%d",&ENTER);

if(ENTER==1)
{ 
	scanf("%s",buffer);
}



read_flag=read(file_descriptor,buffer,strlen(buffer));

printf("\nrf= %d",read_flag);

write_flag=write(file_descriptor,buffer,strlen(buffer));

printf("\nwf= %d",write_flag);

copy_flag=write(file_copy,buffer,strlen(buffer));

printf("\ncf= %d",copy_flag);



close(file_descriptor);
close(file_copy);




return 0;
}
