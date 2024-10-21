#include <stdio.h>

#define MINLINE 80
#define MAXLINE 1000
int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
    int i = 0; // index for resultLines
    int len; // current line length
    char line[MAXLINE]; // current input line
    char resultLines[MAXLINE][MAXLINE]; //list of final lines

    while ((len = getLine(line, MAXLINE)) > 0) {
        printf("Length: %d\n", len);
        if (len > MINLINE) {
            copy(resultLines[i], line); // Use copy function to store the line
            ++i; // Increment index to store the next line
        }
    }
    for (int j = 0; j < i; ++j){
        printf("%s", resultLines[j]);
    }

    return 0;
}


/* getLine:  read a line into line[], return length  */
int getLine(char line[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    while(c != EOF && c != '\n'){
        ++i;
        c = getchar(); 
    }
    
    return i;
}


/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    while ((*to++ = *from++) != '\0') // copy characters from from to to
        ;
}