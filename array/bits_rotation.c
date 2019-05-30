#include <stdio.h>
#include <string.h>

int
main(void) {
   char a = 'B';
   int len = sizeof(char)*8;
   int shift = 2;
   if(shift > len)
      return -1;	   
   char b = a<<shift;
   a = b | (a>>(len-shift));
   return 0;
}	
