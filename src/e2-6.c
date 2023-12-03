#include <stdio.h>
#include <limits.h>

static unsigned int setbits(unsigned int x, const int p, 
                               const int n, const unsigned int y) {
    size_t bits = sizeof(int) / sizeof(char) * (size_t)CHAR_BIT;
    unsigned int result = x;

    if (n > 0 && n < bits && p >= 0 && p < bits && p + 1 - n >= 0) {
        unsigned int n_bits_mask      = ~(UINT_MAX << n);
        unsigned int n_bits           = n_bits_mask & y;
        unsigned int n_bits_at_p      = n_bits << (p + 1 - n);
        unsigned int n_bits_at_p_mask = n_bits_mask << (p + 1 - n);

        result = (x & ~n_bits_at_p_mask) | n_bits_at_p;
    }

    return result;
}

int main(void) {
    unsigned int from     = 0xA15;
    unsigned int to       = UINT_MAX;
    int          position = 19;
    int          bits     = 12;

    printf("take first %d bits from 0x%X and\n", bits, from);
    printf("insert into 0x%X at bit position %d\n\n", to, position);
    printf("result: 0x%X\n", setbits(to, position, bits, from));


    return 0;
}
