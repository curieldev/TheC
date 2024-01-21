#include <stdio.h>

#define MAXLINE     256

#define NOT_OK      0
#define OK          1

#define MAX_BASE    36
#define MIN_BASE    2

static char number_table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Reverse a string
static void reverse(char s[]) {
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

static void itob(int n, char s[], int b) {
    int i = 0;

    while (n > 0) {
        int remainder = n % b;
        s[i++] = number_table[remainder];
        n /= b;
    }
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
    int base10_int;
    int target_base;
    char prompt[] = "Enter a number and its target number base,\n"
                    "separated by a blank space. for example: 10 2";

    int read_status;
    do {
        if (read_line(line, prompt) != OK) {
            read_status = NOT_OK;
        }
        else if (sscanf(line, "%u %u", &base10_int, &target_base) != 2) {
            puts("Two numbers are expected\n");
            read_status = NOT_OK;
        }
        else if (base10_int < 1) {
            puts("Only non-zero positive numbers allowed\n");
            read_status = NOT_OK;
        }
        else if (target_base < MIN_BASE || target_base > MAX_BASE) {
            printf("Valid number base range is [%d, %d]\n", MIN_BASE, MAX_BASE);
            read_status = NOT_OK;
        }
        else {
            read_status = OK;
        }
    } while (read_status != OK);

    printf("Number in base 10: %u\n", base10_int);

    char result[MAXLINE];       // Result of conversion
    itob(base10_int, result, target_base);

    printf("Number in base %u: %s\n", target_base, result);

    return 0;
}
