#include <stdio.h>

#define MAXLINE     256

#define NOT_OK      0
#define OK          1

// Reverse a string
void reverse(char s[]) {
    char temp;
    int length = 0;

    // Find string length
    while (s[length] != '\0')
        length++;

    if (length > 0) // Avoid negative index
        length--; // Don't count the newline
    else
        return;

    for (int i = 0; i <= (length) / 2; i++) {
        temp = s[i];
        s[i] = s[length - i];
        s[length - i] = temp;
    }
}

static void itoa(int n, char s[], int w) {
    int i, sign;
    long num = n;

    if ((sign = n) < 0) // record sign
        num = -num;

    i = 0;
    do { // generate digits in reverse order
        s[i++] = num % 10 + '0'; // get next digit
    } while ((num /= 10) > 0); // delete it

    if (sign < 0)
        s[i++] = '-';

    while (i < w)
        s[i++] = ' ';

    s[i] = '\0';
    reverse(s);
}

static int read_line(char line[], char const prompt[]) {
    int result;

    printf("%s\n", prompt);

    if (fgets(line, MAXLINE, stdin) == NULL)
        result = NOT_OK;
    else
        result = OK;
    
    return result;
}

int main(int argc, char *argv[]) {
    char line[MAXLINE];         // Input line
    int integer;                // Integer to convert
    int width;
    char prompt[] = "Enter a number and the minimum width of the output,\n"
                    "separated by a blank space. for example: 10 2";

    int read_status;
    do {
        if (read_line(line, prompt) != OK) {
            read_status = NOT_OK;
        }
        else if (sscanf(line, "%d %d", &integer, &width) != 2) {
            puts("Two numbers are expected\n");
            read_status = NOT_OK;
        }
        else {
            read_status = OK;
        }
    } while (read_status != OK);

    char result[MAXLINE];       // Result of conversion

    printf("Input as integer: %d\n", integer);
    itoa(integer, result, width);
    printf("Result as char[]: %s\n", result);
    return 0;
}

