#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int getLine(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould";   /* pattern to search for */
int position;
/* find all lines matching pattern */
int main() {
    char line[MAXLINE];
    int found = 0;
    while (getLine(line, MAXLINE) > 0)
        if ((position = strindex(line, pattern)) >= 0) {
            printf("%d\n", position);
            found++;
        }
    return found;
}