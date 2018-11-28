/*
 * https://www.geeksforgeeks.org/toggle-case-string-using-bitwise-operators/
 * Toggle case of a string using Bitwise Operators
   Given a string, write a function that returns toggle case of a string using the bitwise operators in place.

   In ASCII codes, character ‘A’ is integer 65 = (0100 0001)2, while 
   character ‘a’ is integer 97 = (0110 0001)2. Similarly, character ‘D’ is integer 68 = (0100 0100)2, while character ‘d’ is integer 100 = (0110 0100)2.

   As we can see, only sixth least significant bit is different in ASCII code of ‘A’ and ‘a’. 
   Similar behavior can be seen in ASCII code of ‘D’ and ‘d’. Therefore, we need to toggle this bit for toggling case.

   Examples:

   Input : "GeekSfOrgEEKs"
   Output : "gEEKsFoRGeekS"

   Input : "StRinG"
   Output : "sTrINg"
 */

#include <stdio.h>
#include <string.h>
int
main(void) {
    char str[14] = "GeekSfOrgEEKs";
    int len = strlen(str);
    int iter = 0;
    for(;iter < len; iter++) {
        str[iter] = ((int)(str[iter])) ^ (1<<5);
    }
    printf("%s\n",str);
    return 0;    
}	


