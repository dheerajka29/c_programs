#include <stdio.h>
#include <string.h>

void
swap(int * arr, int i , int j) {
    if(i < j) {
       arr[i] = arr[i] ^ arr[j];
       arr[j] = arr[i] ^ arr[j];
       arr[i] = arr[i] ^ arr[j]; 
    }	    
}	

void
print_array(int * arr, int len) {
    int iter = 0;
    for(;iter < len; iter++) 
	printf("%d ",arr[iter]);
    printf("\n");    
}	

int
main(void) {
   int arr[] = {1,2,3,4,5,6};
   int len = sizeof(arr)/sizeof(arr[0]);
   int i = 0,j = 0;
   int rotate_by = 3;
   print_array(arr,len);
   for(;i < 3; i++)
	for(j = 0;j < len- 1;j++)	   
	    swap(arr,j,j+1);
   print_array(arr,len);
   return 0;  
}	
