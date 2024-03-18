#include <stdio.h>

#define IN  1   // Inside a word
#define OUT 0   // Outside a word

// Print one word per line
int main (void) {
    int c;
    int state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            putchar('\n');
            putchar(c);
        }
        else {
            putchar(c);
        }
    }

    return 0;
}
