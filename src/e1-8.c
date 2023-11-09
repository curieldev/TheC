#include <stdio.h>

int main (void) {
    char c;
    int blanks, tabs, newlines;

    blanks = tabs = newlines = 0;
    while((c = getchar()) != EOF){
        putchar(c);
        if (c == ' ')
            blanks++;
        else if (c == '\t')
            tabs++;
        else if (c == '\n')
            newlines++;
        else
            continue;
    }

    printf("Blanks seen: %d\n", blanks);
    printf("Tabs seen: %d\n", tabs);
    printf("New lines seen: %d\n", newlines);
    return 0;
}
