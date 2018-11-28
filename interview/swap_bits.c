/*
 * Swap bits in a given number
   Given a number x and two positions (from right side) in binary representation of x, 
   write a function that swaps n bits at given two positions and returns the result. It is also given that the two sets of bits do not overlap.
 * https://www.geeksforgeeks.org/swap-bits-in-a-given-number/
 */
#include <stdio.h>

int 
main(void) {
   int num = 28;
   int pos_one = 0;
   int pos_two = 3;
   int no_bits = 2;
   int temp_one = ((1<<no_bits) - 1) & num>>pos_one;
   int temp_two = ((1<<no_bits) - 1) & num>>pos_two;
   int xor = temp_one ^ temp_two;
   num = num ^ xor<<pos_one;
   num = num ^ xor<<pos_two;
   printf("%d\n",num);
   return 0;
}	
