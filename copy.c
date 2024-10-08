 #include <stdio.h>
 /* copy input to output; 1st version */
 char main()
 {
    int c;
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
 }