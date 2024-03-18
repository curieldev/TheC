#include <stdio.h>

#define MAX_STR     10000

void escape(char t[], const char s[]) {
    int i; // Input index
    int o; // Output index

    i = 0;
    o = 0;
    while (s[i] != '\0' && o < MAX_STR - 1) {
        switch(s[i]) {
            case '\n':
                t[o++] = '\\';
                t[o++]   = 'n';
                t[o]   = '\n';
                break;
            case '\t':
                t[o++] = '\\';
                t[o]   = 't';
                break;
            default:
                t[o] = s[i];
        }
        
        o++;
        i++;
    }
    
    if (o == MAX_STR - 1)
        t[MAX_STR - 1] = '\0';
    else
        t[o] = '\0';
}

void no_escape(char t[], const char s[]) {
    int i; // Input index
    int o; // Output index

    i = 0;
    o = 0;
    while (s[i] != '\0' && o < MAX_STR - 1) {
        if (s[i] == '\\') {
            switch(s[i + 1]) {
                case 'n':
                    t[o]   = '\n';
                    i++;
                    if (s[i + 1] == '\n')
                        i++;
                    break;
                case 't':
                    t[o]   = '\t';
                    i++;
                    break;
                default:
                    t[o] = s[i];
            }
        }
        else
            t[o] = s[i];
        
        o++;
        i++;
    }
    
    if (o == MAX_STR - 1)
        t[MAX_STR - 1] = '\0';
    else
        t[o] = '\0';

}

int main(void) {
    char text[MAX_STR];
    char escaped[MAX_STR];
    char c;
    int  i;

    i = 0;
    while ((c = getchar()) != EOF && i < MAX_STR - 1)
        text[i++] = c;

    if (i == MAX_STR - 1)
        text[MAX_STR - 1] = '\0';

    escape(escaped, text);
    printf("Escaped text:\n%s\n", escaped);

    no_escape(text, escaped);
    printf("No escape text:\n%s\n", text);

    return 0;
}

