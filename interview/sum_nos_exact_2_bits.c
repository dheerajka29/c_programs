/*
 * Sum of numbers with exactly 2 bits set
   Given a number n. Find sum of all number upto n whose 2 bits are set.

   Examples:

   Input : 10
   Output : 33
   3 + 5 + 6 + 9 + 10 = 33

   Input : 100
   Output : 762
 * https://www.geeksforgeeks.org/sum-numbers-exactly-2-bits-set/
 */

#include <stdio.h>

int
main(void) {
    unsigned int high_bit = 1;
    unsigned int n = 100; 
    unsigned int low_bit = 0;
    unsigned int temp_sum = 0;
    int count = 0;
    while(1<<high_bit < n) {
          while(low_bit < high_bit) {
                if(((1<<high_bit) + (1<<low_bit)) <= n) {
		   temp_sum += (1<<high_bit) + (1<<low_bit);	
		}
	        low_bit++;	
          }
	  low_bit = 0;
	  high_bit++;	  
    }
    printf("%u\n",temp_sum);
    return 0;    
}	
