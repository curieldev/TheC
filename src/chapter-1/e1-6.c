#include <stdio.h>

int main (void){
    signed char c;

    // Ctrl + d sends an EOF in Konsole terminal
    c = getchar() != EOF;
    printf("getchar() != EOF = %d\n", c);

    return 0;
}
