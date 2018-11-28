/*
 * Subtract two numbers without using arithmetic operators
   Write a function subtract(x, y) that returns x-y where x and y are integers. 
   The function should not use any of the arithmetic operators (+, ++, –, -, .. etc).
 */

#include <stdio.h>

int 
main(void) {
    int a = 10;
    int b = 5;
    int carry = 0;
    while(b != 0) {
          carry = (~a) & b;
	  a = a^b;
	  b = carry<<1;
    }	    
    printf("%d\n",a);
    return 0;
}	
