/*
 * Link : https://www.geeksforgeeks.org/find-ones-complement-integer/
 */ 

#include <stdio.h>

int
one_complement( int num) {
   num |= num>>1;
   num |= num>>2;
   num |= num>>4;
   num |= num>>8;
   num |= num>>16;
   return num;
}	

int
main(void) {
    int num = 35;
    printf("%d\n",one_complement(num) ^ num);
    return 0;
}	
