#include <stdio.h>

#define MAXLINE     1000 // Maximum input line length
#define MAXCHARS    80

// getline: read a line into s, return length
static int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

static void fold(char to[], char from[]) {
    // If dashes or other chars are gonna be added, consider MAXLINE value.
    // Maybe if there's only alphanumeric and _ chars in the last 10 positions
    // a dash can be added to fold the line.
    // Chars other than alphanumeric, ',', ';', ':', ']', and _ can be split.
    // Chars that can be split: 
    // - ' ', '\t', "&&" with ' ' before or after,
}

int main(void) {
    char line[MAXLINE];
    char folded[MAXLINE];
    int len;

    while ((len = get_line(line, MAXLINE)) > 0) {
        fold(folded, line);
        printf("%s", folded);
    }

    return 0;
}

