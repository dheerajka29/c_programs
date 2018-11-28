#include <stdio.h>

int 
rightmost_index(int num) {
    int count = 0;	
    while (num) {
	  if(num&1)
	     return count;	  
          num = num>>1;
	  count++; 
    }	    
    return -1;
}	

int 
main(void){
   int num = 2;
   printf("%d\n",rightmost_index(num));
   return 0;
}	
