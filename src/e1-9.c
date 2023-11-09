#include <stdio.h>

int main (void) {
    char c;
    char prev_c = '\0';

    while((c = getchar()) != EOF){
        if (prev_c == ' ' && c == ' ')
            continue;
        else
            putchar(c);

        prev_c = c;
    }

    return 0;
}
