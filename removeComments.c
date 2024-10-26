#include <stdio.h>

#define MAXLENGTH 10000
#define TRUE (1 == 1)
#define FALSE !TRUE

int getString(char string[], int lengthLimit);
void removeComments(char string[], char noCommentsString[]);

int main() {
    char string[MAXLENGTH];
    char noCommentsString[MAXLENGTH];
    
    /*
    another test comment, but now 
    a
    multiple
    line
    one
    */
    
    getString(string, MAXLENGTH);
    removeComments(string, noCommentsString);
    printf("%s", noCommentsString);

    return 0;
}

int getString(char string[], int lengthLimit) {
    int c, i = 0;
    while ((c = getchar()) != EOF && i < lengthLimit - 1) {
        string[i] = c;
        i++;
    }
    string[i] = '\0';
    return i;
}

void removeComments(char string[], char noCommentsString[]) {
    int inBlockComment = FALSE;
    int inLineComment = FALSE;
    int inQuote = FALSE;

    int i = 0, j = 0;
    while (string[i] != '\0') {
        if (!inBlockComment && !inLineComment) {
            // Handle quotes
            if (!inQuote && string[i] == '"') {
                inQuote = TRUE; 
            } else if (inQuote && string[i] == '"') {
                inQuote = FALSE;
            }
        }

        if (!inQuote) {
            // Start of block comment
            if (!inLineComment && !inBlockComment && string[i] == '/' && string[i + 1] == '*') {
                inBlockComment = TRUE;
                i += 2; // Skip "/*"
                continue;
            }

            // End of block comment
            if (inBlockComment && string[i] == '*' && string[i + 1] == '/') {
                inBlockComment = FALSE;
                i += 2; // Skip "*/"
                continue;
            }

            // Start of line comment
            if (!inBlockComment && !inLineComment && string[i] == '/' && string[i + 1] == '/') {
                inLineComment = TRUE;
                i += 2; // Skip "//"
                continue;
            }
        }

        // Handle new line (end of line comment)
        if (inLineComment) {
            if (string[i] == '\n') {
                inLineComment = FALSE; // End of line comment
            }
            i++; // Move to the next character
            continue; // Skip the rest of this loop iteration
        }

        // Only copy characters that are not in comments
        if (!inBlockComment && !inLineComment) {
            noCommentsString[j++] = string[i];
        }
        
        i++; // Move to the next character
    }

    noCommentsString[j] = '\0'; // Null-terminate the result string
}
