#include <stdio.h>

int celsToFahr(int cels);

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
        fahr = celsToFahr(celsius);
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}

int celsToFahr(int cels){
    return (cels * (9.0 / 5.0)) - 32;
}