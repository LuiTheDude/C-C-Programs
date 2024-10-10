#include <stdio.h>
/* copy input to output; 1st version */
char main()
{
    int c;

    int blanks = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\b'){
            ++blanks;
            if (blanks <= 1){
                putchar(c);
            }
            else if (blanks > 1){
                blanks = 0;
                continue;
            }
        }
        else {
            putchar(c);
        }
    }
}