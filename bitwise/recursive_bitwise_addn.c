/*
 * https://www.geeksforgeeks.org/bitwise-recursive-addition-two-integers/
 */ 

#include <stdio.h>

int 
sum_recursive(unsigned int a ,unsigned int b){
    unsigned int temp = a & b; //Calculation of carry
    unsigned int res = a^b;  // Calculation of Sum
    temp <<=1; //Shift the carry 1 bit upwards.
    if(temp == 0)
       return res; //Final result.
    sum_recursive(res,temp);    
}	

int 
main(void) {
   unsigned  int a = 15;
    unsigned int b = 34;
    printf("%u\n",sum_recursive(a,b));
    return 0;
}	
