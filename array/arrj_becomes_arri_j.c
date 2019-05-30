/*
 * https://www.geeksforgeeks.org/rearrange-array-arrj-becomes-arri-j/
 * https://ideone.com/QSPWMK
 */ 
#include <stdio.h>
#include <string.h>

void
print_arr(int * arr, int len) {
    int iter = 0;
    for(;iter <len;iter++) {
        printf("%d ",arr[iter]);
    }	    
    printf("\n");
}	

int
main(void) {
    int arr[]  =  {2, 0, 1, 4, 5, 3};
    int len = sizeof(arr)/sizeof(arr[0]);
    int iter = 0 ;

    print_arr(arr,len);
    for(;iter < len;iter++) {
	/* modulo of len is needed as we are losing the value after iteration.*/     
	/* Logic : Total_value = new_value * length + old_value.
	 * Divisor of above will give new_value while modulo gives old_value*/    
        arr[arr[iter]%len] += iter*len;
    }
    for(iter = 0;iter < len;iter++) {
        arr[iter] = arr[iter]/len;
    }    
    print_arr(arr,len);
    return 0;    
}	

