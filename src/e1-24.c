#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE  100

#define DEFAULT     0
#define INLINE      1   // Inside inline comment
#define BLOCK       2   // Inside block comment
#define QUOTE       3   // Inside quotes

// Notes
// Parentheses, brackets and braces can be handled the same.
// Single and double quotes can be handled the same.
// No syntax error comes to mind for inline comments.
// Block comments cannot be nested
// Challenges:
// Comments, parentheses, brackets, and braces must be ignored when inside
// quotes

int main(void) {
    char prev_c, c;
    char stack[STACK_SIZE];
    int  stack_idx;

    stack_idx = 0;
    prev_c = '\0';
    while ((c = getchar()) != EOF) {
        bool is_inline = (prev_c == '/' && c == '/');
        bool is_block  = (prev_c == '/' && c == '*');
        bool is_quote  = (c == '\"' || c == '\'')
        bool is_pair   = (c == '{' || c == '(' || c == '[');

        // TODO: Reuse previous logic
        // Symmetric paired symbols share the default state

        if (is_inline || is_block || is_quote || is_pair) {
            stack[stack_idx++] = c;
        }

        prev_c = c;
    }
    putchar(c); // Print last character


    return 0;
}

