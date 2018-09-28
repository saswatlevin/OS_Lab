#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msg_st{
	long int my_msg_type;
	char some_text[BUFSIZ];
};



/*int isPalindrome(char str[])
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = strlen(str) - 1;
    
    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            //printf("%s is Not Palindrome", str);
        
            return 0;     
        }
    }
    
    return 1;
}
*/

int main()
{
	int running=1;
	int msgid;
	struct my_msg_st some_data;
	long int msg_to_receive=0;
	char ch;
	char buffer[BUFSIZ];
	int result=-1;
	msgid=msgget((key_t)1234,0666|IPC_CREAT);
	if(msgid==-1)
	{
		fprintf(stderr,"msgget failed with error:%d\n",errno);
		exit(EXIT_FAILURE);
	}

while(running){
	

	if(msgrcv(msgid,(void*)&some_data,BUFSIZ,msg_to_receive,0)==-1){
		fprintf(stderr,"msgrecv failed with error:%d\n",errno);
		exit(EXIT_FAILURE);
	}

  
   // Start from leftmost and rightmost corners of str
    
    
    // Keep comparing characters while they are same
    int l = 0;
    int h = strlen(some_data.some_text) - 1;
    while (h > l)
    {
        if (some_data.some_text[l++] != some_data.some_text[h--])
        {
            printf("It is Not a Palindrome");
            exit(0);
            //return 0;     
        }
    printf(" it is a palindrome");
    }



  //result=isPalindrome(buffer);
 

  printf("\nYou wrote some number %s",some_data.some_text);
  
  /*printf("\nWould you like to end the buffer?(y/n)");
  scanf("%c",&ch);
if(ch=='Y'||ch=='y')
{
  running=0;
}*/

  if(strncmp(buffer,"0",3)==0)
{
  running=0;
}

}
if(msgctl(msgid,IPC_RMID,0)==-1)
{
	fprintf(stderr,"msgctl(IPC_RMID) failed\n");
	exit(EXIT_FAILURE);
}

exit(EXIT_SUCCESS);

}