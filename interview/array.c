#include <stdio.h>

int main (void) {
    int arr[5] = {0,1,2,3,4};
    int no_rot = 2;
    int len = 5;
    int temp;
    int ind = 0 , i;
    for (ind;ind<no_rot;ind++) {
         for (i = 0;i < (len - 1);i++) {
              temp = arr[i];
	      arr[i] = arr[i+1];
	      arr[i+1] = temp;
         }
    }
    for(ind = 0;ind < len;ind++)
        printf("%d element is %d \n",ind,arr[ind]);
}	
