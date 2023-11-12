#include <stdio.h>

#define MAXLINE     1000 // Maximum input line length
#define LONGLINE    80   // Long line length

// I had no lines longer than 80 characters at this point, so I had to write this comment.

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

// Print the longest input line
int main(void) {
    int len;                // Current line length
    char line[MAXLINE];     // Current input line

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > LONGLINE) {
            printf("%s", line);
        }
    }

    return 0;
}

