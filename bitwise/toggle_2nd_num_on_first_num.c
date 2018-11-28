/*
 * For every set bit of a number toggle bits of other
  Given two integer numbers, whenever the bits of the first number is set i.e. 1,
  toggle the bits of the second number leaving the rest bits of the second number unchanged.
  Examples :

  Input: 2 5
  Output: 7
  2 is represented as 10 in binary and 5 
  is represented as 101. Hence toggling the 
  2nd bit of 5 from right, thus the new 
  number becomes 7 i.e. 111

  Input: 1 3
  Output: 2
 */

#include <stdio.h>

int
main(void) {
    int first_num = 231;
    int second_num = 999;
    printf("%d\n",first_num ^ second_num);
    return 0;
}	
