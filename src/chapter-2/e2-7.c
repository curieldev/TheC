#include <stdio.h>
#include <limits.h>

unsigned int invert(unsigned int x, int p, int n) {
    unsigned int result = x;
    size_t bits = sizeof(x) / sizeof(char) * (size_t)CHAR_BIT;
    if (p >= 0 && p < bits && n > 0 && n <= bits && p + 1 - n >= 0) {
        unsigned int n_bits_mask = ~(UINT_MAX << n);
        unsigned int n_bits_at_p_mask = n_bits_mask << (p + 1 - n);
        
        result = x ^ n_bits_at_p_mask;
    }

    return result;
}

int main(void) {
    unsigned int input    = 0xAAFAAAAA;
    unsigned int position = 23;
    unsigned int bits     = 8;

    printf("Flip %u bits from 0x%X, starting at position %d.\n", bits, input,
           position);
    printf("Result: 0x%X\n", invert(input, position, bits));

    return 0;
}
