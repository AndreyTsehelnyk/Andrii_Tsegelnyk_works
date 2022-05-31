//class 6.2
#include <iostream>
#include <inttypes.h>

int main() {

	int n;
	unsigned k;
	printf("Input n:");
	scanf_s("%d", &n);
	printf("Input k:");
	scanf_s("%u", &k);

	int res = n | (1 << k);
	printf("r=%d", res);

}