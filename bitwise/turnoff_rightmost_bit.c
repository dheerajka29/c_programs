/*
 * https://www.geeksforgeeks.org/turn-off-the-rightmost-set-bit/
 */ 

#include <stdio.h>

/*
 * Another logic (num & num-1) gives the answer.
 */ 
int
main(void) {
    int num = 31;
    int m = 1;
    while(!(num&m)){
        m <<=1;
    }	    
    num = num ^ m;
    printf("%d\n",num);
    return 0;
}	
