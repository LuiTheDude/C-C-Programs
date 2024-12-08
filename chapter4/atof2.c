#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof2(char s[]){
    double value, power;
    int i, sign, exponentSign = 1, exponentPower = 0;
    
    for (i = 0; isspace(s[i]) == ' '; i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    
    if (s[i] == '+' || s[i] == '-')
        i++;
    
    for (value = 0.0; isdigit(s[i]); i++)
        value = value * 10.0 + (s[i] - '0');
    
    if(s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++){
        power = power * 10;
        value = value * 10.0 + (s[i] - '0');
    }
    if (s[i] == 'e' || s[i] == 'E'){
        i++;
        if(s[i] == '-' || s[i] == '+'){
            exponentSign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while(isdigit(s[i])){
            exponentPower = exponentPower * 10 + (s[i] - '0');
            i++;
        }
    }

    return (sign * value / power) * pow(10, exponentSign * exponentPower);
}

int main(){
    char doubleString1[] = "3123.32e2";
    char doubleString2[] = "3123.32678";
    char doubleString3[] = "3.2e-4";

    double double1 = atof2(doubleString1);
    double double2 = atof2(doubleString2);
    double double3 = atof2(doubleString3);

    printf("\"%s\":   %f\n", doubleString1, double1);
    printf("\"%s\":   %f\n", doubleString2, double2);
    printf("\"%s\":   %f\n", doubleString3, double3);
}