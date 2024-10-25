#include <stdio.h>

#define TAB_LENGTH 8

int main(){
    int c, linePosition = 0, numSpaces = 0;
    while ((c = getchar()) != EOF)
    {
        linePosition++;
        if (c == ' '){
            numSpaces++;
            if (linePosition % TAB_LENGTH == 0 && numSpaces > 1) {
                putchar('\t');
                numSpaces = 0;
            }
        }
        else {
            while (numSpaces){
                putchar(' ');
                numSpaces--;
            }
            if (c == '\n'){
                linePosition = 0;
            }
            putchar(c);
        }
    }
    return 0;
}