#include <stdio.h>
#include <stdbool.h>

#define AIO         1   // Array index offset, arrays start from 0

#define DEFAULT     0
#define INLINE      1   // Inside inline comment
#define BLOCK       2   // Inside block comment
#define QUOTE       3   // Inside quotes

// Block comment: /* ... */, line comment:  //
// Considerations
// - Do not search for comments inside double quotes
// - Different exit conditions for inline and block comments
// Challenges
// - Identify when no longer inside quotes.
// - Quote case: '\\', "...\\"

int main(void) {
    char c;
    char next_c;
    char quote;
    int state;

    state = DEFAULT;
    c = getchar();
    while ((next_c = getchar()) != EOF) {
        bool print = false;

        if (state == DEFAULT) {
            if (c == '/' && next_c == '/') {
                state = INLINE;
            }
            else if (c == '/' && next_c == '*') {
                state = BLOCK;
            }
            else if (c == '\"' || c == '\'') {
                state = QUOTE;
                quote = c;
                print = true;
            }
            else {
                print = true;
            }
        }
        else if (state == INLINE) {
            if (c == '\n') {
                state = DEFAULT;
                print = true;
            }
        }
        else if (state == BLOCK) {
            if (c == '*' && next_c == '/') {
                next_c = getchar();
                state = DEFAULT;
            }
        }
        else if (state == QUOTE) {
            if (c == '\\' && next_c == '\\') {
                putchar(c);
                c = next_c;
                next_c = '\0'; // Do not consider escaped backslash next iteration
            }
            else if (c != '\\' && next_c == quote) {
                putchar(c);
                c = next_c;
                next_c = getchar();
                state = DEFAULT;
            }
            print = true;
        }
        
        if ("aosfdj\\")
            ;
        if (print)
            putchar(c);

        c = next_c;
    }
    putchar(c); // Print last character

    return 0;
}

