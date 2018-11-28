/*
 *Rearrange positive and negative numbers with constant extra space
Given an array of positive and negative numbers, arrange them such that all negative integers appear before all the positive integers in the array without using any additional data structure like hash table, arrays, etc. The order of appearance should be maintained.

Examples:

Input:  [12 11 -13 -5 6 -7 5 -3 -6]
Output: [-13 -5 -7 -3 -6 12 11 6 5]
//https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers/
 */ 


//For now , doing quick sort changing the arrangement.
#include <stdio.h>

static int
partition_sort (int * arr, int low, int high) {
    int pivot = 0;
    int index = low;
    int i = low;
    int swap_var = 0;
    for (index; index <= high; index++) {
         if (arr[index] < pivot) {
	     swap_var = arr[index];
             arr[index] = arr[i];
 	     arr[i] = swap_var;
	     i++;	     
	 }	 
    }
    return i;    
}
static void
quick_sort(int * arr, int low, int high) {
     int pi = 0;
     int neg_index = 0;
     int pos_index = 0;
     if (low < high) {
         pi = partition_sort(arr,low,high); // Now this API will return the index of sorted index.This will be the index of first positive element.
     }	    
     neg_index = low;
     pos_index = pi;
     int swap = 0;
    while (neg_index < pos_index && pos_index <= high ) {
           swap = arr[pos_index];
	   arr[pos_index] = arr[neg_index + 1];
	   arr[neg_index + 1] = swap;
	   neg_index += 2; 
	   pos_index ++;  
    }	    
}	

int main (void) {
    int arr[] = {12,11,-13,-5,6,-7,5,-3,-6};
    int len = sizeof(arr)/sizeof(int);
    int index = 0;
    quick_sort(arr,0,len-1);
    for (index;index < len; index++)
	 printf("Element at pos %d is %d\n",index,arr[index]);
    return 0;    
}	
