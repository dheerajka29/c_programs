/*
 * Positive elements at even and negative at odd positions
You have been given an array and you have to make a program to convert that array such that positive elements occur at even numbered places in the array and negative elements occur at odd numbered places in the array. We have to do it in place and the relative order of the elements must be maintained.
There can be unequal number of positive and negative values and the extra values have to left as it is.

Examples:

Input : arr[] = {1, -3, 5, 6, -3, 6, 7, -4, 9, 10}
Output : arr[] = {1, -3, 5, -3, 6, 6, 7, -4, 9, 10}

Input : arr[] = {-1, 3, -5, 6, 3, 6, -7, -4, -9, 10}
Output : arr[] = {3, -1, 6, -5, 3, -7, 6, -4, 10, -9}

 *https://www.geeksforgeeks.org/positive-elements-even-negative-odd-positions/
 */ 

#include <stdio.h>
#include <string.h>

static void
swap(int * arr, int pos_index, int neg_index, int len) {
     int temp = 0;	
     if( neg_index < len && pos_index < len) {
         temp = arr[neg_index];
	 arr[neg_index] = arr[pos_index];
	 arr[pos_index] = temp;
     }	     
}	

static void 
rearr_arr_elem(int * arr, int len ) {
    int pos_index = 0;
    int neg_index = 1;
    while (pos_index < neg_index) {
           while (arr[pos_index] > 0 && pos_index < len)
		  pos_index += 2;
	   while (arr[neg_index] < 0 && neg_index < len)
                  neg_index += 2; 
	   swap(arr,pos_index,neg_index, len);
    }	    
}	

static void
print_arr(int * arr, int len) {
    int iter = 0;
    for (iter;iter < len; iter++)
	 printf("%d ",arr[iter]);
    printf("\n");   
}	

int main(void) {
    //int arr[] = {1, -3, 5, 6, -3, 6, 7, -4, 9, 10};
    int arr[] = {-1, 3, -5, 6, 3, 6, -7, -4, -9, 10};
    int len = sizeof(arr)/sizeof(int);
    print_arr(arr,len);
    rearr_arr_elem(arr,len);
    print_arr(arr,len);
}	
