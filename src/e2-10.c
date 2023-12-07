#include <stdio.h>

char lower(char c) {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int main(void) {
    char letter = 'J';

    printf("Uppercase: %c, Lowercase: %c\n", letter, lower(letter));
    
    return 0;
}
