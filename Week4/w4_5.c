#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main()
{
int file_descriptor,buffer_length;
char file_name[100],buffer[100];

printf("\nEnter filename\t");
scanf("%s",file_name);


file_descriptor=creat(file_name,S_IRWXU|O_RDWR|O_APPEND|O_TRUNC);


if(file_descriptor==-1)
{
	perror("\nCould not open file. Exiting...\n");
	exit(1);
}

buffer_length=sizeof(buffer);

printf("\nEnter something in your file\t");
scanf("%s",buffer);

read(file_descriptor,buffer,strlen(buffer));
write(file_descriptor,buffer,strlen(buffer));




close(file_descriptor);

return 0;


}
