/*
 * Check a number is odd or even without modulus operator
   Given a number, check whether it is even or odd.

   Examples :

   Input: n = 11
   Output: Odd

   Input: n = 10
   Output: Even
 */

#include <stdio.h>

int
main(void) {
    int n = 212;
    if(n&1)
       printf("No is odd\n");
    else
       printf("No is even\n");
    return 0;    
}	
