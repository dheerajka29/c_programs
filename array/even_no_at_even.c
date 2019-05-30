#include <stdio.h>
#include <stdbool.h>
void
swap(int * arr, int pos1, int pos2) {
    arr[pos1] = arr[pos1] ^ arr[pos2];
    arr[pos2] = arr[pos1] ^ arr[pos2];
    arr[pos1] = arr[pos1] ^ arr[pos2];
}	

int
main(void) {
    int arr[] = {10,9,7,18,12,19,4,20,6,14};
    int len = sizeof(arr)/sizeof(int);
    int even_index = 0;
    int odd_index = 1;
    int iter = 0;
    while(true) {
         while(even_index < len &&
		arr[even_index]%2 == 0)
		 even_index += 2;
	 while(odd_index < len &&
		arr[odd_index]%2 != 0)
		 odd_index += 2;
	 if(even_index >= len ||
	    odd_index >= len)
	    break;
         swap(arr,odd_index,even_index);	 
    }	    
    for(;iter < len;iter++)
	printf("%d ",arr[iter]);
    printf("\n");
    return 0;    
}	
