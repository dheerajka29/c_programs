/*
 * Link : https://www.geeksforgeeks.org/swap-every-two-bits-bytes/
 */ 

#include <stdio.h>

int
main(void) {
    unsigned int num = 231;
    unsigned int temp = 0xcccccccc; //Mask to be used when no. is shifted 2 times to left.
    printf("%u\n",(num<<2 & temp) | (num>>2 & (0xffffffff - temp)));
    return 0;
}	
