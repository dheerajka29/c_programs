/*
 * Link : https://www.geeksforgeeks.org/set-left-unset-bit/
 */ 

#include <stdio.h>

int
main(void) {
   int num = 355;
   int temp = num;
   int prev = 0;
   int count = 0;
   while(temp) {
       if((temp & 1) == 0){
           prev = count;
       }
       count++;
       temp >>=1;       
   }	   
   printf("%d\n",num ^ 1<<prev);
   return 0;
}	
