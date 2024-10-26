#include <stdio.h>

#define LINE_LENGTH 50

int main(){
    int c;
    int currentLineLength = 0;
    while ((c = getchar()) != EOF){
        currentLineLength++;
        if(currentLineLength > LINE_LENGTH && (c == '\t' || c == ' ')){
            putchar('\n');
            currentLineLength = 0;
        }
        else if(currentLineLength > (LINE_LENGTH + 10)){
            putchar('-');
            putchar('\n');
            currentLineLength = 0;
        }
        else {
            putchar(c);
        }
    }
}