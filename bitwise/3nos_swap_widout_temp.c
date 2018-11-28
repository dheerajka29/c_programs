/*
 * Swap three variables without using temporary variable
   Given three variables, a, b and c, swap them without temporary variable.

   Example :

   Input  : a = 10, b = 20 and c = 30
   Output : a = 30, b = 10 and c = 20
 */ 
#include <stdio.h>

int
main(void) {
    int a = 10, b = 20,c = 30;    
    a = a^b^c;
    b = b^c^a; // It has value of a.
    c = c^a^b; //It has value of b .
    a = a^b^c; //It has value of c.
    printf("Output : a : %d b : %d c : %d\n",a,b,c);
    return 0; 
}	
