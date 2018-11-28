/*
 * Find XOR of two number without using XOR operator
   Given two integers, find XOR of them without using XOR operator, i.e., without using ^ in C/C++.

   Examples :

   Input:  x = 1, y = 2
   Output: 3

   Input:  x = 3, y = 5
   Output: 6
   Link : https://www.geeksforgeeks.org/find-xor-of-two-number-without-using-xor-operator/
 */ 

#include <stdio.h>

int
main(void) {
    unsigned int a = 3;
    unsigned int b = 5;
    printf("%u\n",(a|b) & (~a | ~b));
    return 0;
}	
