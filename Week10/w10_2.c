#include <stdio.h>
#include <stdlib.h>
//#define TOTAL_BYTES 256
//#define TOTAL_PAGES 8
//#define PAGE_SIZE   32
//#define PAGE_MARKER 1

//int memory[TOTAL_BYTES];
//int byte_count=0;
//int page_count=0;

/*void init_mem()
{
int i;

for(i=0;i<TOTAL_PAGES;i=i+PAGE_SIZE)
{
	memory[i]=PAGE_MARKER;
    
}

}*/

void get_num_offset(int l_addr)
{

int pg_no,offset; 
int temp;
if(l_addr%32==0)
{
	pg_no=l_addr/32;
    offset=0;
    printf("\nPage number=%d\t,offset=%d\t",pg_no,offset);

}

else if(l_addr%32!=0)
{ 
  pg_no=l_addr/32;
  offset=l_addr%32;
  //pg_no=l_addr+offset;
  printf("\nPage number=%d",pg_no);
  printf("\nOffset=%d",offset);
}	

}

void main()
{
	int l_addr;
    //int p_no;
    int p_offset;
    printf("\nEnter the logical address");
    scanf("%d",&l_addr);
    get_num_offset(l_addr);
}