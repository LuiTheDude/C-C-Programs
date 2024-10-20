#include <stdio.h>

int add(int x, int y);

int main(){
    int x = 10;
    int y = 3;

    int result = add(x, y);
    printf("%d", result);
}

int add(int x, int y){
    return x + y;
}