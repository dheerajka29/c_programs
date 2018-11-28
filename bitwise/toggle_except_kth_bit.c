/*
 * https://www.geeksforgeeks.org/toggle-bits-number-except-k-th-bit/
 * Given a positive (or unsigned) integer n, write a function to toggle all the bits except k-th bit. Here value of k starts from 0 (zero) and from right.

   Examples:

   Input : n = 4294967295, k = 0
   Output : 1
   The number 4294967295 in 32 bits has all bits
   set.  When we toggle all bits except last bit,
   we get 1.

   Input  :  n = 1, k = 1
   Output : 4294967292
   4294967262 has all bits toggled except second
   bit from right.
 */
#include <stdio.h>

int
main(void) {
    unsigned int n = 1;
    unsigned int k = 1;
    unsigned int temp = 1<<k;
    temp = ~temp;
    printf("%u\n",temp ^ n);
    return 0;
}	
