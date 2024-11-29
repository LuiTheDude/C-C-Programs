#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_BUFFER 100

void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itoa(int n, char s[], int minWidth){
    int i = 0, sign;
    
    if (n == INT_MIN) {
        s[i++] = '8';  // Store the last digit of INT_MIN
        n = n / 10;    // Reduce INT_MIN to -214748364
    }
    
    if ((sign = n) < 0){
        n = -n;
    }
    do {
        s[i++] = n % 10 + '0';
    } while((n /= 10) > 0);

    if(sign < 0){
        s[i++] = '-';
    }

    while (i < minWidth) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}

int main(){
    char buffer[100];
    
    itoa(INT_MIN, buffer, 25);
    printf("INT_MIN: '%s'\n", buffer);
    
    itoa(12345, buffer, 25);
    printf("12345: '%s'\n", buffer);
    
    itoa(-12345, buffer, 25);
    printf("-12345: '%s\n'", buffer);

    return 0;
}