/*
 *Rearrange an array in maximum minimum form | Set 1
 *Given a sorted array of positive integers, rearrange 
 *the array alternately i.e first element should be maximum value, second minimum value, third second max, fourth second min and so on.

 *Examples:

 *Input  : arr[] = {1, 2, 3, 4, 5, 6, 7} 
 *Output : arr[] = {7, 1, 6, 2, 5, 3, 4}

 *Input  : arr[] = {1, 2, 3, 4, 5, 6} 
 *Output : arr[] = {6, 1, 5, 2, 4, 3}
 *Expected time complexity is O(n).
 * https://www.geeksforgeeks.org/rearrange-array-maximum-minimum-form/
 */

/* 
 * DJ : Simple method is to take an auxillary array and arrange the elements starting from max in even positions. Then arrange the next elements
 * in odd positions.
 * Take high-low pointers and arrange them in auxillary array.
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static void
rearrange_arr(int * arr, int * aux_arr, int len) {
   bool is_index_even = true;
   int even_index = 0;
   int odd_index = len-1;
   int index = 0;
   for (index; index < len; index++) {
        if(index%2 == 0) {
	   aux_arr[index] = arr[odd_index];
   	   odd_index--;	   
	} else {
           aux_arr[index] = arr[even_index];
	   even_index++;
	}		
	   	
   }	   
}

static void
print_arr(int * arr, int len) {
    int iter = 0 ;
    for (iter;iter < len; iter++)
	 printf("%d ",arr[iter]);
    printf("\n");   
}	

int main (void) {
    int arr[] = {3,4,5,6,7,8};
    int len = sizeof(arr)/sizeof(int);
    int aux_arr[len];
    memset(aux_arr,0,sizeof(int)*len);
    rearrange_arr(arr,aux_arr,len);
    print_arr(aux_arr,len);
}	
