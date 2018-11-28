/*
 * https://www.geeksforgeeks.org/count-minimum-bits-flip-xor-b-equal-c/
 * Count minimum bits to flip such that XOR of A and B equal to C
Given a sequence of three binary sequences A, B and C of N bits. Count the minimum bits required to flip in A and B such that XOR of A and B is equal to C. For Example :

Input: N = 3
       A = 110
       B = 101
       C = 001
Output: 1
We only need to flip the bit of 2nd position
of either A or B, such that A ^ B = C i.e.,
100 ^ 101 = 001
 */

#include <stdio.h>

int
main(void) {
    int n = 3;
    int a = 6;
    int b = 5;
    int c = 1;
    int temp = a^b;
    int count = 0, iter = 0;
    temp = temp ^ c;
    for(;iter < n;iter++) {
        if(temp & 1)
	   count++;
	temp>>=1;	
    }	   
    printf("%d\n",count);
    return 0; 
}	
