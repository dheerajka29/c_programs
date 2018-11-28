/*
 * https://www.geeksforgeeks.org/toggle-first-last-bits-number/
 * Toggle first and last bits of a number
   Given a number n, the task is to toggle only first and last bits of a number

   Examples :

   Input : 10
   Output : 3
   Binary representation of 10 is
   1010. After toggling first and
   last bits, we get 0011.

   Input : 15
   Output : 6
 */

#include <stdio.h>

int
main(void) {
    unsigned int num = 10;
    //Find the position of last bit(msb)
    unsigned int temp = num, count = 0;
    while(temp){
        count++;
	temp = temp/2;
    }
    temp = 0;
    temp = (1<<(count-1)) | (1<<0);
    printf("%u\n",temp^num);    
    return 0;
}	
