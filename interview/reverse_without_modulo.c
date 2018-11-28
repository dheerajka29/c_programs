#include <stdio.h>

/*
 *Program to reverse the 
 * given bits.
 *
 */ 
int main(void) {
    unsigned int num = 3;
    int iter;
    unsigned int new_no = 0;
    int no_bytes = sizeof(num)*8;
    for (iter = 0 ;iter < no_bytes ; iter++) {
         if(num & 1<<iter) {
	    new_no |= 1 << ((no_bytes - iter) -1 ); 
	 }	 
    }
    printf("reverse is %u",new_no);    
}	
