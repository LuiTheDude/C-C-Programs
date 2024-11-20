#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[]){
    int i = 0;
    int j = 0;
    while (s1[i] != '\0') {
        // Handle valid ranges like a-z, A-Z, or 0-9
        if ((islower(s1[i]) || isupper(s1[i]) || isdigit(s1[i])) &&
            s1[i+1] == '-' &&
            (islower(s1[i+2]) || isupper(s1[i+2]) || isdigit(s1[i+2])) &&
            s1[i] < s1[i+2]) {
            
            for (int c = s1[i]; c <= s1[i+2]; c++) {
                s2[j++] = c;
            }
            i += 3; // Skip over the range
        } else {
            // Copy single characters or invalid range delimiters
            s2[j++] = s1[i++];
        }
    }
    s2[j] = '\0'; // Null-terminate the result
}

int main(){
    char s1[1000] = "a-z0-9";
    char s2[1000];

    expand(s1, s2);
    printf("%s\n", s2);
}