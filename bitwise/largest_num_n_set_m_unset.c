/*
 * Link : https://www.geeksforgeeks.org/find-largest-number-n-set-m-unset-bits/
 */ 

#include <stdio.h>

int
main(void) {
    int set_bits = 4;
    int unset_bits = 1;
    int iter = unset_bits;
    int res = 0;
    for(;iter < (set_bits + unset_bits);iter++)
	res |= 1<<iter;
    printf("%d\n",res);
    return 0;    
}	
