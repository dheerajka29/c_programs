/*
 *
 * Find maximum value of Sum( i*arr[i]) with only rotations on given array allowed
   Given an array, only rotation operation is allowed on array. We can rotate the array as many times as we want. Return the maximum possbile of summation of i*arr[i].

   Examples :

   Input: arr[] = {1, 20, 2, 10}
   Output: 72
   We can 72 by rotating array twice.
   {2, 10, 1, 20} 20*3 + 1*2 + 10*1 + 2*0 = 72

   Input: arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   Output: 330
   We can 330 by rotating array 9 times.
   {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  0*1 + 1*2 + 2*3 ... 9*10 = 330
 *
 */

#include <stdio.h>

/*
 *
 * V1 to rotate an array
 */ 
static void
rotate_array_v1(int * arr , int len, int rot_index) {
    int index = 0, iter = 0, temp = 0;
    for(index;index < rot_index;index++) {
        for(iter = 0;iter < len - 1; iter++) {
            temp = arr[iter];
	    arr[iter] = arr[iter+1];
	    arr[iter+1] = temp;
	}       	
    }	    
}	

static void
reverse_array(int * arr, int start, int end) {
     int temp = 0;	
     if(start < end) {
        while (start < end) {
	       temp = arr[start];
	       arr[start] = arr[end];
	       arr[end] = temp;
	       start++;
	       end--;
	}	
     }	     
}	

static void
rotate_array_v2 (int * arr, int len, int rot_index) {
     reverse_array(arr, 0 , rot_index);
     reverse_array(arr,rot_index+1,len-1);
     reverse_array(arr,0,len-1);
}

static int
find_max(int * arr, int len) {
    int index = 0, iter = 0;
    int cur_max = 0 , sum = 0;
    for (index; index < len; index++) {
         rotate_array_v2(arr,len,index);
 	 for(iter = 0;iter < len; iter++) {
	     sum = sum + iter * arr[iter];
	 }
 	 if (sum > cur_max)
	     cur_max = sum;
 	     sum = 0;	 
    }
    return cur_max;    
}	

int main(void) {
    //int arr[] = {1,20,2,10};
    int arr[] = {10,1,2,3,4,5,6,7,8,9};
    int len = sizeof(arr)/sizeof(int);
    printf("Max sum is %d\n",find_max(arr,len));
    return 0;
}	
