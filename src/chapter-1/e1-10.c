#include <stdio.h>

int main (void) {
    char c;

    while((c = getchar()) != EOF){
        if (c == ' ')
            printf("\\b");
        else if (c == '\t')
            printf("\\t");
        else if (c == '\n')
            printf("\\n\n");
        else
            putchar(c);
    }

    return 0;
}
