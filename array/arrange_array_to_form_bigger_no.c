/*
 * https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
 */ 
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int
find_count(int val) {
    int temp_count = 0;
    while(val) {
          val = val/10;
	  temp_count++;
    }	   
   return temp_count; 
}

void
sorting_algo(int * arr , int len) {
    int iter = 0 , j = 0;
    int count1 = 0;
    int count2 = 0;
    for(;iter < len-1;iter++) {
        for(j = iter+1;j <len;j++ ) {
	    count1 = find_count(arr[iter]);
	    count2 = find_count(arr[j]);
	    int temp_var_1 = arr[iter] * pow(10,count2) + arr[j];
	    int temp_var_2 = arr[j] * pow(10,count1) + arr[iter];
            if(temp_var_2 > temp_var_1) {
	       arr[iter] = arr[j] ^ arr[iter];
	       arr[j] = arr[j] ^ arr[iter];
	       arr[iter] = arr[j] ^ arr[iter];
	    }	    
	}	
    }	    
}	

void
print_arr(int * arr, int len) {
   int iter = 0;
   for(;iter < len;iter++) {
       printf("%d ",arr[iter]);
   }	   
   printf("\n");
}	

int
main(void) {
    //int arr[] = {1, 34, 3, 98, 9, 76, 45, 4};
    int arr[] = {54, 546, 548, 60};
    int len = sizeof(arr)/sizeof(arr[0]);
    print_arr(arr,len);
    sorting_algo(arr,len);
    print_arr(arr,len);
    return 0;
}	
