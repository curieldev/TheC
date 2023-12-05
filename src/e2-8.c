#include <stdio.h>

static unsigned int rightrot(unsigned int x, int n) {
    return x;
}

int main(void) {
    unsigned int input = 0xFFFFFFFA;
    int          bits  = 4;
    printf("Original number: 0x%X\n", input);
    printf("Number rotated %d bits: 0x%X\n", bits, rightrot(input, bits));

    return 0;
}
