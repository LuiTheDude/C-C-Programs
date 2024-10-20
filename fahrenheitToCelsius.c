#include <stdio.h>

int fahrToCelsius(float fahr);

int main()

/* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300 */

{
    printf("Fahrenheit-Celsius table\n");

    float fahr, celsius;
    float lower, upper, step;
    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */

    fahr = lower;

    while (fahr <= upper)
    {
        celsius = fahrToCelsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

int fahrToCelsius(float fahr) {
    return 5.0 * (fahr-32) / 9.0;
}