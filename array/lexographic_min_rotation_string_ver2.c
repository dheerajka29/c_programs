/*
 * https://www.geeksforgeeks.org/lexicographically-smallest-rotated-sequence-set-2/
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


/*
 * This function will pick the current minimum as well as
 * the challenger for the minimum. 
 * Now we will traverse whole string . If at any point , we
 * found that the either challenger index or curr index is smaller
 * ,then return true(curr remains small) or false(challenger becomes small).
 */ 
bool
comparator_func(char * str , int curr_min , 
		int challenger , int len) {
    int iter = 0;
    int x = curr_min;
    int y = challenger;
    for(;iter < len;iter++) {
        if(str[x] < str[y])
	   return true;
        else if(str[x] > str[y])	
	   return false;
        else {
	   x = (x + 1)%len;
	   y = (y + 1)%len;
	}	
    }
    return true;    
}	

/*
 * This API will call the comparator_func(see edt above.)
 * On the basis of its result , it will store the new minimum.
 * Once whole length is traversed , we will print the minimum
 * string starting from curr_min to the end.
 */ 

void
helper_func(char * str , int len) {
    int iter = 1;
    int curr_min = 0;
    for(;iter < len;iter++) {
        if(comparator_func(str,curr_min,iter,len) == false)
	   curr_min = iter;	
    }
    for(iter = 0;iter < len;iter++) {
        printf("%c",str[(curr_min+iter)%len]);
    }
    printf("\n");    
}	

int
main(void) {
   char *str = "dhananjay";
   int len = strlen(str);
   helper_func(str,len);
   return 0;
}	
