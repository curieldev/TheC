#include <stdio.h>

#define MAXLINE 1048576 // 1 MiB

int main(void) {
    char c;
    char s[MAXLINE];
    int lim = MAXLINE;
    int i = 0;

    // Original for loop
    // for (int i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    //    s[i] = c;
    
    // Equivalent loop
    
    for (;;) {
        if (i >= lim - 1)
            break;
        else if ((c = getchar()) == '\n')
            break;
        else if (c == EOF)
            break;
        else
            s[i++] = c;
    }

    printf("%s\n", s);

    return 0;
}
