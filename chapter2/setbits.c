#include <stdio.h>

void printBinary(unsigned n) {
    // Assuming we are dealing with 8 bits (you can adjust this as needed)
    for (int i = 7; i >= 0; i--) {  // 7 for an 8-bit number
        unsigned bit = (n >> i) & 1; // Extract the i-th bit
        printf("%u", bit);
    }
    printf("\n");
}

unsigned setbits(unsigned x, int p, int n, unsigned y){
    //creates mask for n bits starting at position p
    unsigned mask = ~(~0 << n) << (p + 1 - n);

    //applies mask
    x = x & ~mask;

    //extractsrightmost n bits of y and sets them to position p
    unsigned yBits = (y & ~(~0 << n)) << (p + 1 - n);
    
    //combines x and y
    return x | yBits;
}

int main(){
    unsigned result = setbits(0b11010111, 4, 2, 0b00000000);

    printf("Decimal: %u\n", result);
    printf("Binary: ");
    printBinary(result);
}