//class 6.3
#include <iostream>
#include <inttypes.h>

int main() {

	uint32_t m;
	printf("Input m:");
	scanf_s("%" PRIu32"", &m);

	uint32_t b0, b1, b2, b3, res2;

	b0 = m & 255;
	b1 = (m >> 8);
	b2 = (m >> 16);
	b3 = m >> 24;

	res2 = b0 | b1 | b2 | b3;

	// little-endian
	// b3| b2|b1|b0
	// b3 |b1|b2|b0


	printf("result 10 = %" PRIu32 "\nresult 16 = %" PRIx32, res2, res2);
}