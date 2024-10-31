#include <stdio.h>
#define MAXLEN 100

int any(char string1[], char string2[]);
int checkForChar(char string[], int c);


int main(){
    char string1[MAXLEN] = "lorem ipsum dolor sit amet";
    char string2[MAXLEN] = "zzzzts";
    char string3[MAXLEN] = "zyhj";    

    int i = any(string1, string2);
    int j = any(string1, string3);

    printf("For string1 and string2: %d\nFor string1 and string3: %d\n", i, j);
}

int any(char string1[], char string2[]){
    int i, c;

    for(i = 0; string1[i] != '\0'; i++){
        c = string1[i];
        if(checkForChar(string2, c))
            return i;
    }
    return -1;
}

int checkForChar(char string[], int c){
    int i = 0;
    while(string[i] != '\0'){
        if (string[i] == c)
            return 1;
        i++;
    }
    return 0;
}