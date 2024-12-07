#include <stdio.h>
#include <ctype.h>

double atof(char s[]){
    double value, power;
    int i, sign;
    
    for (i = 0; isspace(s[i]) == ' '; i++);
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
    return sign * value / power;
}

int main(){
    char doubleString1[] = "3123.32";
    char doubleString2[] = "3123.32678";
    char doubleString3[] = "3.2";

    double double1 = atof(doubleString1);
    double double2 = atof(doubleString2);
    double double3 = atof(doubleString3);

    printf("\"%s\":   %f\n", doubleString1, double1);
    printf("\"%s\":   %f\n", doubleString2, double2);
    printf("\"%s\":   %f\n", doubleString3, double3);
}