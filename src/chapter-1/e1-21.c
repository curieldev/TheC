#include <stdio.h>

#define MAXLINE     1000 // Maximum input line length
#define TAB_SIZE    4

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

// replace spaces for tabs + spaces, line by line
static void entab(char to[], const char from[]) {
    int i = 0;  // Input index (from)
    int o = 0;  // Output index (to)

    // Blanks will be given preference when either a blank or a tab suffice.
    
    while (from[i] != '\n') {
        if (from[i] == ' '){
            int blanks_needed = TAB_SIZE - (i % TAB_SIZE);

            if (blanks_needed == 1) {
                to[o++] = from[i++];
                continue;
            }

            int blanks_available = 1;
            while (from[i + blanks_available] == ' ')
                blanks_available++;

            if (blanks_available >= blanks_needed) {
                to[o++] = '\t';
                i += blanks_needed;
            }
            else {
                to[o++] = from[i++];
            }
        }
        else {
            to[o++] = from[i++];
        }
    }
    to[o++] = '\n';
    to[o] = '\0';
}


int main(void) {
    char line[MAXLINE];
    char entabbed[MAXLINE];
    int len;

    while ((len = get_line(line, MAXLINE)) > 0) {
        entab(entabbed, line);
        printf("%s", entabbed);
    }

    return 0;
}

