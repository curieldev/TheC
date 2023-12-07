#include <stdio.h>

// Due to how the binary numbers are represented, if 1 is removed from a number 
// it will invert all the digits to the right of the rightmost 1 including it.
// For example, if we have 0xF0 (0b1111000) and we subtract 1 from it we get
// 0xEF (0b1110111) that we can now use as a mask to remove the righmost 1.

// count 1 bits in x
int bitcount(unsigned x) {
    int b = 0;

    for (b = 0; x != 0; x &= x - 1)
            b++;

    return b;
}

int main(void) {
    unsigned number = 0xDEADBEEF;

    printf("There are %d non-zero bits in 0x%X\n", bitcount(number), number);
    return 0;
}
