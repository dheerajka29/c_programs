/*
 *Segregate even and odd numbers | Set 3
Given an array of integers, segregate even and odd numbers in the array. All the even numbers should be present first, and then the odd numbers.

Examples:

Input : 1 9 5 3 2 6 7 11
Output : 2 6 5 3 1 9 7 11

Input : 1 3 2 4 7 6 9 10
Output : 2 4 6 10 7 1 9 3
 */ 

/*
 * Approach :
 * Step 1 : Initialize odd_index with 0 and even_index with len - 1. Hunt for odd element and even element respectively.
 * Step 2 : Swap both the index.  
 */
#include <stdio.h>

static void
swap(int * arr, int low, int high) {
     if(low < high) {
        int temp = 0;
        temp = arr[low];
        arr[low] = arr[high];
	arr[high] = temp;	
     }	     
}	

static void
rearr_even_odd(int * arr, int len) {
    int even_index = len - 1;
    int odd_index = 0;
    while (odd_index < even_index) {
         while (arr[odd_index] % 2 == 0 && odd_index < len)
		odd_index++;
	 while (arr[even_index] % 2 != 0 && even_index > 0)
		even_index--;
	swap(arr,odd_index,even_index); 
    }	    
}	

static void
print_arr(int * arr, int len) {
    int iter = 0;
    for (iter;iter < len; iter++)
	 printf("%d ",arr[iter]);
    printf("\n");   
}	

int 
main (void) {
    //int arr[] = {1,9,5,3,2,6,7,11};
    int arr[] = {1,3,2,4,7,6,9,10};
    int len = sizeof(arr)/sizeof(len);
    print_arr(arr,len);
    rearr_even_odd(arr,len);
    print_arr(arr,len);
}	
