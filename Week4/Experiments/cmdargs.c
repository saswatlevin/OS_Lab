#include <stdio.h>
int main(int argc,char **argv)
{

char *cmdargs[]={"grep","-I","-n","SUMIT","etc/passed",NULL};
execv("/bin/grep",cmdargs);
printf("execv error\n");
return 0;

}