#include <stdio.h>

int main()

/* print Celsius-Fahrenheit table
 for celsius = -100, -95, -90 ..., 100 */

{
    printf("Celsius-Fahrenheit table\n");

    float fahr, celsius;
    float lower, upper, step;
    lower = -100; /* lower limit of temperature scale */
    upper = 100; /* upper limit */
    step = 5; /* step size */

    celsius = lower;

    while (celsius <= upper)
    {
        fahr = (celsius * (9.0 / 5.0)) - 32;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}