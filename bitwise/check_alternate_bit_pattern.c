/*
 * Check if a number has bits in alternate pattern | Set 1
   Given an integer n > 0, the task is to find whether this integer 
   has an alternate pattern in its bits representation. For example- 5 has an alternate pattern i.e. 101.
   Print “Yes” if it has an alternate pattern otherwise “No”. Here alternate pattern can be like 0101 or 1010.

   Examples:

   Input :  15
   Output :  No
   Explanation: Binary representation of 15 is 1111.

   Input :  10
   Output :  Yes
   Explanation: Binary representation of 10 is 1010.
 */

#include <stdio.h>

int
main(void) {
    int num = 10;
    if(num == 0)
       return -1;
    int prev = -1;
    int curr = 0;
    while(num) {
        curr = 1 & num;
	if(curr == prev) {
	   printf("Pattern not found\n");	
	   return -1;	
	}   
        num >>=1;
	prev = curr;	
    }
    printf("Pattern found\n");
    return 0;    
}	
