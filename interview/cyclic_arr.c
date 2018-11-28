/*
Given an array, cyclically rotate the array clockwise by one.

Examples:

Input:  arr[] = {1, 2, 3, 4, 5}
Output: arr[] = {5, 1, 2, 3, 4}
*/


#include <stdio.h>

int main (void) {
    int array[5]  = {2,0,3,3,4};
    int len = 5;
    int index = len - 1;
    int temp;
    for (index ; index >0; index--) {
	 temp = array[index - 1];
         array[index - 1] = array[index];
	 array[index] = temp;
   }
   for(index =0 ; index < len; index ++)
       printf("%d Element value is %d \n",index,array[index]);
}   
