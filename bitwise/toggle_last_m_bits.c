/*
 * Link : https://www.geeksforgeeks.org/toggle-last-m-bits/
 * Input : n = 21, m = 2
   Output : 22
   (21)10 = (10101)2
   (22)10 = (10110)2
   The last two bits in the binary
   representation of 21 are toggled.

   Input : n = 107, m = 4
   Output : 100
 */

#include <stdio.h>

int
main(void) {
    int n = 21;
    int pos = 2;
    /*
     * 1 << pos will set the pos bit . subtraction from 1 will set (pos-1)bits. 
     */ 
    printf("%d\n",n ^ ((1<<pos) - 1));
    return 0; 
}	
