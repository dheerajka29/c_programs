/*
 * https://www.geeksforgeeks.org/lexicographically-minimum-string-rotation/
 */ 

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

void
reverse(char * str, int low , int high) {
    while (low < high) {
        str[low] = str[low] ^ str[high];
	str[high] = str[low] ^ str[high];
	str[low] = str[low] ^ str[high];
	low++;
	high--;
    }	    
}	

void
left_rotate(char * str, int key ,int len) {
    reverse(str,0,key);
    reverse(str,key+1,len);
    reverse(str,0,len);
}	

void
swap(char * str1 , char * str2) {
   int len = strlen(str1);
   char str[len] ;
   strcpy(str,str1);
   strcpy(str1,str2);
   strcpy(str2,str);
}

int
main(void) {
    char str[] = "GEEKSFORGEEKS";
    int len = strlen(str) -1;
    char *ptr[len];
    int iter = 0;
    int j_iter = 0;
   
    memset(ptr,0,sizeof(char *) * len);
    for(;iter<=len;iter++) {
	left_rotate(str,1,len);
	ptr[iter] = strdup(str);
    }
    for(iter = 0;iter <= len;iter ++) { 
        for(j_iter = iter + 1;j_iter < len;j_iter++){
	    if(strcmp(ptr[iter],ptr[j_iter]) > 0){
               swap(ptr[iter],ptr[j_iter]);
	    } else {
	      //Skip
	    }	    
	}
    }
    printf("%s\n",ptr[0]);
    for(iter = 0;iter < len;iter++)
	free(ptr[iter]);    
    return 0;    
}	

