#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// https://www.geeksforgeeks.org/find-maximum-value-of-sum-iarri-with-only-rotations-on-given-array-allowed/

// Below is the first un-optimized approach where we picks a rotated array and computes its sum.
// We then compare this sum with the previously calculated value and then either store or reject it.

#if 0
void
reverse_array(int * arr, int low , int high) {
    while(low < high) {
        arr[low] = arr[low] ^ arr[high];
	arr[high] = arr[low] ^ arr[high];
	arr[low] = arr[low] ^ arr[high];
	low++;
	high--;
    }	    
}	

void
rotate_array(int * arr , 
	     int len , 
	     int rotation_number) {
    reverse_array(arr,0,rotation_number);
    reverse_array(arr,(rotation_number+1),len-1);
    reverse_array(arr,0,len-1);
}	

int
find_arr_sum(int * arr, int len) {
   int temp = 0;
   int iter = 0;
   while(iter < len) {
        temp += iter*arr[iter];
	iter++;
   }	   
   return temp;	   
}	

int
main(void) {
    int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(arr)/sizeof(arr[0]);
    int iter = 0;
    int max_sum = 0;
    int temp_sum = 0;
    /*
     * Steps : 
     * 1. Rotate the array .
     * 2. Calculate the sum . 
     */ 
    for(;iter < len; iter++) {
        rotate_array(arr,len,iter);
	temp_sum =find_arr_sum(arr,len);
	if(temp_sum > max_sum)
	   max_sum = temp_sum;	
    }	    
    printf("Max Sum is %d\n",max_sum);
    return 0;
}	
#endif 

int
main(void) {
   int arr[] = {1, 20, 2, 10};
   int len = sizeof(arr)/sizeof(arr[0]);
   int iter = len-1 ;
   int arr_sum = 0;
   int prev_sum = 0;
   int final_sum = 0;
   /*
    * Here , we calculate the initial sum of the array as
    * well as sum of i * arr[i].
    */ 
   for(;iter >= 0 ;iter-- ) {
       arr_sum = arr_sum + arr[iter];
       prev_sum += iter*arr[iter];
   }
   //We need to start from (i-2)since this rotation will lead to dropping of element 9.
   //(i-1) will lead to recalculation of initial array , which we do not want.
   iter = len-2;
   final_sum = prev_sum;

   for(;iter >=0;iter--) {
       // In the previous calculation ,we are adding arr_sum ,i.e individual elements again ,followed by
       // Subtraction of the element that is being dropped in the new iteration. 	   
       prev_sum = prev_sum + arr_sum - (len)*arr[iter+1];
       if(prev_sum > final_sum)
	  final_sum = prev_sum;     
   }
   printf("%d\n",final_sum);
   return 0;   
}	
