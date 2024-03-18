#include <stdio.h>

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

// Reverse a string
void reverse(char s[]) {
    char temp;
    int length = 0;

    // Find string length
    while (s[length] != '\n')
        length++;

    if (length > 0) // Avoid negative index
        length--; // Don't count the newline
    else
        return;

    for (int i = 0; i <= (length) / 2; i++) {
        temp = s[i];
        s[i] = s[length - i];
        s[length - i] = temp;
    }
}

int main(void) {
    char line[MAXLINE];
    int len;

    while ((len = get_line(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}
