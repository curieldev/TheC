#include <stdio.h>

#define MAX_WORD_SIZE 20
#define IN            1   // Inside a word
#define OUT           0   // Outside a word

int main (void) {
    int histogram[MAX_WORD_SIZE];
    int more_than_20 = 0; // Words with more than 20 characters

    for (int i = 0; i < MAX_WORD_SIZE; i++)
        histogram[i] = 0;

    char c;
    int char_count = 0;
    int state = OUT;
    while ((c = getchar()) != EOF)
    {
        if (c != ' ' && c != '\t' && c != '\n') {
            state = IN;
            char_count++;
        }
        else if (state == IN) {
            if (char_count < MAX_WORD_SIZE)
                histogram[char_count - 1]++;
            else
                more_than_20++;

            state = OUT;
            char_count = 0;
        }
    }

    puts("Word length histogram (chars)");
    for (int i = 0; i < MAX_WORD_SIZE; i++) {
        printf("%3d  ", i + 1);
        for (int j = 0; j < histogram[i]; j++)
             putchar('#');
        printf(" (%d)\n", histogram[i]);
    }

    printf(" 20+ ");
    for (int i = 0; i < more_than_20; i++)
         putchar('#');
    printf(" (%d)\n", more_than_20);

    return 0;
}
