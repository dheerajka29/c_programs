/*
 * Set the rightmost unset bit
   Given a non-negative number n. The problem is to set the rightmost unset bit in the binary representation of n. 
   If there are no unset bits, then just leave the number as it is.

   Examples:

   Input : 21
   Output : 23
   (21)10 = (10101)2
   Rightmost unset bit is at position 2(from right) as 
   highlighted in the binary representation of 21.
   (23)10 = (10111)2
   The bit at position 2 has been set.

   Input : 15
   Output : 15
   Link : https://www.geeksforgeeks.org/set-rightmost-unset-bit/
 */

#include <stdio.h>

int
main(void) {
    int num = 21;
    int count = 0;
    int temp = num;
    while(temp) {
          if((temp & 1) == 0){
	     num = num ^ (1<<count); 
	     break;
	  }	  
	  temp = temp>>1;
	  count++;
    }	    
    printf("%d\n",num);
    return 0;
}	
