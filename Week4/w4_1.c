#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
   pid_t pid;
   int a;
  //Fork a child process
  pid=fork();
  printf("\nProcess_ID=%d",pid);
  
  if(pid<0)
  {
    //Error Ocurred
    fprintf(stderr,"\nFork Failed\n");
    return 1;
  }

  else if(pid>0)
  {
    //Child Process
    execlp("/bin/ls","ls",NULL);
  }

  else
  {
    //Parent will wait for the child to complete
    wait(NULL);
    printf("\nChild Complete\n");	
  }

  


  return 0;

}