#include <stdio.h>

void printBinary(unsigned n) {
    // Assuming we are dealing with 8 bits (you can adjust this as needed)
    for (int i = 7; i >= 0; i--) {  // 7 for an 8-bit number
        unsigned bit = (n >> i) & 1; // Extract the i-th bit
        printf("%u", bit);
    }
    printf("\n");
}

unsigned invert(unsigned x, int p, int n){
    // create mask for n bits from position p is set to 1
    unsigned mask = ((1 << n) - 1) << (p + 1 - n); 
    return x ^ mask;

}

int main(){
    unsigned result = invert(0b10101010, 4, 3);
                             //10110110
    printf("Decimal: %u\n", result);
    printf("Binary: ");
    printBinary(result);
}