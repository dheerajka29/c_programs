/*
 * Maximum Product Subarray
 Given an array that contains both positive and negative integers, 
 find the product of the maximum product subarray. Expected Time complexity is O(n) and only O(1) extra space can be used.
 Examples:

 Input: arr[] = {6, -3, -10, 0, 2}
 Output:   180  // The subarray is {6, -3, -10}

 Input: arr[] = {-1, -3, -10, 0, 60}
 Output:   60  // The subarray is {60}

 Input: arr[] = {-2, -3, 0, -2, -40}
 Output:   80  // The subarray is {-2, -40}
 https://www.geeksforgeeks.org/maximum-product-subarray/
 * Soln 1 [On2] : 2 for-loops
 * Soln 2[Optimized]: https://ide.geeksforgeeks.org/kSvNLp
 */

#include <stdio.h>

int 
main(void) {
    int arr[] = {6, -3, -10, 0, 2};
    int len = sizeof(arr)/sizeof(len);
    int max_pos_prod = 1;
    int min_prod = 1;
    int max_prod = 1;
    int iter = 0;
    int temp = 0;
    for(iter;iter<len;iter++) {
	//Case when 0 is encountered , for further iterations,
	//initialize our variables to 1.    
        if(arr[iter] == 0){
           min_prod = 1;
	   max_prod = 1;
	}
	//Case when arr[index] is greater than 0.
	//Blindly update the pos_prod.
	//for neg_index ,If negative then update.If not negative , then previous sub-array do not have -ve.
	if(arr[iter] > 0) {
	   max_prod = arr[iter]*max_prod;
	   min_prod = min_prod == 1 ? 1:min_prod*arr[iter];
	}
	//Case when arr[index] is smaller than 0.
	//update the min_prod and then compare the min_prod
	//with max_prod and store acc.
	//finally update the min_prod with last max_prod * curr_elem.   
 	if(arr[iter] < 0) {
	   temp = max_prod;	
	   min_prod = min_prod * arr[iter];
	   max_prod = max_prod > min_prod ? max_prod : min_prod;
	   min_prod = temp*arr[iter];
	}
        max_pos_prod = max_prod > max_pos_prod ? max_prod:max_pos_prod;	
    }	   
    printf("%d\n",max_pos_prod);
    return 0; 
}	
