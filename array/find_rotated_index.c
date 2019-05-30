#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int
helper_func(int * arr, int low, int high) {
   if(low > high)
      return -1;
   int mid = (low+high)/2;
   if(arr[mid] > arr[mid+1])
      return mid;
   if(arr[mid] < arr[mid-1])
      return mid-1;	   
   if(arr[mid] > arr[low])
      return helper_func(arr,mid+1,high);
   if(arr[mid] <= arr[high])
      return helper_func(arr,low,mid-1);	   
}	

int
main(void) {
   int arr[] = {3,4,5,6,7,1,2};
   int len = sizeof(arr)/sizeof(arr[0]);
   int pivot_index = helper_func(arr,0,len-1);
   int sum_pair = 8;
   int high = pivot_index;
   int low = pivot_index + 1;
   bool status = false;
   while(low != high) {
        if(arr[low] + arr[high] == sum_pair) {
	   status = true;
           break;
        }
        if(arr[low] + arr[high] > sum_pair) {
	   //low--;
	   //if(low == -1)
	   //   low = len-1;	   
	   high = (high+len-1)%(len);
	   continue;
	}	
	if(arr[low] + arr[high] < sum_pair) {
           //high++;
	   //if(high == len-1)
	   //   high = 0;	   
	   low = (low+1)%(len);
           continue;
        }
   }
   printf("sum pair Found : %s\n",status ? "True" : "False");   
   return 0;
}	
