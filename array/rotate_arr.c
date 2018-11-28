/*
 * Write a function rotate(arr[], d, n) that rotates arr[] of size n by d elements.

   Example :

   Input :  arr[] = [1, 2, 3, 4, 5, 6, 7]
         d = 2
   Output : arr[] = [3, 4, 5, 6, 7, 1, 2]

   https://www.geeksforgeeks.org/array-rotation/
*/

#include <stdio.h>


void
reverse_array(int * arr, int from, int till) {
     int temp = 0;
     while (from < till){
	        temp = arr[from];
		arr[from] = arr[till];
		arr[till] = temp;
	from++;
        till--;	
     }	     
}	

void 
rotate_array(int * arr ,int  d,int len) {
	reverse_array(arr,0,d-1);
	reverse_array(arr,d,len-1);
	reverse_array(arr,0,len-1);
}	

int main (void) {
    int arr[5] = {0,1,2,3,4};
    int no_of_rot = 2;
    int len = 5;
    
    /* 
     * V1 Below.
     * int temp;
    int index = 0 , i;
    for (index;index<no_of_rot;index++) {
         for (i = 0;i < (len - 1);i++) {
              temp = arr[i];
	      arr[i] = arr[i+1];
	      arr[i+1] = temp;
         }
    }*/
    int index;
    rotate_array(arr,no_of_rot,len);
    for(index = 0;index < len;index++)
        printf("%dst element is %d \n",index,arr[index]);
}	
