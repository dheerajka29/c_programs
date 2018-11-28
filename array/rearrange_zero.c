/*
 *
 * Move all zeroes to end of array
   Given an array of random numbers, Push all the zero’s of a given array to the end of the array. 
   For example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}.
   The order of all other elements should be same. Expected time complexity is O(n) and extra space is O(1).

   Example:

   Input :  arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
   Output : arr[] = {1, 2, 4, 3, 5, 0, 0};

   Input : arr[]  = {1, 2, 0, 0, 0, 3, 6};
   Output : arr[] = {1, 2, 3, 6, 0, 0, 0};
 *
 */

#include <stdio.h>
#include <string.h>

void
rearrange_arr(int * arr, int len) {
     int iter = 0, zero_index = 0;
     int temp;
     for (iter;iter < len; iter++) {
          if(arr[iter] != 0) {
	     temp = arr[iter];
	     arr[iter] = arr[zero_index];
	     arr[zero_index] = temp;
	     zero_index++;
	  }
     }	  
     for(iter = 0; iter < len; iter++)
	 printf("%d ",arr[iter]);    
}	

int 
main (void) {
     int arr[] = {1,2,0,4,3,0,5,0};
     int len = sizeof(arr)/sizeof(int);
     
     rearrange_arr(arr,len);
     /* V1 with extra O(1) space below.
     int temp_arr[len], index = 0, iter = 0;
     memset(temp_arr,0,sizeof(int)*len);
     for (iter;iter < len; iter++) {
          if (arr[iter] != 0) {
	      temp_arr[index] = arr[iter];
	      index++;
	  }	  
     }	     
     for(iter = 0 ;iter < len; iter++)
	 printf("%d ", temp_arr[iter]);
     printf("\n"); */
     return 0;    
}	
