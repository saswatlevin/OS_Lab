#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
execlp("/bin/cat","cat f1.txt","NULL");
return 0;	
}