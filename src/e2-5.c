#include <stdio.h>
#include <stdbool.h>

#define NCO             1       // Null Character Offset
#define AIO             1       // Array Index Offset

#define MAXSTRING       1048576
#define MAXSQUEEZE      ('~' - ' ' + NCO) // Valid characters to squeeze

static int any(char s[], char find[]) {
    int i;
    bool located = false;

    i = 0;
    while (s[i] != '\0') {
        int j = 0;

        while (find[j] != '\0') {
            if (s[i] == find[j]) {
                located = true;
                break;
            }
            j++;
        }

        if (located)
            break;

        i++;
    }

    return located ? i : -1;
}

static void print_line(char s[]) {
    int i = 0;

    while (s[i] != '\n')
        putchar(s[i++]);
    putchar(s[i]);
}

int main(void) {
    char c;
    int  i = 0;
    char str[MAXSTRING];

    while ((c = getchar()) != EOF && i < MAXSTRING)
        str[i++] = c;

    int location;
    char locate[MAXSQUEEZE] = "23";
    location = any(str, locate);

    if (location == -1) {
        puts("No match was found.");
    }
    else {
        printf("Found a match on index: %d\n", location);
        print_line(str + location);
    }

    

    return 0;
}

