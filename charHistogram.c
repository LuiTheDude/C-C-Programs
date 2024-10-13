#include <stdio.h>

void astNum(int num){
    for (int i = 0; i < num; i++){
        printf("*");
    }
    printf("\n");
}
int main(){
    int c;
    int charsArr[52] = {0};  // Initialize all elements to 0

    while((c = getchar()) != EOF){
        if (c >= 'A' && c <= 'Z'){
            charsArr[c - 'A']++;
        }
        else if (c >= 'a' && c <= 'z'){
            charsArr[c - 'a' + 26]++;
        }
    }

    printf("Character counts:\n");
    for (int i = 0; i < 52; i++){
        if (charsArr[i] != 0 && i < 26){ // First 26 indices for uppercase letters
            printf("%c: %d\n", (i + 'A'));
            astNum(charsArr[i]);
        }  
        else if (charsArr[i] != 0 && i >= 26){ // Remaining 26 indices for lowercase letters
            printf("%c:", (i - 26 + 'a'));
            astNum(charsArr[i]);
        } 
    }
    return 0;
}
