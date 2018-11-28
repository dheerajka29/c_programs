/*
 *Find a rotation with maximum hamming distance
  Given an array of n elements, create a new array which is a rotation of given array and hamming distance between both the arrays is maximum.
  Hamming distance between two arrays or strings of equal length is the number of positions at which the corresponding 
  character(elements) are different.
  Input :  1 4 1
  Output :  2
  Explanation:  
  Maximum hamming distance = 2.
  We get this hamming distance with 4 1 1 
  or 1 1 4 

  input :  N = 4
         2 4 8 0
  output :  4
  Explanation: 
  Maximum hamming distance = 4
  We get this hamming distance with 4 8 0 2.
  All the places can be occupied by another digit.
  Other solutions can be 8 0 2 4, 4 0 2 8 etc.
 */

#include <stdio.h>
#include <string.h>
int 
count_hamming(int * arr , int * temp , int index, int len) {
     int count = 0;
     int iter = 0;
     for(iter;iter <len; iter++) {
         if(arr[iter] != temp[iter + index]) {
	    count++;
	 }	 
     }	     
     return count;
}	

int main (void) {
    int arr[] = {2,4,8,0};
    int len = sizeof(arr)/sizeof(int);
    int temp[2*len];
    int hamming_max_count = 0, temp_count = 0;
    int index = 0;
    memset(temp,0,sizeof(temp));
    memcpy(temp,arr,len*sizeof(int));
    memcpy(&temp[3],arr,len*sizeof(int));
    for (index =1;index <= len; index++) {
         temp_count = count_hamming(arr,temp,index, len);
         if(temp_count > hamming_max_count) {
	    hamming_max_count = temp_count;
	 }	 
    }	   
    printf("Max count is %d\n",hamming_max_count); 
}	
