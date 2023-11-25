// NOTE: Decided not to use structs as they are not presented yet in the book.

// Scope of this program
// Identify missing closing pairs (], ), })
// Identify missing closing quotes (', ")
// Identify nested block comments


#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE  100

#define DEFAULT     0
#define INLINE      1   // Inside inline comment
#define BLOCK       2   // Inside block comment
#define QUOTE       3   // Inside quotes

#define NONE            0
#define OPENING_PAIR    1
#define CLOSING_PAIR    2

// Dev Notes
// Parentheses, brackets and braces can be handled the same.
// Single and double quotes can be handled the same.
// No syntax error comes to mind for inline comments.
// Block comments cannot be nested
// Challenges:
// Comments, parentheses, brackets, and braces must be ignored when inside
// quotes

static int get_pair_type(char c) {
    if (c == '{' || c == '(' || c == '[')
        return OPENING_PAIR;
    else if (c == '}' || c == ')' || c == ']')
        return CLOSING_PAIR;
    else
        return NONE;
}
static char get_pair(char c) {
    if (c == '{')
        return '}';
    else if (c == '(')
        return ')';
    else if (c == '[')
        return ']';
    else if (c == '}')
        return '{';
    else if (c == ']')
        return '[';
    else if (c == ')')
        return '(';
    else
        return '\0';
}

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
            if (prev_c == '/' && c == '/')
                state = INLINE;
            else if (prev_c == '/' && c == '*')
                state = BLOCK;
            else if (c == '\"' || c == '\'')
                state = QUOTE;

            int pair_type = get_pair_type(c);
            if (state != DEFAULT || pair_type == OPENING_PAIR) {
                syntax_stack[stack_idx] = c;
                line_stack[stack_idx] = line_count;
                stack_idx++;
            }

            if (pair_type == CLOSING_PAIR) {
                stack_idx--;
                if (get_pair(c) != syntax_stack[stack_idx]) {
                    printf("Missing closing \'%c\'", syntax_stack[stack_idx]);
                    printf("opened on line %d\n", line_stack[stack_idx]);
                    break;
                }
            }
        }
        else if (state == INLINE) {
            if (c == '\n') {
                stack_idx--;
                state = DEFAULT;
            }
        }
        else if (state == BLOCK) {
            if (prev_c == '/' && c == '*') {
                printf("Block comments cannot be nested\n");
                printf("Refer to line %d\n", line_count);
                break;
            }
            else if (prev_c == '*' && c == '/') {
                stack_idx--;
                state = DEFAULT;
            }
        }
        else if (state == QUOTE) {
            if (c == '\n') {
                stack_idx--;
                printf("Missing closing \'%c\'", syntax_stack[stack_idx]);
                printf("opened on line %d\n", line_stack[stack_idx]);
                break;
            }
            else if (prev_c == '\\' && c == '\\') {
                c = '\0'; // Do not allow scaped backslash to interfere with
                           // end of quote detection
            }
            else if (prev_c != '\\' && c == syntax_stack[stack_idx - 1]) {
                stack_idx--;
                state = DEFAULT;
            }
        }

        prev_c = c;
    }

    return 0;
}

