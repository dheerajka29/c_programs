/*
 * XOR of two numbers after making length of their binary representations equal
   Given two numbers say a and b. Print their XOR after making the lengths of 
   their binary representation equal by adding trailing zeros to the binary representation of smaller one.

   Examples :

   Input : a = 13, b = 5 
   Output : 7
   Explanation : Binary representation of 13 is 1101 and 
   of 5 is 101. As the length of "101" is smaller,
   so add a '0' to it making it "1010', to make 
   the length of binary representations equal. 
   XOR of 1010 and 1101 gives 0111 which is 7.

   Input : a = 7, b = 5 
   Output : 2
   Explanation : Since the length of binary representations
   of 7 i.e, 111 and 5 i.e, 101 are same, hence simply
   print XOR of a and b.
   https://www.geeksforgeeks.org/xor-two-numbers-making-length-binary-representations-equal/
 */ 

#include <stdio.h>

/*
 * Bad question : 
 * Do the following things , get the length of both the nos. 
 * calculate the difference and append 0 in the smaller one.
 * Finally , calculate the xor b/w them.
 */

int
find_count(int num) {
   int count = 0;
   while(num){
       num = num/2;
       count++;
   }	   
   return count;
}	

int
main(void) {
    int a = 7;
    int b = 5;
    int a_len = find_count(a);
    int b_len = find_count(b);
    if(a_len > b_len) {
       b <<=(a_len-b_len); 
    } else {
       a <<=(b_len - a_len);
    }	    
    printf("%d\n",b^a);
    return 0;
}	
