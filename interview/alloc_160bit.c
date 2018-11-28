#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int * ptr = malloc(40*sizeof(int));
   //set 97th bit
   char * a = ptr;
   int n = 24;
   while(n) {
         a++;
	 n--;
   }	   
   if((*a) && 1<<1) {
      printf("Bit is set\n");
   }	   
}	
