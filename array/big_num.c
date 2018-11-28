/*
 * Arrange given numbers to form the biggest number | Set 1
Given an array of numbers, arrange them in a way that yields the largest value. For example, if the given numbers are {54, 546, 548, 60}, the arrangement 6054854654 gives the largest value. And if the given numbers are {1, 34, 3, 98, 9, 76, 45, 4}, then the arrangement 998764543431 gives the largest value.

https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
 */ 

#include <stdio.h>
#include <math.h>

int 
find_digits (int val) {
    int temp = val;
    int count = 0;
    if (val == 0 ) return 1;
    while (val) {
           val = val/10;
	   count++;   
    } 	    
    return count;
}	

static void
sorted_arr(int * arr, int len) {
    int index = 0;
    int j = 0;
    int temp_1,temp_2;
    int swap;
    for (index;index < len;index++) {
	 for(j = index; j < len; j++) {  
	     int n1 = find_digits(arr[index]);
             int n2 = find_digits(arr[j+1]);
	     temp_1 = arr[j+1] * pow(10,n1) + arr[index];
	     temp_2 = arr[index] * pow(10,n2) + arr[j+1];
             if (temp_1 > temp_2) {
		 swap = arr[index];
	         arr[index] = arr[j+1];	 
	         arr[j+1] = swap;
	     }		     
         }	     
    }	    
}	

int 
main(void) {
    int arr[] = {1, 34, 3, 98, 9, 76, 45, 4};
    int len = sizeof(arr)/sizeof(int);
    sorted_arr(arr,len-1);
    int iter = 0;
    while (iter < len) {
        printf("%d",arr[iter]);
	iter++;
    }	    
    return 0;
}
