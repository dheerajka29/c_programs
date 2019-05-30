/*
 * https://www.geeksforgeeks.org/positive-elements-at-even-and-negative-at-odd-positions-relative-order-not-maintained/
 */ 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void
print_arr(int * arr, int len) {
    int iter = 0;
    for(;iter < len;iter++)
	printf("%d ",arr[iter]);
    printf("\n");    
}

void
swap(int * arr, int low , int high) {
    int temp = 0;
    temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
}	

int
main(void) {
    int arr[] = {1,-3,5,6,-3,6,7,-4,9,10};
    int len = sizeof(arr)/sizeof(int);
    int odd_index = 1;
    int even_index = 0;
    while(true) {
         while(even_index < len &&
	       arr[even_index] >= 0 )
	       even_index +=2;
         while(odd_index < len &&
	       arr[odd_index] < 0)
	       odd_index +=2;		 
	 if(odd_index >= len ||
	    even_index >= len)
	    break;	 
	 swap(arr,odd_index,even_index);
    }
    print_arr(arr,len);
    return 0;    
}	
