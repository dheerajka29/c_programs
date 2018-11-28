/*
 * Rearrange an array such that arr[i] = i
 Given an array of elements of length N, ranging from 1 to N. All elements may not be present in the array. If element is not present then there will be -1 present in the array. Rearrange the array such that A[i] = i and if i is not present, display -1 at that place.

 Examples:

 Input : arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1}
 Output : [-1, 1, 2, 3, 4, -1, 6, -1, -1, 9]

 Input : arr = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8,
                11, 10, 9, 5, 13, 16, 2, 14, 17, 4}
 Output : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
          11, 12, 13, 14, 15, 16, 17, 18, 19]
 */

#include <stdio.h>

/*
 * API to place the arr[index] to correct place.
 * First , it will fetch the arr[index] to be restored 
 * to its correct place.
 * Then arr[index] will be reset to -1 so that if other elements 
 * has this index as a value , than it can be restored here.
 * If temp index has value -1 , straight-away restore and return.
 * Again temp index has different value , we need to restore it and
 * recurse.
 * Finally store temp to temp index.
 */
static void 
swap (int * arr, int index, int len) {
      int temp = arr[index];
      arr[index] = -1;
      if (temp > len) 
	  return;
      if (arr[temp] == -1) {
          arr[temp] = temp;
	  return;
      }
      swap(arr,temp,len);
      arr[temp] = temp;
}

/*
 * API to check if index 
 * is correctly placed or not.
 * Case 1: if arr[index] has index , then return.
 * Case 2: if arr[index] has -1 , then return.
 * Case 3: arr[index] has other value , need to place
 * it correctly.
 */


static void 
order_arr(int * arr, int len , int index) {
    if (index > len)
	return;
    if (arr[index] == index)
	return;
    if (arr[index] == -1)
	return;
    swap(arr, index, len);     
}	

static void
rearrange_arr(int * arr , int len) {
    int iter = 0;	
    for(iter ;iter < len;iter++) {
        order_arr(arr, len, iter);
    }	    
}	

int main (void) {
    //int arr[] = {-1,-1,6,1,9,3,2,-1,4,-1};
    int arr[] = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8,
                11, 10, 9, 5, 13, 16, 2, 14, 17, 4};
    int len = sizeof(arr)/sizeof(int);
    int iter = 0;
    rearrange_arr(arr,len);
    for (iter = 0;iter < len;iter++)
          printf("Element %d is %d\n",iter,arr[iter]);	 
}	
