#include <stdio.h>

int main (void) {
    int array[5] = {0,1,2,3,4};
    int find_sum = 5;
    int len = 5;
    int sum = 0;
    int iter = 0;
    int start = 0;
    for (iter;iter < len;iter++) {
	 sum += array[iter];
	 if(sum > find_sum) {
            		 
	    sum -=array[iter];
	 }
         if(sum == find_sum) {
            return 0;
	    //return the indexes
	 }	 
    }	    
    return 1;
}	
