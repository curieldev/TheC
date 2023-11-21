#include <stdio.h>
#include <stdbool.h>

#define IOS         1       // Index offset, arrays start from 0

#define MAX_LINE    1000    // Maximum input line length
#define LINE_SIZE   80      // Maximum visible characters in an unfolded line
#define IGNORED     2       // Newline and NULL are ignored for line size
#define FOLD_MARGIN 10      // Scope where folding can occur

// Number of lines that would fit in the longest allowed line
#define LINES_IN_MAX_LINE   ((MAX_LINE - IGNORED) / LINE_SIZE)

// Maximum line length for a line to be folded
#define MAX_FOLD_LENGTH    (MAX_LINE - IGNORED - LINES_IN_MAX_LINE)

// getline: read a line into s, return length
static int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - IOS && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

// Can the line be folded by replacing a character e.g. a blank with a newline?
static bool is_easy_fold(const char s[], int *pos) {
    for (*pos = FOLD_MARGIN - IOS; *pos >= 0; (*pos)--)
        if (s[*pos] == ' ' || s[*pos] == '\t')
            return true;

    return false;
}

static void fold(char to[], const char from[]) {
    int i = 0;  // Input index (from)
    int o = 0;  // Output index (to)
    // If dashes or other chars are gonna be added, consider MAX_LINE value.
    // Maybe if there's only alphanumeric and _ chars in the last 10 positions
    // a dash can be added to fold the line.
    // Chars other than alphanumeric, ',', ';', ':', ']', and _ can be split.
    // Chars that can be split: 
    // - ' ', '\t', "&&" with ' ' before or after,

    while (from[i] != '\0') {
        bool near_limit = (o % LINE_SIZE) > (LINE_SIZE - FOLD_MARGIN - IOS); 
        int fold_pos;

        if (!near_limit) {
            if (from[i] != '\n')
                to[o++] = from[i++];
            else
                i++;
        }
        else if (is_easy_fold(&from[i], &fold_pos)) {
            for (int j = 0; j < FOLD_MARGIN; j++, i++)
                to[o++] = (j == fold_pos) ? '\n' : from[i];
        }
        else {
            for (int j = 0; j < FOLD_MARGIN - 1; j++)
                to[o++] = from[i++];

            to[o++] = '\n';
        }
    }
    to[o++] = '\n';
    to[o]   = '\0';
}

int main(void) {
    char line[MAX_LINE];
    char folded[MAX_LINE];
    int len;

    while ((len = get_line(line, MAX_LINE)) > 0) {
        if (len > LINE_SIZE + IGNORED && len < MAX_FOLD_LENGTH) {
            fold(folded, line);
            printf("%s", folded);
        }
        else {
            printf("%s", line);
        }
    }

    return 0;
}

// This is a long test line to fold, let's see if this code actually works, but probably it won't, at least not the first time.
// https://www.google.com/search?q=word+separators+symbols&client=firefox-b-d&sca_esv=584142833&ei=Q_pbZdS1JovPkPIPoL6-kAw&oq=word+delimiters+s&gs_lp=Egxnd3Mtd2l6LXNlcnAiEXdvcmQgZGVsaW1pdGVycyBzKgIIADIIEAAYFhgeGA8yCBAAGBYYHhgPMggQABgWGB4YDzIGEAAYFhgeMgYQABgWGB4yCxAAGBYYHhjxBBgKMggQABgWGB4YDzILEAAYgAQYigUYhgNIqA9QjAJYyARwAXgBkAEAmAGIAaAB-AGqAQMwLjK4AQPIAQD4AQHCAgoQABhHGNYEGLADwgIFEAAYgATiAwQYACBBiAYBkAYI&sclient=gws-wiz-serp#ip=1
