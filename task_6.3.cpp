//class 6.3
#include <iostream>
#include <inttypes.h>

int main() {

	uint64_t m;
	unsigned j;
	printf("Input m:");
	scanf_s("%" PRIu64"", &m);
	printf("Input j:");
	scanf_s("%u", &j);

	uint64_t res = m | (0 << j);
	printf("result 10 = %" PRIu64 "\nresult 16 = %" PRIx64, res, res);
}