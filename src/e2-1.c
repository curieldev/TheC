#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    printf("  signed char  range: [%d, %d]\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char  range: [%u, %u]\n", 0, UCHAR_MAX);
    putchar('\n');
    printf("  signed short range: [%d, %d]\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short range: [%u, %u]\n", 0, USHRT_MAX);
    putchar('\n');
    printf("  signed int   range: [%d, %d]\n", INT_MIN, INT_MAX);
    printf("unsigned int   range: [%u, %u]\n", 0, UINT_MAX);
    putchar('\n');
    printf("  signed long  range: [%ld, %ld]\n", LONG_MIN, LONG_MAX);
    printf("unsigned long  range: [%u, %lu]\n", 0, ULONG_MAX);
    putchar('\n');
    printf("      float range: [%.10e, %.10e]\n", FLT_MIN, FLT_MAX);
    printf("     double range: [%.10le, %.10le]\n", DBL_MIN, DBL_MAX);
    printf("long double range: [%.10Le, %.10Le]\n", LDBL_MIN, LDBL_MAX);

    return 0;
}


