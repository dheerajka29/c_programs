/*
 * Link : https://www.geeksforgeeks.org/check-one-numbers-ones-complement/
 *
 * Input : a = 10, b = 5
   Output : Yes
   (10)10 = (1010)2
   1's complement of 10 is
   = (0101)2 = (101)2 = (5)10

   Input : a = 1, b = 14
   Output : Yes
   (14)10 = (1110)2
   1's complement of 14 is
   = (0001)2 = (1)2 = (1)10
 */

#include <stdio.h>

int
main(void) {
    int num = 10;
    int b = 5;
    if (num & b == 0)
	printf("Both are 1s complement\n");
    else
	printf("Not 1s complement\n");
    return 0;    
}	


