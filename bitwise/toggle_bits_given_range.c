/*
 * Link : https://www.geeksforgeeks.org/toggle-bits-given-range/
 *
 * Toggle bits in the given range
   Given a non-negative number n and two values l and r. 
   The problem is to toggle the bits in the range l to r in the binary representation of n,
   i.e, to toggle bits from the rightmost lth bit to the rightmost rth bit. A toggle operation flips a bit 0 to 1 and a bit 1 to 0.

   Constraint: 1 <= l <= r <= number of bits in the binary representation of n.

   Examples:

   Input : n = 17, l = 2, r = 3
   Output : 23
   (17)10 = (10001)2
   (23)10 = (10111)2
   The bits in the range 2 to 3 in the binary
   representation of 17 are toggled.

   Input : n = 50, l = 2, r = 5
   Output : 44
 */

#include <stdio.h>

int
main(void) {
    int num = 17;
    int l_bit = 3;
    int r_bit = 3;
    /* -1 since both bits need to be inclusive. */
    int l_temp = 1<<(l_bit-1);
    int r_temp = 1<<r_bit;
    l_temp = l_temp - 1;
    r_temp = r_temp - 1;
    int temp = l_temp ^ r_temp;
    printf("%d\n",temp^num);
    return 0;
}	
