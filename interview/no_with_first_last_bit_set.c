/*
 * Print numbers having first and last bits as the only set bits
   Given a positive integer n. The problem is to print numbers in the range 1 to n having first and last bits as the only set bits.

   Examples:

   Input : n = 10
   Output : 1 3 5 9
   (1)10 = (1)2.
   (3)10 = (11)2.
   (5)10 = (101)2.
   (9)10 = (1001)2
 */

#include <stdio.h>

int
main(void) {
    unsigned int n = 10;
    unsigned int num = 1;
    unsigned int temp = 1;
    while(1) {
        temp <<=1; 
	num = temp ^ 1;
        if(num > n )
	   break;
	printf("%u\n",num);	
    }	    
    return 0;
}	
