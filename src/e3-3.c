#include <stdio.h>
#include <ctype.h>

// Developer notes
// Error cases
//  a-0, 0-a
//  b-b, 3-3
//  
// Special cases
// -a-z, a-b-c

#define MAXSTR  1000

#define FALSE   0
#define TRUE    1


static int is_expansion_possible(char start, char end) {
    int result;

    if (start >= end)
        result = FALSE;
    else if (isalpha(start) && isalpha(end))
        result = TRUE;
    else if (isdigit(start) && isdigit(end))
        result = TRUE;
    else
        result = FALSE;

    return result;
}

static void expand(char from[], char to[]) {
    int i = 0;
    int o = 0;

    while (from[i] != '\0' && i < MAXSTR - 1) {
        if (!isalnum(from[i]) || from[i + 1] != '-' || !isalnum(from[i + 2])) {
            to[o++] = from[i];
        }
        else if (is_expansion_possible(from[i], from[i + 2])) {
            for (int c = from[i]; c < from[i + 2]; c++) {
                to[o++] = c;
            }
            i++; // To start next iteration at the end of this expansion,
                 // in case another expansion is linked, e.g. a-d-f
        }
        else {
            to[o++] = from[i];
        }
        i++;
    }
    to[o] = '\0';

}

int main(int argc, char *argv[]) {
    char test_string[] = "The alphabet is A-Z or a-z, a-as far as I'm concerned"
                         ", there's 2-7 letters not 7-2.";
    char expanded[MAXSTR];
    printf("Input string:\n %s\n", test_string);

    expand(test_string, expanded);

    printf("Expanded string:\n %s\n", expanded);

    return 0;
}
