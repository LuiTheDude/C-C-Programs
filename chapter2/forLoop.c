#include <stdio.h>

int main(){

    // for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    //        s[i] = c;

    int c, lim, i = 0;
    char s[5];
    while (i < lim-1){
        c = getchar();
        if (c != '\n'){
            if(c != EOF){
                s[i] = c;
                i++;
            }
        }
    }
}