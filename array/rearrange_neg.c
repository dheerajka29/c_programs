/*
 *Rearrange positive and negative numbers in O(n) time and O(1) extra space
  An array contains both positive and negative numbers in random order. 
  Rearrange the array elements so that positive and negative numbers are placed alternatively. 
  Number of positive and negative numbers need not be equal. If there are more positive numbers 
  they appear at the end of the array. If there are more negative numbers, they too appear in the end of the array.

  For example, if the input array is [-1, 2, -3, 4, 5, 6, -7, 8, 9], then the output should be [9, -7, 8, -3, 5, -1, 2, 4, 6]
 */
#include <stdio.h>
#include <stdbool.h>

int 
main(void) {
    //int arr[] = {-1,2,-3,4,5,6,-7,8,9};
    int arr[] = {2,-1};
    int len = sizeof(arr)/sizeof(int);
    //int cpy_arr[] = {9,8,6,5,4,2,-1,-3,-7}; // Assume we have the sorted array after merge_sort has been applied.
    int cpy_arr[] = {2,-1};
    /*
     * Step 1. Hunt for the index where the first negative element is.
     * If there is not any , return as array is already fine.
     */
    int neg_index = 0 , pos_index = 0;
    bool is_found = false;
    for(neg_index;neg_index < len; neg_index++) {
        if(cpy_arr[neg_index] < 0) {
	   is_found = true;	
	   break;
	}	
    }
    if(is_found == false) // No negative element present , return.
       return -1;
    // Find the first positive no. index . If there is not any , return .
    pos_index = len - neg_index - 1;
    if (pos_index < 0)
	return -1;   
    // Sorted array is decreasing , so start from its first index.
    int iter = 1, temp = 0;
    for (iter;iter < len && neg_index < len; iter+=2) {
	 //Break if you find negative element as it means array is already done .   
	 if(cpy_arr[iter] < 0) {
	    break;
         }
	 /*
	  * swap the alternate positive element with the negative element
	  *
	  */ 
	 temp = cpy_arr[iter];
	 cpy_arr[iter] = cpy_arr[neg_index];
	 cpy_arr[neg_index] = temp;
	 neg_index++; 
    }
    // Note : Above logic is manipulating the original array sequence
    for(iter = 0; iter < len; iter++)
        printf("%d ",cpy_arr[iter]);    
    return 0; 
}	  
