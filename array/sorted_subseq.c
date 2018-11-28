/*
 *
 Find a sorted subsequence of size 3 in linear time
 Given an array of n integers, find the 3 elements such that a[i] < a[j] < a[k] and i < j < k in 0(n) time. If there are multiple such triplets, then print any one of them.
 Examples:

Input:  arr[] = {12, 11, 10, 5, 6, 2, 30}
Output: 5, 6, 30

Input:  arr[] = {1, 2, 3, 4}
Output: 1, 2, 3 OR 1, 2, 4 OR 2, 3, 4

Input:  arr[] = {4, 3, 2, 1}
Output: No such triplet
https://www.geeksforgeeks.org/find-a-sorted-subsequence-of-size-3-in-linear-time/
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main (void) {
    //int arr[] = {12, 11, 10, 5, 6, 2, 30};
    int arr[] = {4,3,2,1};
    int len = sizeof(arr)/sizeof(int);
    //Standard Approach 1 : Take an auxillary array and store the index of element greater than arr[curr_pos] , otherwise store -1.
    //		   Similarly , take another array and store the element smaller than arr[curr_pos] , otherwise store -1.
    int small_temp_arr[len];
    memset(small_temp_arr,0,sizeof(int)*len);
    int large_temp_arr[len];
    memset(large_temp_arr,0,sizeof(int)*len);
    int i = 0;
    int j = len-1;
    int small = arr[0];
    int large = arr[len-1];
    int min = 0;
    int max = len-1;
    for(i = 0;i < len;i++){
	if(arr[i] > small) {
	   small_temp_arr[i] = min;
        } else {
	   small_temp_arr[i] = -1;	
	   min = i;
	   small = arr[i];
        }		
    }	    
    for(j ;j > 0;j--){
	if(arr[j] < large) {
	   large_temp_arr[j] = max;	
        } else {
           large_temp_arr[j] = -1;
	   max = j;
	   large = arr[j];
	}		
    }
    for(i = 0;i < len;i++) {
        if(small_temp_arr[i] != -1 && large_temp_arr[i] != -1) {
	   printf("Triplets are %d %d %d \n",arr[small_temp_arr[i]],arr[i],arr[large_temp_arr[i]]);
	   return 0;
	}	
    }
    printf("No Triplets found\n");
    return 0;    
}	
