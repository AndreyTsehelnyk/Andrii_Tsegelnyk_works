//class 6.3
#include <iostream>
#include <inttypes.h>



size_t max_bits_in_row(unsigned x) {

	size_t res = 0, count = 0;;
	size_t num_bits = 8 * sizeof(x);

	for (int i = 0; i < num_bits; i++) {
		unsigned r = x & (1 << i);
		if (r) {
			count++;
		}
		else {
			if (count > res) {
				res = count;
			}
		}
	}

	return res;
}

int main() {

	uint32_t m;
	printf("Input m:");
	scanf_s("%" PRIu32"", &m);

	uint32_t b0, b1, b2, b3, res3;

	b1 = (m >> 8);
	
	b3 = m >> 24;

	res3 = b3 | b1;

	printf(" max 1th in a row is %zu", max_bits_in_row(m));

}