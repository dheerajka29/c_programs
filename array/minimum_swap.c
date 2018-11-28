/*
Minimum swaps required to bring all elements less than or equal to k together
Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring all the numbers less than or equal to k together.

Input:  arr[] = {2, 1, 5, 6, 3}, k = 3
Output: 1

Explanation: 
To bring elements 2, 1, 3 together, swap 
element '5' with '3' such that final array
will be-
arr[] = {2, 1, 3, 6, 5}

Input:  arr[] = {2, 7, 9, 5, 8, 7, 4}, k = 5
Output: 2
*/

#include <stdio.h>

int 
main (void) {
    int arr[] = {2, 7, 9, 5, 3, 11, 4};
    int len = sizeof(arr)/sizeof(len);
    int key = 5, min = 0, temp_min = 0;
    //Step 1 : find no. of elements less than key.
    int iter ,count = 0,iter_j;
    for(iter = 0;iter < len; iter++) {
        if( arr[iter] <= key)
	   count++;	
    }	  
    for (iter = 0; iter < count; iter++)
	 if(arr[iter] > key)
	    min++;
    temp_min = min;
    for (iter = 1,iter_j = count ; iter_j < len,iter < len; iter_j++,iter++) {
	 if (arr[iter-1] > key )
	     min--;
	 if (arr[iter_j] > key)
	     min++;
	 if (min < temp_min) {
	     temp_min = min;
	 }	 
    }
    printf("Minimum swap required are %d\n",temp_min);    
    return 0;	    
}	
