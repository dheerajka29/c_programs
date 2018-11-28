#include <stdio.h>

void
sum(int a,int b,int c) {
    printf("%d %d %d\n",a,b,c);
}	

/*
 * Reason : Evaluation sequence is right to left
 * In GCC , while evaluation it checks if the
 * operator is pre or post . If it is pre , then
 * changed value is reflected to specifier at the last.
 * If the operator is post , changed value will be reflected 
 * instantly.
 */ 
int main(void) {
    int a = 5;
    sum(++a,a++,++a);
}	
