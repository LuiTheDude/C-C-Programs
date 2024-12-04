#include <stdio.h>
/* strindex:  return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
    int i, j, k;
    int pos = -1;  // Store the rightmost position of t in s

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        // If the entire string t is found in s, update pos
        if (k > 0 && t[k] == '\0')
            pos = i;
    }

    return pos;
}