#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itob(int n, char s[], int base){
    int i = 0, sign;
    
    if ((sign = n) < 0){
        n = -n;
    }
    do {
        int remainder = n % base;
        s[i++] = (remainder < 10) 
                   ? remainder + '0'
                   : remainder - 10 + 'A';
    } while((n /= base) > 0);

    if(sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main(){
    char buffer[20];
    
    itob(564621, buffer, 10);
    printf("564621: %s\n", buffer);
    
    itob(654865, buffer, 16);
    printf("654865: %s\n", buffer);
    
    itob(-12345, buffer, 8);
    printf("-12345: %s\n", buffer);

    return 0;
}