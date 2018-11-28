/*
 * https://www.geeksforgeeks.org/efficient-method-2s-complement-binary-string/
 * Efficient method for 2’s complement of a binary string
 * Given a Binary Number as string, print its 2’s complements.

 * 2’s complement of a binary number is 1 added to the 1’s complement 
 * of the binary number. Note that 1’s complement is simply flip of given binary number.
 * Examples:

 * 2's complement of "0111" is  "1001"
 * 2's complement of "1100" is  "0100"
 */

#include <iostream>
#include <stdbool.h>

using namespace std;

string
complement_string(string s) {
    int len = s.length();
    int iter = len - 1;
    bool is_found = false;

    for(; iter>=0; iter--) { 
       if(s[iter] == '1'){
	  break;     
       }	       
    }
    if(iter == -1){
       return '1' + s;
    }
    iter = iter - 1;
    for(;iter>=0;iter--){
        if(s[iter] == '0'){
	   s[iter] = '1';
	} else {
	   s[iter] = '0';
	}	
    }
    return s;    
}	

int
main(void) {
    string num = "0000";
    cout<<complement_string(num)<<"\n";
    return 0;
}	
