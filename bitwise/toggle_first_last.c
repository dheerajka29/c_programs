/*
 * https://www.geeksforgeeks.org/toggle-bits-number-expect-first-last-bits/
 */

#include <stdio.h>

int
unset_num(int n) {
    if (n == 0)
	return n;
    n |= n>>1;
    n |= n>>2;
    n |= n>>4;
    n |= n>>8;
    n |= n>>16;
    n +=1;
    n >>=1;
    return n^1 ; 
}	

int
main(void) {
    int num = 355;
    printf("%d\n",unset_num(num) ^ num );
    return 0;
}	
