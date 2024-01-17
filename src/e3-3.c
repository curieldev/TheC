#include <stdio.h>
#include <ctype.h>

// Developer notes
// Error cases
//  a-0, 0-a
//  b-b, 3-3
//  e-R, E-R
//  r-E, R-e
// Special cases
// -a-z, a-b-c

#define MAXSTR  1000

#define FALSE   0
#define TRUE    1

static int is_expansion(char const str[]) {
    int result;
    if (!isalnum(str[0]) || str[1] != '-' || !isalnum(str[2]))
        result = FALSE;
    else
        result = TRUE;

    return result;
}

static int is_expandable(char start, char end) {
    int result;

    if (islower(start) && !islower(end))
        result = FALSE;
    else if (!islower(start) &&  islower(end))
        result = FALSE;
    else if (start >= end)
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
        if (!is_expansion(&from[i]) || !is_expandable(from[i], from[i + 2])) {
            to[o++] = from[i];
        }
        else {
            for (int c = from[i]; c < from[i + 2]; c++) {
                to[o++] = c;
            }
            i++; // To start next iteration at the end of this expansion,
                 // in case another expansion is linked, e.g. a-d-f
        }
        i++;
    }
    to[o] = '\0';

}

int main(int argc, char *argv[]) {
    char text[MAXSTR];
    char expanded[MAXSTR];

    if(fgets(text, MAXSTR, stdin) != NULL) {
        printf("Input string:\n%s\n", text);
        expand(text, expanded);
        printf("Expanded string:\n%s\n", expanded);
    }

    return 0;
}
