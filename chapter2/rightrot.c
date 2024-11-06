#include <stdio.h>

unsigned rightrot(unsigned x, int n){
    int numBits = sizeof(x) * 8;

    n %= numBits;

    unsigned rightPart = x >> n;
    unsigned leftPart = x << (numBits - n);

    return rightPart | leftPart;
}

void printBinary(unsigned x){
    for (int i = 31; i >= 0; i--){
        unsigned bit = (x >> i) & 1;
        printf("%u", bit);
    }
    printf("\n");
}

int main(){
    unsigned x = 0b0011010111001;
    int n = 4;

    unsigned result = rightrot(x, n);

    printf("Initial decimal: %u\n", x);
    printf("Binary: ");
    printBinary(x);

    printf("Decimal: %u\n", result);
    printf("Binary: ");
    printBinary(result);
}