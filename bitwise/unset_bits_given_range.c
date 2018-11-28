/*
 * Link : https://www.geeksforgeeks.org/unset-bits-given-range/
 * Unset bits in the given range
   Given a non-negative number n and two values l and r. The problem is to unset the bits in the range 
   l to r in the binary representation of n, i.e, to unset bits from the rightmost lth bit to the rightmost rth bit.

   Constraint: 1 <= l <= r <= number of bits in the binary representation of n.

   Examples:

   Input : n = 42, l = 2, r = 5
   Output : 32
   (42)10 = (101010)2
   (32)10 = (100000)2
   The bits in the range 2 to 5 in the binary
   representation of 42 have been unset.

   Input : n = 63, l = 1, r = 4
   Output : 48
 */
#include <stdio.h>

int
main(void) {
    unsigned int num = 63;
    unsigned int l_bit = 1;
    unsigned int r_bit = 4;
    /*
     *In below step , following things will happen :
     * 1. we are going to have unset bits under the range and all the other bits will be set.
     */ 
    unsigned int temp = ~(((1<<l_bit-1) - 1) ^ ((1<<(r_bit))-1));
    printf("%u\n",temp & num);
    return 0;
}	
