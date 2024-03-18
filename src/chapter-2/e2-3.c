#include <stdio.h>
#include <limits.h>
#include <math.h>

#define AIO         1 // Array Index Offset
#define MAXLINE     1024 // 1 KiB
#define HEX_BASE    16

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

static char to_upper(char c) {
    char result;
    if (c >= 'a' && c <= 'z')
        result = c - 'a' - 'A';
    else if (c >= 'A' && c <= 'Z')
        result = c;
    else
        result = '\0';

    return result;
}

static int to_int(char c) {
    int result;
    if (c >= '0' && c <= '9')
        result = c - '0';
    else if (to_upper(c) >= 'A' && to_upper(c) <= 'F')
        result = 10 + c - 'A';
    else
        result = -1;

    return result;
}

static int ignore_trailing_whitespace(int len, char line[len]) {
    int i = len - 1;

    while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
        i--;

    return i;
}

int main(void) {
    char line[MAXLINE];
    int len;

    while ((len = get_line(line, MAXLINE)) > 0) {
        int i = ignore_trailing_whitespace(len, line);
        int number = 0;
        int hex_digit;
        int power = 0;
        
        while ((hex_digit = to_int(line[i])) >= 0) {
            int powered_base = pow(HEX_BASE, power);
            
            // Test overflow
            if (number <= (INT_MAX - hex_digit * powered_base)) {
                number += hex_digit * powered_base;
            }
            else {
                printf("Value out of range, result is incorrect.\n");
                break;
            }

            i--;
            power++;
        }

        printf("Number in decimal: %d\n", number);
    }

    return 0;
}
