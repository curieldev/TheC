//! WARNING: This code breaks with unicode bigger than 1 byte
#include <stdio.h>

// ASCII Visible Chars
#define FIRST_VISIBLE_CHAR  '!'
#define LAST_VISIBLE_CHAR   '~'
#define VISIBLE_CHARS       ((int)LAST_VISIBLE_CHAR - (int)FIRST_VISIBLE_CHAR + 1) 
#define LAST_ASCII_CHAR     (char)127

int main (void) {
    int histogram[VISIBLE_CHARS];
    int whitespace, others, multibyte;

    for (int i = 0; i < VISIBLE_CHARS; i++)
        histogram[i] = 0;

    char c;
    whitespace = others = multibyte = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n')
            whitespace++;
        else if (c >= FIRST_VISIBLE_CHAR && c <= LAST_VISIBLE_CHAR)
            histogram[(int)c - (int)FIRST_VISIBLE_CHAR]++;
        else
            others++;
    }

    puts("Visible Characters Histogram");
    if (whitespace > 0) {
        puts("ws -> whitespace characters");
        printf("ws ");
        for (int i = 0; i < whitespace; i++)
            putchar('#');
        printf(" (%d)", whitespace);
        putchar('\n');
    }
    if (others > 0)
        puts("oc -> other characters");

    for (int i = 0; i < VISIBLE_CHARS; i++) {
        if (histogram[i] == 0)
            continue;

        printf("%2c ", i + FIRST_VISIBLE_CHAR);
        for (int j = 0; j < histogram[i]; j++)
            putchar('#');
        printf(" (%d)", histogram[i]);
        putchar('\n');
    }

    if (others > 0) {
        printf("oc ");
        for (int i = 0; i < others; i++)
            putchar('#');
        printf(" (%d)", others);
        putchar('\n');
    }

    return 0;
}

