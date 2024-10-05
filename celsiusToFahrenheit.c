#include <stdio.h>

int main()

/* print Celsius-Fahrenheit table
 for celsius = -100, -95, -90 ..., 100 */

{
    int fahr, celsius;
    int lower, upper, step;
    lower = -100; /* lower limit of temperature scale */
    upper = 100; /* upper limit */
    step = 5; /* step size */

    celsius = lower;

    while (celsius <= upper)
    {
        fahr = (9 * celsius / 5) - 32;
        printf("%d\t%d\n", celsius, fahr);
        celsius = celsius + step;
    }
}