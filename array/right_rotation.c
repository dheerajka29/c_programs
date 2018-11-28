/*
 * Reversal algorithm for right rotation of an array
   Given an array, right rotate it by k elements.

   Examples:

   Input: arr[] = {1, 2, 3, 4, 5,
                   6, 7, 8, 9, 10}
          k = 3
   Output: 8 9 10 1 2 3 4 5 6 7

   Input: arr[] = {121, 232, 33, 43 ,5}
          k = 2
   Output: 43 5 121 232 33
 */

#include <stdio.h>

static void
reverse_array(int * arr, int start, int end) {
    int temp = 0;
    if (start < end) {
        while (start < end) {
	       temp = arr[start];
	       arr[start] = arr[end];
	       arr[end] = temp;
	       start++;
	       end--;
	}	
    }	    
}	

static void 
rotate_array(int * arr, int len, int pos) {
    int converted_pos = len-pos-1;	
    reverse_array(arr,0,converted_pos);
    reverse_array(arr,converted_pos+1,len-1);
    reverse_array(arr,0,len-1);
}
int main(void) {
    //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr[] = {121, 232, 33, 43 ,5};
    int rot_arr = 10;
    int len = sizeof(arr)/sizeof(int);
    rotate_array(arr,len,rot_arr);
    int index;
    for(index = 0;index < len; index++)
	printf("Value is %d\n",arr[index]);
}	
