#include <stdio.h>

int main(){
    #define IN 1
    #define OUT 0

    int c, nl, nw, nc, state;

    state = OUT;
    nl = nc = nw = 0;
    while ((c = getchar()) != EOF){
        ++nc;
        if (c == '\n'){
            ++nl;
        }
        if (c == '\n' || c == '\t' || c ==' '){
            state = OUT;
        }
        else if(state == OUT){
            state = IN;
            ++nw;
        }   
    }
    printf("Newlines: %d\nWords: %d\nCharacters: %d\n", nl, nw, nc);
}