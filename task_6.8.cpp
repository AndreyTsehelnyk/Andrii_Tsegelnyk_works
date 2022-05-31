//class6.8.c
#include <iostream>
#include <inttypes.h>

int main() {
    uint32_t m;
    unsigned j;

    scanf_s("%" PRIu32"", &m);
    scanf_s("%u", &j);

    uint64_t res1 = m & ~(1 << 3);

    printf("r=%" PRIu32 ", %" PRIx32, res1, res1);
}
