/*
 * https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers/
 */ 

#include <string.h>
#include <stdio.h>

void
helper_func(int * arr, int low , int mid ,int high) {
    int a = mid - low + 1;
    int b = high - mid;
    int iter;
    int first_arr[a];
    int second_arr[b];

    memset(first_arr,0,sizeof(int)*a);
    memset(second_arr,0,sizeof(int)*b);

    for(iter = 0;iter < a;iter++) 
	first_arr[iter] = arr[low + iter];
    for(iter = 0;iter < b;iter++)
	second_arr[iter] = arr[mid + 1 + iter];
    int i = 0,j = 0, k  = low;
    while(i < a &&
	  first_arr[i] < 0) {
          arr[k] = first_arr[i];
	  i++;
	  k++;
    }	   
    while(j < b &&
          second_arr[j] < 0) {
          arr[k] = second_arr[j];
          j++;
          k++;
    }
    while(i < a &&
          first_arr[i] > 0) {
          arr[k] = first_arr[i];
          i++;
          k++;
    }
    while(j < b &&
          second_arr[j] > 0) {
          arr[k] = second_arr[j];
          j++;
          k++;
    } 
}	

void
merge_sort(int * arr ,int low ,  int high) {
     if(low < high) {
        int mid = (low + high)/2;
	merge_sort(arr,low,mid);
	merge_sort(arr,mid+1,high);
	helper_func(arr,low,mid,high);
     }	     
}	

void
print_arr(int * arr , int len) {
    int iter = 0;
    for(;iter < len;iter++) 
	printf("%d ",arr[iter]);
    printf("\n");   
}	

int
main(void) {
   int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6 };  
   int len = sizeof(arr)/sizeof(arr[0]);
   print_arr(arr,len);
   merge_sort(arr,0 , len-1);
   print_arr(arr,len);
}	
