#include <stdio.h>

#define MAXLINE 50   /* maximum input line length */
int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main() {
    int len;               /* current line length */
    int max;               /* maximum length seen so far */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    
    max = 0;

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
            printf("Length: %d\n", max);
        }
    }

    if (max > 0) {  /* there was a line */
        printf("Longest line: %s", longest);
    }

    return 0;
}

/* getLine:  read a line into s, return length  */
int getLine(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    while(c != EOF && c != '\n'){
        ++i;
        c = getchar();
    }
    
    return i;
}

/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
