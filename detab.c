#include <stdio.h>

#define TAB_LENGTH 8

int main(){
    int c, numSpaces;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t'){
            numSpaces = TAB_LENGTH;    
            while (numSpaces)
            {
                putchar(' ');
                --numSpaces;
            }
        }
        else{
            putchar(c);
        }
    }
    return 0;
}