#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXOP   100
#define NUMBER  '0'
#define MAXVAL  100

int stackPosition = 0; //stack position
double value[MAXVAL];

void push(double f){
    if (stackPosition < MAXVAL)
        value[stackPosition++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}
double pop(void){
    if (stackPosition > 0)
        return value[--stackPosition];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

#define BUFSIZE 100

char buffer[BUFSIZE];
int bufferPosition = 0;

int getch(void){
    return (bufferPosition > 0) ? buffer[--bufferPosition] : getchar();
}
void ungetch(int c){
    if (bufferPosition >= BUFSIZE)
        printf("ungetch: too many charecters\n");
    else 
        buffer[bufferPosition++] = c;
}

int getop(char s[]){
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[i++] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int main(){
    int type;
    double op2;
    char s[MAXOP];
    
    while((type = getop(s)) != EOF){
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
                else printf("error: zero divisor\n");
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