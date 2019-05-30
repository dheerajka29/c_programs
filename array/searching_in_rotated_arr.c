#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool
helper_func(int * arr, int low, int high, int key) {
    if(low > high)
	return false;
    int mid = (low + high)/2;
    //If element is found , return true. 
    if(arr[mid] == key)
	return true;
    /* Case when middle element is greater than
     * the first element. It means this half is sorted.
     * Check for key , if it is part of this group.
     * If yes , then moveover to this part , else
     * we move to the other group.
     */ 
    if(arr[mid] > arr[low]) {
	if(key >= arr[low] &&
	   key <= arr[mid]) 
	   return helper_func(arr,low,mid-1,key);
	else
	   return helper_func(arr,mid+1,high,key);	   
    } 
    /* Case when middle element is smaller than
     * the last element. It means this half is sorted.
     * Check for key , if it is part of this group.
     * If yes , then moveover to this part , else
     * we move to the other group.
     */
    else {
        if(key >= arr[mid] &&
           key <= arr[high]) 
           return helper_func(arr,mid+1,high,key);
        else
           return helper_func(arr,low,mid-1,key);

    }	    
}	

bool
search_element(int * arr, int len , int key) {
     return helper_func(arr, 0 , len, key);
}	

int
main(void) {
   int arr[] = {5,6,7,8,1,2,3,4};
   int len = sizeof(arr)/sizeof(arr[0]);
   int key = 0;
   bool status = search_element(arr,len-1,key);
   printf("Found : %s\n",status ? "True":"False");
   return 0; 
}	

