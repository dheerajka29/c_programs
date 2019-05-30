/*
 * https://www.geeksforgeeks.org/minimum-rotations-required-get-string/
 */ 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int
main(void) {
    int arr[26] = {};
    char str[] = "aaab";
    int len = strlen(str);
    int iter = 0;
    bool status = false;
    //Increement the hash with the characters encountered.
    for(;iter < len;iter++)
	arr[str[iter]-'a']++;
    //Now we need to check if the count in the hash is equal to
    //the string size. if it is true then all the characters of
    //the string are same , and rotation will be 1.
    //else rotation will be length of string.
    for(iter = 0;iter<len;iter++) {
	if(arr[str[iter]-'a'] == (len)){    
	   status = true;	
	   break;
	}   
    }
    if(status == true)
	printf("Single rotation\n");
    else
	printf("%d rotation required\n",len);    
    return 0;
}	
