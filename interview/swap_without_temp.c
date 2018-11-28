#include <stdio.h>

int
main(void) {
    unsigned int a = 9;
    unsigned int b = 75;
    a = a^b;
    b = b^a;
    a = a^b;
    return 0;
}	
