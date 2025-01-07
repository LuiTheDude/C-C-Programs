#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itoa_recursive(int n, char s[], int *index) {
    // Handle the case for INT_MIN
    if (n == INT_MIN) {
        s[(*index)++] = '-';
        s[(*index)++] = '2';
        itoa_recursive(147483648, s, index);  // Process the remaining digits
        return;
    }

    if (n < 0) {
        s[(*index)++] = '-';
        n = -n;
    }

    if (n / 10) {
        itoa_recursive(n / 10, s, index);
    }

    s[(*index)++] = n % 10 + '0';
}

void itoa(int n, char s[]) {
    int index = 0;
    itoa_recursive(n, s, &index);
    s[index] = '\0';
}

int main() {
    char buffer[20];

    itoa(INT_MIN, buffer);
    printf("INT_MIN: %s\n", buffer);

    itoa(12345, buffer);
    printf("12345: %s\n", buffer);

    itoa(-12345, buffer);
    printf("-12345: %s\n", buffer);

    return 0;
}
