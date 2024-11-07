#include <stdio.h>
/* bitcount:  count 1 bits in x */
int bitcount(unsigned x)
{
    int b;
    while(x != 0){
        x &= (x - 1); //this deletes the rightmost 1-bit in x
        b++;
    }
    return b;
}

int main(){
    printf("%d\n", bitcount(0b1010101010));
}