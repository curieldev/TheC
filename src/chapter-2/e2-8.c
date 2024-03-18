#include <stdio.h>
#include <limits.h>

static unsigned int rightrot(unsigned int x, int n) {
    size_t bits = sizeof(int) / sizeof(char) * CHAR_BIT;
    unsigned int result = x;

    if (n > 0 && n < bits) {
        unsigned int n_bits_mask         = ~(UINT_MAX << n);
        unsigned int n_bits              = x & n_bits_mask;
        unsigned int n_bits_rotated_mask = n_bits_mask << (bits - n);
        unsigned int n_bits_rotated      = n_bits << (bits - n);

        result = (x >> n & ~n_bits_rotated_mask) | n_bits_rotated;
    }
    return result;
}

int main(void) {
    unsigned int input = 0x1A2B3C4D;
    int          bits  = 12;
    printf("Original number: 0x%X\n", input);
    printf("Number rotated %d bits: 0x%X\n", bits, rightrot(input, bits));

    return 0;
}
