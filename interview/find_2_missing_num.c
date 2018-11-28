/*
 * https://www.geeksforgeeks.org/find-two-missing-numbers-set-2-xor-based-solution/
 * Find Two Missing Numbers | Set 2 (XOR based solution)
   Given an array of n unique integers where each element in the array is in range [1, n]. 
   The array has all distinct elements and size of array is (n-2). Hence Two numbers from the range are missing from this array. Find the two missing numbers.

   Examples:

   Input  : arr[] = {1, 3, 5, 6}, n = 6
   Output : 2 4

   Input : arr[] = {1, 2, 4}, n = 5
   Output : 3 5

   Input : arr[] = {1, 2}, n = 4
   Output : 3 4
 */ 

#include <stdio.h>

int 
main(void) {
    int arr[] = {1,3,4,5,6,8};
    int len = sizeof(arr)/sizeof(int);
    int n = 8;
    int temp = 0;
    int iter = 0;
    int xor = 0;
    int xor_temp = 0;
//Approach 1 .
#if 0 
    for(iter;iter<len;iter++)
	temp += arr[iter];    

    //We now have the average of 2 non-known nos.
    int total_sum = (n*(n+1))/2;
    int avg = (total_sum - temp)/2;
    int small_temp = 0;
    int max_temp = 0;
    //Step 1 : calculate the sum of nos smaller/equal than avg as
    //well as sum of nos greater than avg.
     for(iter = 0; iter<len;iter++){
	 if(arr[iter] <= avg) {
	    small_temp += arr[iter];
	 } else {   	 
	 max_temp += arr[iter];
         }
     }	 
     //First number will be total sum from 1-avg - sum of array elements till avg.
     printf("First no is %d \n",((avg*(avg+1)/2) - small_temp)); 
     //Second number will be total sum from avg-max - sum of elements greater than avg. 
     printf("Second num is %d\n",total_sum - max_temp - (avg*(avg+1)/2));
#endif 

//Approach 2 using XOR.
     for(iter;iter < len; iter++)    
	 xor ^= arr[iter];
     for(iter = 1;iter <=n;iter++)
	 xor_temp ^= iter;
     int two_nos_xor = xor_temp ^ xor;
     //Now we need to fetch our 2 nos from 2_nos_xor.
     /*
      * Step 1 : find the set bit in the 2_nos_xor . 
      */ 
     int set_bit_no = two_nos_xor & ~(two_nos_xor-1);
     /*
      * Step 2 : Hunt for nos in array who have this bit set . If true, xor them.
      *          Also , hunt for nos in range 1-n , and xor it to above variable.
      *          Final value will be the one of the nos.
      */
      two_nos_xor = 0;
      int temp_two_nos_xor = 0;
      for(iter = 0;iter < len; iter++) {
          if(arr[iter] & set_bit_no) {
	     two_nos_xor ^= arr[iter];
	  }	  
	  if((arr[iter] & set_bit_no) == 0) {
	      temp_two_nos_xor ^= arr[iter]; 
	  }	  
      }	
      for(iter = 1;iter <= n; iter++) {
          if(iter & set_bit_no) {
	     two_nos_xor ^= iter;
	  }	  
	  if((iter & set_bit_no) == 0) {
	      temp_two_nos_xor ^= iter; 
	  }	  
      }	
      printf("Nos are %d and %d\n",two_nos_xor,temp_two_nos_xor);     
     return 0 ;
}	
