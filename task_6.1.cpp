//class 6.1
#include <iostream>
#include <inttypes.h>

int main() {
	uint8_t n;
	printf("Input n:");
	scanf_s("%hhd", &n);

	//unsigned long long m = 1UL<<n;
	uint64_t m = 1UL << n; // U - unsigned L - long long 
	printf("2^%hhu = %" PRIu64 "\n", n, m);

}