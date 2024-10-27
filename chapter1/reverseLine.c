#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
void reverse(char line[], int len);

int main(){
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0){
        reverse(line, len);
    }

    return 0;
}

int getLine(char line[], int maxline){
    int c, i;

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++){
        line[i] = c;
    }

    if (c == '\n'){
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}

void reverse(char line[], int len){
    int frontPtr, backPtr;
    backPtr = len - 1;

    char newLine[len + 1];

    for(frontPtr = 0; frontPtr < len; frontPtr++, backPtr--){
        newLine[frontPtr] = line[backPtr];
    }

    newLine[len] = '\0';

    printf("%s\n", newLine);
}