#include <stdio.h>
#include <stdbool.h>

#define MAXLINE     1000 // Maximum input line length         

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

static bool is_line_empty(char s[]) {
    int i = 0;
    while (s[i] != '\n') {
        if (s[i] != ' ' || s[i] != '\t')
            return false;
        i++;
    }

    return true;
}

static void clean_whitespace(char s[]) {
    int i = 0;

    while (s[i] != '\n')
        i++;

    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
        i--;

    s[++i] = '\n';
    s[++i] = '\0';
}

int main (void) {
    int len;                // Current line length      
    char line[MAXLINE];     // Current input line         

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (!is_line_empty(line)) {
            clean_whitespace(line);
            printf("%s", line);
        }
    }
    return 0;
}

