/*
 * Link : https://www.geeksforgeeks.org/check-binary-representation-given-number-complement-anagram/
 * Given a positive number you need to check whether it’s complement and the number are anagrams or not.

   Examples:

   Input : a = 4294967295
   Output : Yes
   Binary representation of 'a' and it's
   complement are anagrams of each other

   Input : a = 4
   Output : No
 */

#include <stdio.h>
#include <inttypes.h>

int
main(void) {
    uint64_t num = 42;
    int len = sizeof(num) *8;
    len = len/2;
    int count = 0;
    while(num){
	  if(num&1)
	     count++;
	  num>>=1;
    }
    if((count ^ len) == 0)
       printf("Nos are anagram\n");
    else
       printf("Nos are not anagram\n");
    return 0;    
}	
