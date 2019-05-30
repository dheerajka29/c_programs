#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int
main(void) {
    int arr[] = {1,3,5,7,9};
    int len = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    int temp_arr[2*len];
    int iter = 0;

    memset(temp_arr,0,sizeof(temp_arr));
    for(;iter < len;iter++) {
        temp_arr[iter] = arr[iter] ;
	temp_arr[iter + len] = arr[iter];
    }
    iter = (k%len);
    for(;iter < (k%len) + len;iter++)
	printf("%d ",temp_arr[iter]);
    printf("\n");
    k = 3;   
    iter = (k%len);
    for(;iter < (k%len) + len;iter++)
        printf("%d ",temp_arr[iter]);
    printf("\n"); 
    k = 4;
    iter = (k%len);
    for(;iter < (k%len) + len;iter++)
        printf("%d ",temp_arr[iter]);
    printf("\n");
    return 0;     
}	
