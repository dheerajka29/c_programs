/*
 * https://www.geeksforgeeks.org/sort-elements-by-frequency/
 * Sort elements by frequency | Set 1
 * Print the elements of an array in the decreasing frequency if 2 numbers have same frequency then print the one which came first.

 * Examples:

   Input:  arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
   Output: arr[] = {8, 8, 8, 2, 2, 5, 5, 6}

   Input: arr[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8}
   Output: arr[] = {8, 8, 8, 2, 2, 5, 5, 6, -1, 9999999}
 *
 */

#include <stdio.h>

/*
 * Sort the array first.
 * Afterwards , arrange them such that largest is in odd position . when those are filled , 
 * fill the even from the smallest index. 
 */ 
int 
main() {
    int arr[] = {2, 5, 2, 8, 5, 6, 8, 8};
    int len = sizeof(arr)/sizeof(int);
    /*
     * Step 1. Traverse the array. If arr[index] is
     * not present in LinkedList , add it , else increement the 
     * existing count.
     * Step 2. Traverse the LinkedList, and print according to the count.
     */ 
}	
