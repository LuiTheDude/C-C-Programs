#include <stdio.h>

#define MAXLEN 10000

void escape(char s[], char t[]){
    int c;
    int i = 0;
    int j = 0;
    while((c = t[i]) != '\0'){
        switch(c){
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = c;
                break;
        }
        i++;
    }
    s[j] = '\0';
}

int main(){
    char s[MAXLEN];
    char t[MAXLEN] = "hello,\tthis\nis an\nexample\ttext.";

    escape(s, t);
    printf("Initial text:%s\nFinal text:%s\n", t, s);

    return 0;
}