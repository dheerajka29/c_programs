/*
 * https://www.geeksforgeeks.org/turn-an-image-by-90-degree/
 * https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/
 * https://www.geeksforgeeks.org/rotate-matrix-90-degree-without-using-extra-space-set-2/
 */ 

#include <stdio.h>
#include <string.h>

#define ROW 3
#define COLUMN 3

int
main(void) {
    int arr[ROW][COLUMN] = {{1,2,3},
			    {4,5,6},
		   	    {7,8,9}};
    int temp_arr[ROW][COLUMN] = {{},{},{}};
    int row = 0, column = 0;
    for(column = COLUMN -1;column >= 0;column--) 
        for(row = 0; row < ROW;row++) {
	    temp_arr[COLUMN - column -1][row] =
	    arr[row][column];	    
	}
    return 0;    
}	
