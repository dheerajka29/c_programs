/*
 * Swap all odd and even bits
   Given an unsigned integer, swap all odd bits with even bits. 
   For example, if the given number is 23 (00010111), it should 
   be converted to 43 (00101011). Every even position bit is swapped 
   with adjacent bit on right side (even position bits are highlighted 
   in binary representation of 23), and every odd position bit is swapped with adjacent on left side.
 */ 

#include <stdio.h>

int 
main(void) {
    unsigned int num = 2;
    unsigned int odd_temp = num<<1 & 0xAAAAAAAA;
    unsigned int even_temp = num>>1 & 0x55555555;
    printf("%u\n",odd_temp|even_temp); 
}	
