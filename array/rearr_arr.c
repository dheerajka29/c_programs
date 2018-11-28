/*
 * Rearrange an array such that ‘arr[j]’ becomes ‘i’ if ‘arr[i]’ is ‘j’ | Set 1
Given an array of size n where all elements are distinct and in range from 0 to n-1, change contents of arr[] so that arr[i] = j is changed to arr[j] = i.
Examples:

Example 1:
Input: arr[]  = {1, 3, 0, 2};
Output: arr[] = {2, 0, 3, 1};
Explanation for the above output.
Since arr[0] is 1, arr[1] is changed to 0
Since arr[1] is 3, arr[3] is changed to 1
Since arr[2] is 0, arr[0] is changed to 2
Since arr[3] is 2, arr[2] is changed to 3

Example 2:
Input: arr[]  = {2, 0, 1, 4, 5, 3};
Output: arr[] = {1, 2, 0, 5, 3, 4};

Example 3:
Input: arr[]  = {0, 1, 2, 3};
Output: arr[] = {0, 1, 2, 3};

Example 4:
Input: arr[]  = {3, 2, 1, 0};
Output: arr[] = {3, 2, 1, 0}; 
https://www.geeksforgeeks.org/rearrange-array-arrj-becomes-arri-j/
 */

#include <stdio.h>
#include <string.h>

/*
 * Below logic is not handling the cyclic loops.
 */ 
static void
rearrange_arr(int * arr, int len, int index,int * temp_arr) {
    while (index < len) {	
           int temp = arr[index];
	   if (temp_arr[index] == 1)
	       return;	   
	   temp_arr[index] = 1;
           rearrange_arr(arr,len,temp,temp_arr);
           arr[temp] = index;
     }	   
}	

int main(void) {
    int arr[] = {2, 0, 1, 4, 5, 3};
    int len = sizeof(arr)/sizeof(int);
    int temp_arr[len] ;
    memset(temp_arr,0,sizeof(int)*len);
    rearrange_arr(arr,len,0,temp_arr);
    int iter = 0;
    for(iter;iter<len;iter++)
	printf("%d ",arr[iter]);    
}	
