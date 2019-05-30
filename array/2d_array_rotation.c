/*
 * https://www.geeksforgeeks.org/rotate-matrix-elements/
 */ 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ROW 3
#define COLUMN 3


#if 0
// A function to rotate a matrix mat[][] of size R x C. 
// Initially, m = R and n = C 
void rotatematrix(int m, int n, int mat[ROW][COLUMN]) { 
    int row = 0, col = 0; 
    int prev, curr; 
    /* 
       row - Staring row index 
       m - ending row index 
       col - starting column index 
       n - ending column index 
       i - iterator 
    */
    while (row < m && col < n) 
    { 
  
        if (row + 1 == m || col + 1 == n) 
            break; 
  
        // Store the first element of next row, this 
        // element will replace first element of current 
        // row 
        prev = mat[row + 1][col]; 
  
         /* Move elements of first row from the remaining rows */
        for (int i = col; i < n; i++) 
        { 
            curr = mat[row][i]; 
            mat[row][i] = prev; 
            prev = curr; 
        } 
        row++; 
  
        /* Move elements of last column from the remaining columns */
        for (int i = row; i < m; i++) 
        { 
            curr = mat[i][n-1]; 
            mat[i][n-1] = prev; 
            prev = curr; 
        } 
        n--; 
  
         /* Move elements of last row from the remaining rows */
        if (row < m) 
        { 
            for (int i = n-1; i >= col; i--) 
            { 
                curr = mat[m-1][i]; 
                mat[m-1][i] = prev; 
                prev = curr; 
            } 
        } 
        m--; 
  
        /* Move elements of first column from the remaining rows */
        if (col < n) 
        { 
            for (int i = m-1; i >= row; i--) 
            { 
                curr = mat[i][col]; 
                mat[i][col] = prev; 
                prev = curr; 
            } 
        } 
        col++; 
    } 
}  

#endif
int
main(void) {
    int arr[ROW][COLUMN] = {{1,2,3},
    			    {4,5,6},
    			    {7,8,9}};
    int row_top = 0,row_down = ROW-1,
	column_left = 0,column_right = COLUMN-1;
    int iter = 0;
    int prev = 0;
    int curr = 0;

    prev = arr[row_top+1][column_left];
    while(true) {
        if(row_top == row_down == column_left == column_right)
	   break;	
	if(row_top > row_down ||
	   column_right < column_left)
	   break;
	for(iter = column_left;iter <= column_right;iter++) {
	    curr = arr[row_top][iter];
	    arr[row_top][iter] = prev;
	    prev = curr; 
	}
        row_top++;
	if(row_top > row_down ||
           column_right < column_left)
           break;
        for(iter = row_top;iter <= row_down;iter++) {
	    curr = arr[iter][column_right];
	    arr[iter][column_right] = prev;
	    prev = curr; 
	}
        column_right--;
	if(row_top > row_down ||
           column_right < column_left)
           break;
        for(iter = column_right;iter >=column_left;iter--) {
	    curr = arr[row_down][iter];
	    arr[row_down][iter] = prev;
	    prev = curr;
	}	
	row_down--;
	if(row_top > row_down ||
           column_right < column_left)
           break;
	for(iter = row_down;iter >=row_top;iter--) {
	    curr = arr[iter][column_left];
	    arr[iter][column_left] = prev;
	    prev = curr;
	}	
	column_left++;
    }
    return 0;    
}	
