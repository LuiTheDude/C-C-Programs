#include <stdio.h>
#include <stdbool.h> // Use stdbool.h for boolean types

#define MAXLENGTH 10000

int getText(char text[], int lengthLimit);
void checkSyntax(char text[]);

int main() {
    char text[MAXLENGTH];

    getText(text, MAXLENGTH);
    checkSyntax(text);

    printf("End of execution\n");
    return 0;
}

int getText(char text[], int lengthLimit) {
    int c, i = 0;
    while ((c = getchar()) != EOF && i < lengthLimit - 1) {
        text[i] = c;
        i++;
    }
    text[i] = '\0';
    return i;
}

void checkSyntax(char text[]) {
    int parentheses = 0;
    int brackets = 0;
    int braces = 0;

    bool doubleQuotes = false;
    bool singleQuotes = false;
    bool blockComments = false;
    bool lineComments = false;

    int i = 0;
    while (text[i] != '\0') {
        /* Check for ( [ { */
        if (!doubleQuotes && !singleQuotes && !blockComments && !lineComments) {
            if (text[i] == '(') {
                parentheses++;
            } else if (text[i] == ')') {
                parentheses--;
            }
            if (text[i] == '[') {
                brackets++;
            } else if (text[i] == ']') {
                brackets--;
            }
            if (text[i] == '{') {
                braces++;
            } else if (text[i] == '}') {
                braces--;
            }
        }

        /* Check for " ' */
        if (!blockComments && !lineComments) {
            if (text[i] == '"' && !singleQuotes) {
                doubleQuotes = !doubleQuotes; // Toggle double quotes
            } else if (text[i] == '\'' && !doubleQuotes) {
                singleQuotes = !singleQuotes; // Toggle single quotes
            }
        }

        // Check for comments
        if (!doubleQuotes && !singleQuotes) {
            if (text[i] == '/' && text[i + 1] == '/') {
                lineComments = true; // Start of line comment
            } else if (text[i] == '\n') {
                lineComments = false; // End of line comment
            } else if (text[i] == '/' && text[i + 1] == '*') {
                blockComments = true; // Start of block comment
            } else if (text[i] == '*' && text[i + 1] == '/' && blockComments) {
                blockComments = false; // End of block comment
            }
        }

        i++;
    }

    // Check for unbalanced symbols
    if (parentheses != 0) {
        printf("Error: unbalanced parentheses.\n");
    }
    if (brackets != 0) {
        printf("Error: unbalanced brackets.\n");
    }
    if (braces != 0) {
        printf("Error: unbalanced braces.\n");
    }
    if (singleQuotes) {
        printf("Error: unbalanced single quotes.\n");
    }
    if (doubleQuotes) {
        printf("Error: unbalanced double quotes.\n");
    }
    if (blockComments) {
        printf("Error: block comment not closed.\n");
    }

    // If no errors were found
    if (parentheses == 0 && brackets == 0 && braces == 0 && !singleQuotes && !doubleQuotes && !blockComments) {
        printf("No syntax errors found.\n");
    }
}