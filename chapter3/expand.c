#include <stdio.h>
#include <ctype.h>

void expand(s1, s2){
    int i = 0;
    int j = 0;
    if (s1[i] == '-'){
        s2[j] = '-';
        i++;
        j++;
    }
    if (islower(s1[i]) && s1[i+1] == '-' && islower(s1[i+2])){
        for(int c = s2[i]; i != s[i+2]; c++){
            s2[j++] = c;
        }
    }
    if (isupper(s1[i]) && s1[i+1] == '-' && isupper(s1[i+2])){
        for(int c = s2[i]; i != s[i+2]; c++){
            s2[j++] = c;
        }
    }
    if (isdigit(s1[i]) && s1[i+1] == '-' && isdigit(s1[i+2])){
        for(int c = s2[i]; i != s[i+2]; c++){
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}

int main(){
    char s1[1000] = "a-z0-9";
    char s2[1000];

    expand(s1, s2);
    printf("%s\n", s2);
}