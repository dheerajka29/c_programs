/*
 * https://www.geeksforgeeks.org/print-first-n-numbers-with-exactly-two-set-bits/
 * 
 * Given a number n, print first n positive integers with exactly two set bits in their binary representation.

   Examples :

   Input: n = 3
   Output: 3 5 6
   The first 3 numbers with two set bits are 3 (0011),
   5 (0101) and 6 (0110)

   Input: n = 5
   Output: 3 5 6 9 10 12
 */ 

#include <stdio.h>

int
main(void) {
    int num = 5;
    unsigned int low_bit = 0;
    unsigned int high_bit = 1;
    while(num > 0) {
          while(low_bit < high_bit) {
	        printf("%u\n",(1<<high_bit) + (1<<low_bit));
		low_bit++;
		num--;
	  }
 	  low_bit = 0;	  
	  high_bit++; 
    }	    
    return 0;
}	
