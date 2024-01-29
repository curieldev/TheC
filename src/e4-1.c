#include <stdio.h>
#include <string.h>

#define MAXLINE     1000

// strindex: return rightmost index of t in s, -1 if none
int strindex(char s[], char t[]) {
    int index = -1;
    int i, j, k;

    for (i = strlen(s) - 1; i >= 0 ; i--) {
        for (j = i, k = strlen(t) - 1; k >= 0 && s[j] == t[k]; j--, k--)
            ;

        if (k < 0) {
            index = i - strlen(t) + 1;
            break;
        }
    }

    return index;
}

int main(int argc, char *argv[]) {
    char str[MAXLINE];
    char find[MAXLINE];
    
    char* last_char;
    do {
        puts("Enter a string:");
    } while ((last_char = fgets(str, MAXLINE, stdin)) == NULL);
    str[strcspn(str, "\n")] = '\0';
    
    do {
        puts("Enter a token to find in previous string:");
    } while ((last_char = fgets(find, MAXLINE, stdin)) == NULL);
    find[strcspn(find, "\n")] = '\0';

    int found_index = strindex(str, find);
    if (found_index != -1)
        printf("Found \"%s\" on index %d\n", find, found_index);
    else
        printf("No matches for \"%s\" found\n", find);

    return 0;
}
