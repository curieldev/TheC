#include <stdio.h>
#include <stdbool.h>

#define NCO             1       // Null Character Offset
#define AIO             1       // Array Index Offset

#define MAXSTRING       1048576
#define MAXSQUEEZE      ('~' - ' ' + NCO) // Valid characters to squeeze

static void squeeze(char s[MAXSTRING], char ditch[MAXSQUEEZE]) {
    int i;
    int j;

    i = j = 0;
    while (s[i] != '\0') {
        bool transfer = true;
        int k = 0;

        while (ditch[k] != '\0') {
            if (s[i] == ditch[k]) {
                transfer = false;
                break;
            }
            k++;
        }

        if (transfer)
            s[j++] = s[i];

        i++;
    }
    s[j] = '\0';
}

int main(void) {
    char str[MAXSTRING];
    char c;
    int  i = 0;
    while ((c = getchar()) != EOF && i < MAXSTRING)
        str[i++] = c;

    printf("ORIGINAL\n%s\n", str);

    char drain[MAXSQUEEZE] = "a[]sz";
    squeeze(str, drain);

    printf("SQUEEZED\n%s", str);

    return 0;
}

