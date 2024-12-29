#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

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

// Clear the stack
void clearStack() {
    stackPosition = 0;
    printf("Stack cleared.\n");
}

// Print the top element of the stack without popping
void printTopElement() {
    if (stackPosition > 0) {
        printf("Top element: %.8g\n", value[stackPosition - 1]);
    } else {
        printf("Stack is empty.\n");
    }
}

// Duplicate the top element of the stack
void duplicateTopElement() {
    if (stackPosition > 0 && stackPosition < MAXVAL) {
        double top = value[stackPosition - 1];
        push(top);
        printf("Duplicated top element: %.8g\n", top);
    } else {
        printf("Error: Cannot duplicate top element.\n");
    }
}

// Swap the top two elements of the stack
void swapTopElements() {
    if (stackPosition > 1) {
        double temp = value[stackPosition - 1];
        value[stackPosition - 1] = value[stackPosition - 2];
        value[stackPosition - 2] = temp;
        printf("Swapped top two elements.\n");
    } else {
        printf("Error: Not enough elements to swap.\n");
    }
}

// Main RPN calculator function
int main() {
    int type;
    double op2;
    char s[MAXOP];

    printf("Enter RPN expressions (e.g., '3 4 +'),\nEnter C to clear stack,\nP to print top element without popping,\nD to duplicate top element,\nS to swap top 2 elements:\n");

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case 'C':
                clearStack();
                break;
            case 'P':
                printTopElement();
                break;
            case 'D':
                duplicateTopElement();
                break;
            case 'S':
                swapTopElements();
                break;
            case 's': //for sin
                push(sin(pop()));
                break;
            case 'c': //for cos
                push(cos(pop()));
                break;
            case 't': //for tan
                push(tan(pop()));
                break;
            case 'p': //for power
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case 'e': //for exponent
                push(exp(pop()));
                break;
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
