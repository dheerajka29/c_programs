/*
 * https://www.geeksforgeeks.org/replace-every-element-with-the-greatest-on-right-side/
 *
 * Replace every element with the greatest element on right side
 * Given an array of integers, replace every element with the next greatest element 
 * (greatest element on the right side) in the array. Since there is no element 
 * next to the last element, replace it with -1. For example, if the array is {16, 17, 4, 3, 5, 2}, then it should be modified to {17, 5, 5, 5, 2, -1}.
 */

#include <stdio.h>

int main(void) {
    int arr[] = {16};
    int len = sizeof(arr)/sizeof(len);
    int iter = len-2;
    int temp_max = arr[len-1]; //Store the last index.
    int temp_var = 0;
    //last element do not have max in its rhs , so mark it -1.
    arr[len-1] = -1;
    for(iter;iter >= 0; iter--){
	temp_var = arr[iter];    
        arr[iter] = temp_max;
	if(temp_var > temp_max)
	   temp_max = temp_var;	

    }
    for(iter = 0;iter < len;iter++)
	printf("%d ",arr[iter]);    
    printf("\n");
    return 0;
}	
