#include <stdio.h>
#include <string.h>

int 
partition_sort(int * arr, int low, int high) {
    int pivot = arr[low];
    int index = low+1;
    int swap_temp = 0;
    int i = index; 
    for (index; index <= high; index++) {
    	 if (arr[index] < pivot) {
	     swap_temp = arr[index];
	     arr[index] = arr[i];
	     arr[i] = swap_temp;
	     i++;
	 }	 
    }	  
    swap_temp = arr[i-1];
    arr[i-1] = pivot;
    arr[low] = swap_temp; 
    return i-1; 
}	

void
quick_sort(int * arr, int low, int high) {
     int pi = 0;	
     if (low < high) {
         /*
	  *Step 1. Sort a single index first.
	  *Step 2. Recursively call the quick sort to sort the index of other halves.
	  */ 
	  pi = partition_sort(arr,low,high);
          quick_sort(arr,low,pi-1);
	  quick_sort(arr,pi+1,high);	  
     }	     
}	

int 
main(void) {
    int arr[] = {4,1,9,3,8,2,7};
    int len = sizeof(arr)/sizeof(int);
    quick_sort(arr,0,len-1);
    int index;
    for(index = 0;index < len ; index++)
	printf("%d \n",arr[index]);    
}	
