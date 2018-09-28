#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 512

struct my_msg_st{
	long int my_msg_type;
    char some_text[4];
};



void isPalindrome(char str[])
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = strlen(str) - 1;
 
    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            printf("%s is Not Palindrome", str);
            return;
        }
    }
    printf("%s is palindrome", str);
}


int main()
{
	int running=1;
	struct my_msg_st some_data;
	int msgid;
	char buffer[BUFSIZ];

    msgid=msgget((key_t)1234,0666|IPC_CREAT);
    if(msgid==-1)
    {
    	fprintf(stderr,"msgget failed with error%d\n",errno);
    	exit(EXIT_FAILURE);
    }

char ch;
while(running){
	printf("\nEnter a 4-digit number");
	fgets(buffer,BUFSIZ,stdin);
	some_data.my_msg_type=1;
	strcpy(some_data.some_text,buffer);
	/*for(int i=0;i<4;++i)
	{
		some_data.some_text[i]=buffer[i];
	}*/

   if(msgsnd(msgid,(void*)&some_data,4,0)==-1)
   {
   	   fprintf(stderr,"msgsnd failed\n");
   	   exit(EXIT_FAILURE);
   }

   

if(strncmp(buffer,"0",3)==0)
{
  running=0;
}

}
exit(EXIT_SUCCESS);
}


