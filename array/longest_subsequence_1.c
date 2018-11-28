/*
 * https://www.geeksforgeeks.org/find-index-0-replaced-1-get-longest-continuous-sequence-1s-binary-array/
 * https://www.geeksforgeeks.org/find-index-of-0-to-be-replaced-with-1-to-get-longest-continuous-sequence-of-1s-in-a-binary-array-set-2/
 * Find Index of 0 to be replaced with 1 to get longest continuous sequence of 1s in a binary array
  Given an array of 0s and 1s, find the position of 0 to be replaced with 1 to get longest continuous
  sequence of 1s. Expected time complexity is O(n) and auxiliary space is O(1).
  Example:

  Input: 
   arr[] =  {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1}
  Output:
  Index 9
  Assuming array index starts from 0, replacing 0 with 1 at index 9 causes
  the maximum continuous sequence of 1s.

  Input: 
   arr[] =  {1, 1, 1, 1, 0}
  Output:
  Index 4
 */

#include <stdio.h>
#include <stdbool.h>

int maxOnesIndex(bool arr[], int len) {
    int iter = 0;
    int left_sum = 0;
    int right_sum = 0;
    int max = 0;
    int tmp_index = 0,final_index = 0;
    while(iter < len) {
	/*
	 * Case when an zero element is found. At this point ,calculate 1s on its right.
	 * Afterwards , if ( left + right ) sum is greater than current max , then update the index element.
	 * Then shift the zero element to next encountered and right_sum to left_sum.
	 */     
        if(arr[iter] == 0 ){
	   //Start iteration from the next index for calculating right_sum.	
	   tmp_index = iter+1;
           right_sum = 0;	   
	   while(tmp_index < len && arr[tmp_index]) {
	         right_sum++;
		 tmp_index++;
	   }
	   //If continuous sum is greater , then update the index.	   
	   if(max < right_sum + left_sum) {
	      max = right_sum + left_sum;
	      final_index = iter;
	   }
	   //Jump to next zero index as well as store the right sum calculated
	   //as a left sum to new zero index   
	   left_sum = right_sum;
	   iter = tmp_index;
	} else { /* Case when starting element is 1.
		  * it is a left_sum , so increement it 
		  * as well as increement iter index.
		  */   
	  left_sum++;
	  iter++;
	}	
    }
    return final_index;
}    

int
sliding_window(bool * arr, int len) {
    int max = 0;
    int fin_index = 0;
    int end = 0;
    int start = 0;
    int last_zero = -1;
    while (end < len) {
           while(arr[end] && end < len){
	         end++;
	   }	   
	   //Zero is encountered
	   //Differentiate between first and second zero.
	   if(last_zero != -1 && max < end - start) {
	      max = end-start;
	      fin_index = last_zero;
	   }	  
	   start = last_zero + 1;
	   last_zero = end;
	   end++; 
    }
    if(last_zero != -1 && max < end - start) {
       fin_index = last_zero;
    }	    
    return fin_index;
}	

// Driver program 
int 
main() { 
    bool arr[] = {1, 1, 1, 1, 0}; 
    int len = sizeof(arr)/sizeof(arr[0]);
    /* Version 1
     * printf("%d\n",maxOnesIndex(arr,len));
     */
    printf("%d\n",sliding_window(arr,len)); 
    return 0;
}    
