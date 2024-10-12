#include <stdio.h>

int main() {
    int c;
    int lengthCounter = 0;
    int lengthsArray[25];

    for (int i = 0; i < 25; i++) {
        lengthsArray[i] = 0;
    }

    while ((c = getchar()) != EOF) {

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            lengthCounter++;
        } 
        else {
            if (lengthCounter > 0) {
                lengthsArray[lengthCounter - 1]++;
                lengthCounter = 0;
            }
        }
    }
    printf("Word lengths:\n");
    for (int i = 0; i < 25; i++) {
        if (lengthsArray[i] != 0) {
            printf("%d: %d\n", (i + 1), lengthsArray[i]);
        }
    }
    return 0;
}
