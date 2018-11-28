/*
 * https://www.geeksforgeeks.org/?p=576/
 * Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.
 */ 

#include <stdio.h>

int max(int a , int b) {
    if (a > b)
	return a;
    return b;    
}	

int main(void) {
    int arr[] = {-2,-3,-1,-2,-3};
    int len = sizeof(arr)/sizeof(int); 
    int max_sum = arr[0];
    int curr_max = arr[0];
    int iter = 1;
    for(iter ;iter < len;iter++) {
	/*
	 * Start from index 1 and add the previous one. 
	 * Whichever is greatest , store it.
	 * This step will judge if it is continuation of previous chain[in case of addition to previous chain] or a new one[when index itself is stored]. 
	 */     
	curr_max = max(arr[iter],curr_max + arr[iter]);
        max_sum = max(curr_max,max_sum);	
    }
    printf("%d\n",max_sum);
    return 0;    
}	
