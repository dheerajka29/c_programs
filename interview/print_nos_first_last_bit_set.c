/*
 * https://www.geeksforgeeks.org/print-numbers-first-last-bits-set-bits/
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
    int n = 10;
    if( n <= 0)
        return;	    
    unsigned int shift_bit = 1;
    unsigned int temp = 0;
    printf("%u\n",shift_bit);
    while(1) {
         shift_bit <<= 1;
	 temp = shift_bit ^ 1;
	 if(temp > n)
	    break;
	 printf("%u\n",temp);	 
    }	    
    return 0;
}	
