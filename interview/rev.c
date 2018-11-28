#include <stdio.h>

int main(void) {
    unsigned int num =2147483648;
    int size = sizeof(int)*8 ;
    int index =0;
    unsigned int rev_no = 0;
    while(num) {
          rev_no = rev_no<<1;
	  if (num & 1<<0) {
	      rev_no |= 1;
	  }
          num = num>>1;	  
	  index++;
    }	  
    rev_no = rev_no<<(size-index);
    printf("%u",rev_no);
}	
