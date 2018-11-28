/*
 *
 *  Find the minimum element in a sorted and rotated array
    A sorted array is rotated at some unknown point, find the minimum element in it.

    Following solution assumes that all elements are distinct.
    Examples:



    Input: {5, 6, 1, 2, 3, 4}
    Output: 1

    Input: {1, 2, 3, 4}
    Output: 1

    Input: {2, 1}
    Output: 1
 */

#include <stdio.h>

int 
find_min(int * arr, int start, int end) {
    if (start == end)
	return arr[start];
    if (start > end) {
	printf ("start : %d end : %d\n",start,end);    
	return arr[0];
    }	
    int mid = (start + end )/2 ;
    if (mid < end && arr[mid] > arr[mid+1])
	return arr[mid+1];
    if (mid > start && arr[mid] < arr[mid-1])
	return arr[mid];
    if (arr[mid] > arr[0])
	return find_min(arr,start,mid-1);
    else return find_min(arr,mid+1,end);    
}

int main (void) {
    int arr [] = {2,1};
    int len = sizeof(arr)/sizeof(int);
    printf("Minimum is %d \n",find_min(arr,0,len-1));
}	
