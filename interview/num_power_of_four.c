/*
 * https://www.geeksforgeeks.org/find-whether-a-given-number-is-a-power-of-4-or-not/
 * Find whether a given number is a power of 4 or not
   Given an integer n, find whether it is a power of 4 or not.

   Example :

   Input : 16
   Output : 16 is a power of 4

   Input : 20
   Output : 20 is not a power of 4
 */

#include <stdio.h>

int
main(void) {
    unsigned int num = 16;
    if (!(num & (num-1)) && (num & 0x55555554)){
	printf("no is power of 4\n");    
        return 1;
    }		    
    return 0;    
}	
