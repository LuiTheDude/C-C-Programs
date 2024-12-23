#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXOP   100
#define NUMBER  '0'
#define MAXVAL  100
#define BUFSIZE 100

char buffer[BUFSIZE];
int bufferPosition = 0;

int stackPosition = 0;
double value[MAXVAL];

// Push a number onto the stack
void push(double f) {
    if (stackPosition < MAXVAL) {
        value[stackPosition++] = f;
        printf("Debug: Pushed %g, stackPosition=%d\n", f, stackPosition);
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

// Pop a number from the stack
double pop(void) {
    if (stackPosition > 0) {
        double result = value[--stackPosition];
        printf("Debug: Popped %g, stackPosition=%d\n", result, stackPosition);
        return result;
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

// Get a (possibly pushed back) character
int getch(void) {
    return (bufferPosition > 0) ? buffer[--bufferPosition] : getchar();
}

// Push a character back onto the buffer
void ungetch(int c) {
    if (bufferPosition >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buffer[bufferPosition++] = c;
    }
}

// Get the next operator or numeric operand
int getop(char s[]) {
    int i, c;

    // Skip spaces and tabs
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-') {
        return c; // Not a number
    }

    i = 0;
    if (c == '-') { // Check for negative numbers
        int next = getch();
        if (!isdigit(next) && next != '.') {
            ungetch(next); // Not a number, return '-'
            return '-';
        }
        s[++i] = c = next;
    }

    // Collect integer part
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    // Collect fractional part
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
}

// Main RPN calculator function
int main() {
    int type;
    double op2;
    char s[MAXOP];

    printf("Enter RPN expressions (e.g., '3 4 +'):\n");

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
