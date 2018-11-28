#include <stdarg.h>
#include <stdio.h>

int sum(int num_args,...) {
    va_list vp ;
    int i = 0;
    int sum;
    va_start(vp,num_args);
    for (i;i < num_args;i++) {
         sum += va_arg(vp,int);
    }	    
    va_end(vp);
    return sum;
}	

int main (void) {
   int a = 5;
   int b = 10;
   printf("Sum is %d\n",sum(3,5,10,15));
}	
