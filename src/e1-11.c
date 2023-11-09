// How would you test the word count progarm?
// Using a file as input e.g. ./e1-11 < main.c
// What kinds of input are most likely to uncover bugs if there are any?
// Special characters might brake the program

#include <stdio.h>

#define IN  1   // Inside a word
#define OUT 0   // Outside a word

// Count lines, words, and characters in input
int main (void){
    int c;
    int nl, nw, nc;
    int state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF){
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT){
            state = IN;
            ++nw;
        }
    }
    printf("lines: %d, words: %d characters: %d\n", nl, nw, nc);

    return 0;
}
