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

static void detab(char to[], const char from[]) {
    int i = 0;  // Input index (from)
    int o = 0;  // Output index (to)
    int offset = 0;
    int spaces;
    
    while (from[i] != '\n') {
        if (from[i] == '\t'){
            spaces = TAB_SIZE - ((i + offset) % TAB_SIZE);
            printf("i = %d, spaces = %d, offset = %d\n", i, spaces, offset);
            
            for (int j = 0; j < spaces; j++)
                to[o++] = ' ';
            offset = (offset + TAB_SIZE - (i % TAB_SIZE) - 1) % TAB_SIZE;
        }
        else {
            to[o++] = from[i];
        }
        i++;
    }
    to[o++] = '\n';
    to[o] = '\0';
}


int main(void) {
    char line[MAXLINE];
    char detabbed[MAXLINE];
    int len;

    while ((len = get_line(line, MAXLINE)) > 0) {
        detab(detabbed, line);
        printf("%s", detabbed);
    }

    return 0;
}

