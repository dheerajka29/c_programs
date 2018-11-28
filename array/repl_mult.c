/*
 * Replace every array element by multiplication of previous and next
   Given an array of integers, update every element with multiplication of previous and next elements with following exceptions. 
   a) First element is replaced by multiplication of first and second.
   b) Last element is replaced by multiplication of last and second last.

   Input: arr[] = {2, 3, 4, 5, 6}
   Output: arr[] = {6, 8, 15, 24, 30}

   // We get the above output using following
   // arr[] = {2*3, 2*4, 3*5, 4*6, 5*6} 
 */

#include <stdio.h>

static void 
print_arr(int * arr, int len) {
    int iter = 0;
    for(iter;iter<len;iter++)
	printf("%d ",arr[iter]);
    printf("\n");    
}

static void
mult_arr(int * arr,int len) {
    int iter = 0;
    int prev = 1;
    int curr = 1;
    if (len <= 1)
	return;
    //handle the 0th index.
    prev = arr[0];
    arr[0] = arr[0]*arr[1];
    
    for(iter = 1;iter < len-1; iter++) {
	curr = arr[iter];    
	arr[iter] = prev*arr[iter+1];
	prev = curr;
    }
    //handle the last index.    
    arr[iter] = prev * arr[iter]; 
}	

int main(void) {
    int arr[] = {2, 3, 4, 5, 6};
    int len = sizeof(arr)/sizeof(int);
    mult_arr(arr,len);
    print_arr(arr,len);
}	
