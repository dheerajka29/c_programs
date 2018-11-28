/*
 * Move all negative elements to end in order with extra space allowed
   Given an unsorted array of both negative and positive integer. 
   The task is place all negative element at the end of array without changing the order of positive element and negative element.
   Note : No Extra space allowed
Examples:

Input : arr[] = {1, -1, 3, 2, -7, -5, 11, 6 }
Output : 1  3  2  11  6  -1  -7  -5 

Input : arr[] = {-5, 7, -3, -4, 9, 10, -1, 11}
Output : 7  9  10  11  -5  -3  -4  -1  
 */ 


/*
 * Note : Can also be done with quick sort taking the pivot element as 0.
 */ 

#include <stdio.h>
#include <string.h>


static void
swap (int * arr, int min_index, int max_index) {
      int temp = 0;
      if (min_index < max_index) {
	  temp = arr[min_index];
	  arr[min_index] = arr[max_index];
	  arr[max_index] = temp; 
      }	      
}	

static void
rearr_neg_elem(int * arr, int len) {
    int neg_index = 0;
    int pos_index = len-1;
    int iter = 0;
    while (neg_index < pos_index) {
        while (arr[neg_index] > 0 && neg_index < len)
	       neg_index++;
	while (arr[pos_index] < 0 && pos_index > 0) {
		pos_index--;	
	}
	swap(arr,neg_index,pos_index);	
    }	    
}	

static void
print_arr(int * arr, int len) {
   int iter = 0;
   for (iter;iter < len; iter++)
	printf("%d ",arr[iter]);
   printf("\n");   
}	
int main (void) {
   // int arr[] = {1, -1, 3, 2, -7, -5, 11, 6 };
    int arr[] = {-5, 7, -3, -4, 9, 10, -1, 11}; 
    int len = sizeof(arr)/sizeof(len);
    print_arr(arr,len);
    rearr_neg_elem(arr,len);
    print_arr(arr,len);
}	
