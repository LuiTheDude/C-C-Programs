#include <stdio.h>
#define swap(t, x, y) do{\
    t temp = x; \
    x = y; \
    y = temp; \
    } while(0)

int main(){
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(int, a, b);
    printf("After swap: a = %d, b = %d\n", a, b);

    double x = 1.5, y = 3.7;
    printf("Before swap: x = %f, y = %f\n", x, y);
    swap(double, x, y);
    printf("After swap: x = %f, y = %f\n", x, y);

    char c1 = 'A', c2 = 'Z';
    printf("Before swap: c1 = %c, c2 = %c\n", c1, c2);
    swap(char, c1, c2);
    printf("After swap: c1 = %c, c2 = %c\n", c1, c2);

    return 0;
}

