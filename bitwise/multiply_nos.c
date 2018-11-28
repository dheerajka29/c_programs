/*
 * https://www.geeksforgeeks.org/russian-peasant-multiply-two-numbers-using-bitwise-operators/
 */ 

#include <stdio.h>

int
main(void) {
    int a = 7;
    int b = 5;
    int res = 0;
    /*while(b){
       res += a;
       b--; 
    }*/
    while(b){
	  //This means no. is odd. When you multiply by a odd no.
	  // then it is 1,3,5,7 etc.  
          if(b & 1){
             res = res + a; 
	  }		  
	  a <<=1;
	  b >>=1;
    }	    
    printf("%d\n",res);
    return 0; 
}	
