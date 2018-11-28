/* 
 * Given an array that is sorted and then rotated around an unknown point. Find if array has a pair with given sum ‘x’. It may be assumed that all elements in array are distinct.

Examples :

Input: arr[] = {11, 15, 6, 8, 9, 10}, x = 16
Output: true
There is a pair (6, 10) with sum 16

Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 35
Output: true
There is a pair (26, 9) with sum 35

Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 45
Output: false
There is no pair with sum 45.
*/
#include <stdio.h>
int hash[10000];

static void
check_pair_sum(int * arr,int len, int sum) {
    int index = 0;
    int temp = 0;
    for (index ; index < len ; index++) {
         temp = sum - arr[index];
	 if (temp > 0 && hash[temp] == 1) 
             printf("Found\n");		 
         hash[arr[index]] = 1; 
    }	    
}	

static void
check_sum_pair(int * arr, int start , int end, int sum) {
    while (start < end) {
           if(arr[start] + arr[end] > sum)
	      end--;
	   if(arr[start] + arr[end] < sum)
	      start++;
	   else { printf("Pair found\n"); start++;end--;}
    }	  
    printf("not found\n");  
}	

int 
main (void) {
   int arr[] = {11,15,6,5,9,10};
   int sum = 16;
   int len = sizeof(arr)/sizeof(int);
   //Method 1
   	//check_pair_sum(arr,len,sum);
   //Method 2
      merge_sort(arr,0,len-1);
      check_sum_pair(arr,0,len-1, sum); 
   return 0;
}	
