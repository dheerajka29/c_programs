/*
 * https://www.geeksforgeeks.org/rearrange-positive-negative-numbers-using-inbuilt-sort-function/
 */ 

#include <stdio.h>
#include <string.h>

void
swap(int * arr, int i , int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}	

int
main(void) {
    int arr[] = {12, 11, -13, -5, 6, -7, 5, -3, -6};
    int len = sizeof(arr)/sizeof(arr[0]);
    int iter = 0;
    int tortoise = 0;
    for(;iter < len;iter++) {
        if(arr[iter] >= 0)
	   continue;
        swap(arr,iter,tortoise);
        tortoise++;	
    }
    return 0;    
}	
