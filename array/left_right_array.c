/*
 *https://www.geeksforgeeks.org/queries-left-right-circular-shift-array/
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void
reverse(int * arr, int low , int high) {
    while(low < high) {
        arr[low] = arr[low] ^ arr[high];
	arr[high] = arr[low] ^ arr[high];
	arr[low] = arr[low] ^ arr[high];
	low++;
	high--;
    }	    
}	

void
right_rotate(int * arr, int no_of_rotations, int len) {
    no_of_rotations = no_of_rotations % (len);
    reverse(arr,0,len);
    reverse(arr,0,no_of_rotations);
    reverse(arr,no_of_rotations+1,len);
}


void
left_rotate(int * arr, int no_of_rotations, int len) {
    no_of_rotations = no_of_rotations % (len);
    reverse(arr,0,no_of_rotations);
    reverse(arr,no_of_rotations+1,len);
    reverse(arr,0,len);
}	

void
print_arr(int * arr, int len) {
    int iter = 0 ;
    for(;iter < len; iter++)
	printf("%d ",arr[iter]);
    printf("\n");    
}	

int
main(void) {
   int arr[] = {1,2,3,4,5};
   int len = sizeof(arr)/sizeof(arr[0]);
   int no_of_rotations = 2;
   left_rotate(arr,no_of_rotations,len-1);
   print_arr(arr,len);
   right_rotate(arr,no_of_rotations,len-1);
   return 0;
}	
