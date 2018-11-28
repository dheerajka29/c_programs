#include <stdio.h>

static void
merge_sub_arr(int * arr, int left,int right,int mid) {
     int l = mid - left +1;
     int r = right - mid ;
     int left_arr[l] ;
     int right_arr[r] ;
     int index;
     for(index = 0; index < l; index++){
         left_arr[index] = arr[left + index];
     }	     
     for(index = 0;index < r; index++ )
	 right_arr[index] = arr[mid + index + 1];
     int i = 0, j = 0, k = left;
     while (i < l && j < r) {
            if(left_arr[i] < right_arr[j]){
	       arr[k] = left_arr[i];
	       k++;
	       i++;
	    } else {
	      arr[k] = right_arr[j];
	      k++;
	      j++; 
	    }	    
     }
     while (i < l) {
	 arr[k] = left_arr[i];
	 k++;
	 i++;
     }		 
     while(j < r){ 
	 arr[k] = right_arr[j]; 
         k++;
         j++;	 
     }
}     

void
merge_sort(int * arr, int start, int end) {
     if (start < end) {
         int mid = (start + end)/2;
	 merge_sort(arr,start,mid); // 1 (0,2) -> ((0,1),(2,2)) -> (0,0) (1,1) (0,1,0)
	 merge_sort(arr,mid + 1,end);//1 (3,5)
	 merge_sub_arr(arr,start,end,mid);
     }	     
}	
#if 0
int main(void) {
    int arr[] = {3,8,12,11,2,5};
    int size = sizeof(arr)/sizeof(int);
    merge_sort(arr,0,size-1);
    int index;
    for (index = 0;index < size; index++)
	 printf("Val at %d is %d\n",index,arr[index]);
    return 0;
}
#endif


