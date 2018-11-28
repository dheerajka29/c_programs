/*
 * https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/
 * Maximum circular subarray sum
   Given n numbers (both +ve and -ve), arranged in a circle, fnd the maximum sum of consecutive number.
   Examples:

   Input: a[] = {8, -8, 9, -9, 10, -11, 12}
   Output: 22 (12 + 8 - 8 + 9 - 9 + 10)

   Input: a[] = {10, -3, -4, 7, 6, 5, -4, -1} 
   Output:  23 (7 + 6 + 5 - 4 -1 + 10) 

   Input: a[] = {-1, 40, -14, 7, 6, 5, -4, -1}
   Output: 52 (7 + 6 + 5 - 4 - 1 - 1 + 40)
 */

#include <stdio.h>

static int
max(int a, int b) {
    if (a > b)
	return a;
    return b;    
}	

static int
kadane_algo(int * arr, int len) {
    int final_max = arr[0];
    int temp_max = arr[0];
    int iter ;
    for(iter = 1;iter < len; iter++) {
	temp_max = max(temp_max+arr[iter],arr[iter]);
        final_max = max(temp_max,final_max);	
    }
    return final_max;    
}	

static int
max_sum(int * arr, int len) {
    int temp_sum_1 = 0;
    int arr_sum = 0;
    int temp_sum_2 = 0;
    int iter = 0;
    temp_sum_1 = kadane_algo(arr,len);
    for(iter;iter<len;iter++) {
	arr_sum += arr[iter];    
	arr[iter] = -arr[iter]; 
    }
    temp_sum_2 = arr_sum + kadane_algo(arr,len);
    return max(temp_sum_1,temp_sum_2);    
}	

int 
main(void) {
     int arr[] = {8, -8, 9, -9, 10, -11, 12};
     int len = sizeof(arr)/sizeof(int);
     printf("%d\n",max_sum(arr,len));
     return 0;
}	
