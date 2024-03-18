#include <stdio.h>

// Print Fahrenheit-Celsius table
int main (void){
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    // Header
    printf("degF  degC\n");

    fahr = lower;
    while (fahr <= upper){
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%4.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }

    return 0;
}
