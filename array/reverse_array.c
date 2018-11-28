#include <stdio.h>

static void
reverse_arr(int * arr, int start, int end) {
    int temp = 0;
    while (start < end) {
           temp = arr[start];
	   arr[start] = arr[end];
	   arr[end] = temp;
	   ++start;
	   --end;
    }	    
}	

int main (void) {
    int arr[] = {1,2,3,4,5};
    int len = sizeof(arr)/sizeof(int);
    reverse_arr(arr,0,len-1);
    int index = 0;
    for (;index < len;index++)
	 printf ("%d ",arr[index]);   
}	
