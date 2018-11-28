/*
 * https://www.geeksforgeeks.org/how-to-turn-off-a-particular-bit-in-a-number/
 * Given a number n and a value k, turn of the k’th bit in n.
Examples:

Input:  n = 15, k = 1
Output: 14

Input:  n = 15, k = 2
Output: 13

Input:  n = 15, k = 3
Output: 11

Input:  n = 15, k = 4
Output: 7

Input:  n = 15, k >= 5
Output: 15
 */ 

#include <stdio.h>

int
main(void) {
    int num = 15;
    int k = 5;
    if(num & 1<<(k-1)){
       printf("%d\n",num ^ 1<<(k-1));
    } else {
       printf("%d\n",num);
    }	    
    return 0;
}	
