#include <stdio.h>

// Print Celsius-Fahrenheit table
int main (void){
    float fahr, celsius;
    float lower, upper, step;

    lower = -20;
    upper = 160;
    step  = 20;

    // Header
    printf("degC  degF\n");

    celsius = lower;
    while (celsius <= upper){
        fahr = (9.0 / 5.0) * celsius + 32;
        printf("%4.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}
