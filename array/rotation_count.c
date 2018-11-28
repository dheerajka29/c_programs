/*
 Consider an array of distinct numbers sorted in increasing order. 
 The array has been rotated (clockwise) k number of times. Given such an array, find the value of k.

 Examples:

 Input : arr[] = {15, 18, 2, 3, 6, 12}
 Output: 2
 Explanation : Initial array must be {2, 3,
 6, 12, 15, 18}. We get the given array after 
 rotating the initial array twice.

 Input : arr[] = {7, 9, 11, 12, 5}
 Output: 4

 Input: arr[] = {7, 9, 11, 12, 15};
 Output: 0
*/

#include <stdio.h>
#include <stdbool.h>

bool
is_array_rotated(int * arr , int len) {
    int iter = 0;
    for (iter; iter < len - 1; iter++)
	 if (arr[iter] > arr[iter+1])
	     return true;	 
    return false;
}	

int main (void) {
    int arr[] = {7,9,11,12,15};
    int len = sizeof(arr)/sizeof(int);
    printf("Array is %s\n",is_array_rotated(arr,len) ? "Rotated":"Not Rotated");
    return 0;
}	
