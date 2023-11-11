#include <stdio.h>

static float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

int main (void) {
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      // Lower limit of temperature scale
    upper = 300;    // Upper limit
    step  = 20;     // Ste size

    puts(" dF    dC");
    fahr = lower;
    while (fahr <= upper) {
        celsius = fahrenheit_to_celsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }

    return 0;
}
