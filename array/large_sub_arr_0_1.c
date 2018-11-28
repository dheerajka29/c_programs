/*
 * Largest subarray with equal number of 0s and 1s
 *Given an array containing only 0s and 1s, find the largest subarray which contain equal no of 0s and 1s. Expected time complexity is O(n).
 *Examples:

 *Input: arr[] = {1, 0, 1, 1, 1, 0, 0}
 *Output: 1 to 6 (Starting and Ending indexes of output subarray)

 *Input: arr[] = {1, 1, 1, 1}
 *Output: No such subarray

 *Input: arr[] = {0, 0, 1, 1, 0}
 *Output: 0 to 3 Or 1 to 4
 * https://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/
 * https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //int arr[] = {1, 0, 1, 1, 1, 0, 0};
    int arr[] = {0,0,1,1,0};
    int len = sizeof(arr)/sizeof(int);
    /*
     * Approach 1 : Subsitute the 0 with -1 .
     * Now iterate in On2 such that total sum from a[i] to a[n]
     * is 0 as well as (i-n) is greater than max , then update the max
     * and continue.
     */
    int iter = 0;
    int sec_iter = 0;
    int max_cnt = 0, sum = 0; 
    for (iter;iter < len; iter++) {
         if(arr[iter] == 0) {
	    arr[iter] = -1;
	 }	 
    }
    for(iter = 0;iter < len; iter++){
        for(sec_iter = iter;sec_iter < len;sec_iter++){
	    sum = sum+arr[sec_iter];
	    if(sum == 0) {
	       max_cnt = max_cnt > (sec_iter - iter + 1) ? max_cnt : (sec_iter -iter + 1);
	    }	    
	}
        sum = 0;	
    }
    if (max_cnt == 0)
	printf("No pair found\n");   
    else	    
	printf("%d\n",max_cnt );
    return 0;   
    /*
     * Approach 2 : Calculate sum and store in the hash table along with index.
     * if sum is again found , then store the larger of index.
     * Finally , pull the index for sum 0 from hash.
     */  
}	
