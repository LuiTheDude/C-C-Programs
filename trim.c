#include <stdio.h>
/* copy input to output; 1st version */
int main()
{
    int c;

    int blanks = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' '){
            ++blanks;
            if (blanks <= 1){
                putchar(c);
            }
            else if (blanks > 1){
                continue;
            }
        }
        else {
            blanks = 0;
            putchar(c);
        }
    }
}