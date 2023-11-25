// NOTE: Decided not to use structs as they are not presented yet in the book.
#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE  100

#define DEFAULT     0
#define COMMENT     1   // Inside block comment
#define QUOTE       2   // Inside quotes

// Dev Notes
// Parentheses, brackets and braces can be handled the same.
// Single and double quotes can be handled the same.
// No syntax error comes to mind for inline comments.
// Block comments cannot be nested
// Challenges:
// Comments, parentheses, brackets, and braces must be ignored when inside
// quotes

int main(void) {
    char prev_c, c;
    char syntax_stack[STACK_SIZE];
    int  line_stack[STACK_SIZE];
    int  stack_idx;
    int  state;
    int  line_count;

    state = DEFAULT;
    stack_idx = 0;
    prev_c = '\0';
    line_count = 1;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            line_count++;
        }

        
        if (state == DEFAULT) {
            if (prev_c == '/' && c == '*')
                state = COMMENT;
            else if (c == '\"' || c == '\'')
                state = QUOTE;

            bool is_pair = (c == '{' || c == '(' || c == '[');
            if (state != DEFAULT || is_pair) {
                syntax_stack[stack_idx] = c;
                line_stack[stack_idx] = line_count;
                stack_idx++;
            }

            // TODO: Implement pair exit handling
            // TODO: Add back inline comment case
        }
        else if (state == COMMENT) {

        }
        else if (state == QUOTE) {

        }
        else {

        }
        state = DEFAULT;

        prev_c = c;
    }

    for (int i = 0; i < stack_idx; i++)
        printf("%c at line %d\n", syntax_stack[i], line_stack[i]);

    return 0;
}

