#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE     100
#define AIO         1 // Array Index Offset

// getline: read a line into s, return length
static int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - AIO && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

// atof: convert string s to double
double atof(char s[]) {
    double val, decimals, exponent;
    int i, sign, e_sign;

    for (i = 0; isspace(s[i]); i++) // skip whitespace
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (decimals = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        decimals -= 1.0;
    }

    if (s[i] == 'e' || s[i] == 'E')
        i++;

    e_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (exponent = 0.0; isdigit(s[i]); i++) {
        exponent = 10.0 * exponent + (s[i] - '0');
    }

    return sign * val * pow(10.0, decimals + (e_sign * exponent));
}

int main(int argc, char *argv[]) {
    double sum;
    char line[MAXLINE];

    sum = 0;
    while (get_line(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));

    return 0;
}

