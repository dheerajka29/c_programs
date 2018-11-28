/*
 *Given an array, write a program to generate a random permutation of array elements. 
 * This question is also asked as “shuffle a deck of cards” or “randomize a given array”. 
 * Here shuffle means that every permutation of array element should equally likely.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

static void
print_arr(int * arr, int len) {
    int iter = 0;
    for (iter;iter < len ; iter++) {
        printf("%d ",arr[iter]);
    }	    
    printf("\n");
}

static void
swap(int * arr, int i , int j) {
     int temp ;
     temp = arr[i];
     arr[i] = arr[j];
     arr[j] = temp;
}	

/*
 * Based on "https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm"
 * Each element will have n permutations.
 * find a random number , and swap with the last un-visited index. 
 * Repeat , and decreement the last visited. 
 */ 
static void
randomize_arr(int * arr, int len) {
   int index = 0;
   int swap_index = 0;
   srand(time(0)); // If this is not called , then the program / rand will generate the same set of random nos.
   for (index = len-1;index > 0; index--) {
        swap_index = rand()%(index+1);
	swap(arr,index,swap_index);
   }	   
}	

int main(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int len = sizeof(arr)/sizeof(int);
    print_arr(arr,len);
    randomize_arr(arr,len);
    print_arr(arr,len);
}	

