#include <stdio.h>

#define MAXLINE 1000 // Maximum input line length

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

static void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}


// Print the longest input line
int main(void) {
    int len;                // Current line length
    int max;                // Maximum length seen so far
    char line[MAXLINE];     // Current input line
    char longest[MAXLINE];  // Longest line saved here

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
            printf("Longest line yet (%d chars):\n%s\n", len, longest);
        }
    }

    return 0;
}

