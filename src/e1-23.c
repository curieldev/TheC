#include <stdio.h>
#include <stdbool.h>

#define AIO         1       // Array index offset, arrays start from 0

#define IN_QUOTE    1
#define OUT_QUOTE   0

// Block comment: /* ... */, line comment:  //
// Considerations
// - Do not search for comments inside double quotes
// Special cases
// - Ignore: "//", "/*", "\""
// - '\"', '\''
// Challenges
// - Identify when no longer inside a string "...".

static void ignore_quoted(const char q) {
    char c = '\0';
    char prev_c;

    do {
        prev_c = c;
        c = getchar();
    } while (c != q || prev_c == '\\');
}

static void ignore_until(char u) {
    char c;
    do
        c = getchar();
    while (c != u);
}

static void ignore_inline() {
}

static void ignore_block() {
}

int main(void) {
    char c;
    char prev_c;
    char quote;
    int state;

    state = OUT_QUOTE;
    while ((c = getchar()) != EOF) {
        if ((c == '\"' || c == '\'') && state == OUT_QUOTE) {
            state = IN_QUOTE;
            quote = c;
        }
        else 
            ;

        putchar(c);
        prev_c = c;
    }

    return 0;
}

