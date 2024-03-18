// The run-time is 1ms faster, was it worth it?

#include <stdio.h>
#include <limits.h>

int array[USHRT_MAX];

#if 0
// binsearch: find x in v[0] <= v[1] <= ... <= v[n-1]
int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid + 1;
        else // found match
            return mid;

        printf("%d, %d, %d\n", low, mid, high);
    }
    return -1;
}
#endif

int binsearch(int x, int v[], int n) {
    int low, high, mid;
    int result = -1;
    int prev_mid;

    low = 0;
    high = n - 1;
    prev_mid = -1;
    mid = (low + high) / 2;
    while (prev_mid != mid) {
        printf("%d, %d, %d\n", low, mid, high);
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;

        prev_mid = mid;
        mid = (low + high) / 2;
    }

    if (v[mid] == x)
        result = v[mid];

    return result;
}

int main(void) {
    const int find = 1;

    for (int i = 0; i < USHRT_MAX; i++) {
        array[i] = i;
    }

    int index = binsearch(find, array, USHRT_MAX);

    if (index >= 0)
        printf("Found %d at index %d\n", array[index], index);
    else
        printf("Not found\n");

    return 0;
}
