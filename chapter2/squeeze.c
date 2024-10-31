#include <stdio.h>
#define MAXLEN 1000

void squeeze(char string1[], char string2[]);
int checkForChar(char string[], int c);

int main(){
    char string1[MAXLEN] = "lorem ipsum dolor sit amet";
    char string2[MAXLEN] = "lsat";

    squeeze(string1, string2);
    printf("%s\n", string1);
    return 0;
}

void squeeze(char string1[], char string2[]){
    int i;
    int j;
    int c;
    for(i = j = 0; string1[i] != '\0'; i++){
        c = string1[i];
        if(!checkForChar(string2, c)){
            string1[j++] = string1[i];
        }
    }
    string1[j] = '\0';
}

int checkForChar(char string[], int c){
    int i = 0;
    int count = 0;
    while(string[i] != '\0'){
        if (string[i++] == c)
            count++;
    }
    return count;
}
