#include <stdio.h>

#define MAXLEN 100

int htoi(const char hexString[]);

int main(void){
    char hexString[MAXLEN];
    
    printf("Enter a hexadecimal (0x/0X is optional):\n");
    scanf("%100s", hexString);
    
    int intValue = htoi(hexString);

    if (intValue != -1)
        printf("Integer value of %s is %d\n", hexString ,intValue);
    return 0;
}

int htoi(const char hexString[]){
    int result = 0;
    int i = 0;

    if (hexString[0] == '0' && (hexString[1] == 'x' || hexString[1] == 'X')){
        i = 2;
    }

    while(hexString[i] != '\0'){
        char c = hexString[i];
        int hexValue = 0;
        if(c >= '0' && c <= '9'){
            hexValue += c - '0';
        }
        else if(c >= 'A' && c <= 'F'){
            hexValue += c - 'A' + 10;
        }
        else if(c >= 'a' && c <= 'f'){
            hexValue += c - 'a' + 10;
        }
        else{
            printf("invalid hexadecimal character %c\n", c);
        }
        result = result * 16 + hexValue;
        i++;
    }
    return result;
}