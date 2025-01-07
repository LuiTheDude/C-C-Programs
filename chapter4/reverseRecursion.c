#include <stdio.h>
#include <string.h>

void reverseRec(char s[], int left, int right) {
    if (left >= right)
        return;

    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    reverseRec(s, left + 1, right - 1);
}

int main() {
    char s1[] = "1234567890";
    char s2[] = "abcdefghij";

    reverseRec(s1, 0, strlen(s1) - 1);
    reverseRec(s2, 0, strlen(s2) - 1);

    printf("%s\n", s1); // Output: 0987654321
    printf("%s\n", s2); // Output: jihgfedcba

    return 0;
}
