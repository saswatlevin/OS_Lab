#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

void main()
{

int file_pointer,file_descriptor,length;

char source_file_name[100],destination_file_name[100],buffer[100];

printf("\nEnter source file name\t");

scanf("%s",source_file_name);

file_descriptor=open(source_file_name,O_RDWR);

if(file_descriptor==-1)
{

printf("\nFile not created. Exiting");

exit(1);	

}

printf("\nEnter destination file name\t");

scanf("%s",destination_file_name);

file_pointer=open(destination_file_name,O_RDONLY);

if(file_pointer==-1)
{

printf("\nFile not created. Exiting");

exit(1);	

}


read(file_pointer,buffer,sizeof(buffer));

length=strlen(buffer);

printf("The file contains:%s\n",buffer);

close(file_pointer);

write(file_descriptor,buffer,length);

close(file_descriptor);

}
