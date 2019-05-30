/*
 * https://www.geeksforgeeks.org/rearrange-array-arri/
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
rearrange_arr(int * arr, int value_to_arr,int prev_index) {
    if(arr[value_to_arr] == -1) {
       arr[value_to_arr] = value_to_arr	;
       if(arr[prev_index] != prev_index)
	  arr[prev_index] = -1;     
       return;    
    }
    if(arr[value_to_arr] == value_to_arr)
       return;	    
    int temp = arr[value_to_arr];
    arr[value_to_arr] = value_to_arr;
    rearrange_arr(arr,temp,value_to_arr);    
}	

int
main(void) {
   int arr[] = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8,
              11, 10, 9, 5, 13, 16, 2, 14, 17, 4};
   int len = sizeof(arr)/sizeof(arr[0]);
   int iter = 0;
   for(;iter < len;iter++) {
       if(arr[iter] == -1)
        continue;
       if(arr[iter] == iter)
        continue;
       rearrange_arr(arr ,arr[iter],iter);
   }
   for(iter = 0;iter < len;iter++) 
	printf("%d ",arr[iter]);
   printf("\n");   
   return 0;   
}	
