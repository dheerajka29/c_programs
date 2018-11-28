/*
 *Given an array of n elements. Our task is to write a program to rearrange the array such that elements at 
  even positions are greater than all elements before it and elements at odd positions are less than all elements before it.

 Examples:

 Input : arr[] = {1, 2, 3, 4, 5, 6, 7}
 Output : 4 5 3 6 2 7 1

 Input : arr[] = {1, 2, 1, 4, 5, 6, 8, 8} 
 Output : 4 5 2 6 1 8 1 8
 */

#include <stdio.h>

static void
merge_arr(int * arr, int start, int mid, int end) {
     int l = mid - start + 1;
     int r = end-mid;
     int l_arr[l] ;
     int r_arr[r] ;
     int iter = 0;
     for (iter;iter<l;iter++)
	  l_arr[iter] = arr[start+iter];
     for (iter=0;iter < r;iter++)
	  r_arr[iter] = arr[mid+iter+1]; 
     int i = 0 , j = 0, k = start;
     while (i < l && j < r) {
            if (l_arr[i] < r_arr[j]) {
                arr[k] = r_arr[j];
	        j++;
	        k++;
           } else {
                arr[k] = l_arr[i];
	        k++;
	        i++;
           }
     }
     while(i < l) {
	   arr[k] = l_arr[i];     
	   i++;
	   k++;
     }
     while(j < r) {
           arr[k] = r_arr[j];
	   j++;
	   k++;
     }	     
}     

static void
merge_sort(int * arr, int start, int end) {
    if(start < end) {
       int mid = (start + end)/2;	    
       merge_sort(arr,start,mid);
       merge_sort(arr,mid+1,end);
       merge_arr(arr,start,mid,end);
    }	    
}	
int main (void) {
    //int arr[] = {1, 2, 1, 4, 5, 6, 8, 8};
    int arr[] = {1};
    int len = sizeof(arr)/sizeof(int);
    //int cpy_arr[] = {1, 2, 1, 4, 5, 6, 8, 8};
    int cpy_arr[] = {1};
    int i = 0, j = 0;
    merge_sort(cpy_arr, 0 , len-1); //In decreasing order.
    /* 
     *Logic : if last element is even-pos , then set it and decreement till zero.
              Afterwards , set the odd-pos from the starting till the end.
     */
    i = len-1;
    if (i%2 != 0) //Neglecting the single index case for now.
	i = i-1;
    for(i;i>=0;i-=2) {
        arr[i] = cpy_arr[j];
	j++;
    }	   
    for(i=1;i < len;i+=2) {
        arr[i] = cpy_arr[j];
	j++;
    }	    
    for (i=0;i<len;i++)
	 printf("%d ",arr[i]); 
    printf("\n");
}	
