#include <iostream>
#include <inttypes.h>

int main() {
    uint32_t b0, b1, b2, b3;
    for (int x = 0; x < 17; x++) {

        int t1 = (x & (x - 1)) > 0;
        int t2 = (x & -x);

        printf("%d: %d % d \n", x, t1, t2);

    }

    int some_number = 0x01020304;

    b0 = some_number & 255;
    b1 = (some_number >> 8) & 0xFF;
    b2 = (some_number >> 16) & 0xFF;
    b3 = some_number >> 24;

    if (b0 == 4 && b1 == 3) {
        printf("big endian");
    }
    else if (b0 == 1) {
        printf("little endian");
    }
    else if (b0 == 4 && b1 == 2) {
        printf("midle endian");
    }
    else {
        printf("unknown");
    }

}




