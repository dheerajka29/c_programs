/*
 * Search in a sorted and/or rotated array.
 * Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
         key = 3
   Output : Found at index 8

   Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
         key = 30
   Output : Not found

   Input : arr[] = {30, 40, 50, 10, 20}
        key = 10
   Output : Found at index 3
*/

#include <stdio.h>

int 
find_pivot(int * arr , int start , int end) {
     int mid = (start + end) / 2 ;	
     if (start < end) {
         if(arr[mid] > arr[mid + 1])
            return;
     }else {
        return -1;
     }	     
}	

void 
search_arr(int * array, int len, int elem) {
    //Step 1 : Find the pivot element.
    //         If no pivot , then normal array ,
    //         search on it.
    //Step 2 : 
    int pivot = find_pivot(array,0,len);
    if (pivot == -1) {
        //Case of normal sorted array.
    }
    // Case of reversed array.    
    if(elem > array[0]) {
    // Case when element is greater , then it is in first half.
    } else {
    // Case when element is in disjointed array.
    }	    
}	

int main(void) {
    int array = {3,4,5,1,2};
    int len = sizeof(arr)/sizeof(int);
    int elem = 4;
    search_arr(array,len,elem);
}	
