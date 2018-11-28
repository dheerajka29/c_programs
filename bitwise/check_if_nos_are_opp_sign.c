/*
 * Detect if two integers have opposite signs
   Given two signed integers, write a function that returns true if the signs of given integers are different,
   otherwise false. For example, the function should return true -1 and +100, and should return false for
   -100 and -200. The function should not use any of the arithmetic operators
   Link : https://www.geeksforgeeks.org/detect-if-two-integers-have-opposite-signs/
 */

#include <stdio.h>
#include <stdbool.h>

bool
is_opposite(int x, int y) {
    return (x^y < 0);
}	
int 
main(void) {
   int x = 31;
   int y = -31;
   printf("%s\n",is_opposite(x,y) ? "Yes":"No");
   return 0;
}	
