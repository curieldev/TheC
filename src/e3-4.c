// The largest negative number cannot be handled because
// in a two's complement representation, the largest 
// negative number that can be represented in any 
// integer type is always bigger then the largest 
// positive number that can be represented by 1.
// e.g. for a sint16 the valid range is [-32,768, 32,767]
//
// So for itoa to work, a bigger data type than the
// integer argument shall be used, when the conversion
// from negative to positive is done.

#include <stdio.h>

#define MAXLINE     256

// Reverse a string
void reverse(char s[]) {
    char temp;
    int length = 0;

    // Find string length
    while (s[length] != '\0')
        length++;

    if (length > 0) // Avoid negative index
        length--; // Don't count the newline
    else
        return;

    for (int i = 0; i <= (length) / 2; i++) {
        temp = s[i];
        s[i] = s[length - i];
        s[length - i] = temp;
    }
}

static void itoa(int n, char s[]) {
    int i, sign;
    long num = n;

    if ((sign = n) < 0) // record sign
        num = -num;

    i = 0;
    do { // generate digits in reverse order
        s[i++] = num % 10 + '0'; // get next digit
    } while ((num /= 10) > 0); // delete it

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main(int argc, char *argv[]) {
    char line[MAXLINE];         // Input line
    int integer;                // Integer to convert
    char result[MAXLINE];       // Result of itoa
    if (   fgets(line, sizeof(line), stdin) != NULL
        && sscanf(line, "%d", &integer)     == 1) // Only 1 integer is found
    {
        printf("Input as integer: %d\n", integer);
        itoa(integer, result);
        printf("Result as char[]: %s\n", result);
    }

    return 0;
}

