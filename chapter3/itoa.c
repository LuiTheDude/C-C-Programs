#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]){
    int sign, i = 0;
    if((sign = n) < 0){
        n = -n;
    }
    do{
        s[i++] = n % 10 + '0';
    } while(n /= 10 > 0);
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main(){
    int n = 123124;
    char s[30];
    itoa(n, s);
    printf("%s\n", s);
    
    return 0;
}