/*
 * Given a number, the task is to toggle bits of the number except the first and the last bit.
 * https://www.geeksforgeeks.org/toggle-bits-number-expect-first-last-bits/
 *
 Examples:

 Input : 10
 Output : 12
 Binary representation:- 1 0 1 0
 After toggling first and last : 1 1 0 0

 Input : 9
 Output : 15
 Binary representation : 1 0 0 1
 After toggling first and last : 1 1 1 1
 *
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
    unsigned iter = 0;
    temp = 0;
    //Logic to set the middle bits.
    for (iter = 1;iter < count-1; iter++){
         temp |= 1<<iter; 
    }
    printf("%u\n",temp^num);    
    return 0;
}	
