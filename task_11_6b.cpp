#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable : 4996)

#define END 0
int square_root(int x) {
	for (int i = 1; i <= x / 2; i++) {
		if (i * i == x) {
			return i;
		}
	}
	return -1;
}

int create_file(const char* fnameF) {
	FILE* fp = fopen(fnameF, "wb");
	if (fp == NULL) {
		printf("Error opening %s", fnameF);
		return -1;
	}
	int tmp;
	do {
		printf("x=");
		scanf("%d", &tmp);
		if (tmp==END) break;
		fwrite(&tmp, sizeof(tmp), 1, fp);
	} while (1);
	fclose(fp);
	return 0;
}


int main() {
	const char* fname = "numbers.dat";
	int k=0;
	create_file(fname);
	FILE* Fp = fopen(fname, "rb");
	if (Fp == NULL) {
		printf("Error opening %s", fname);
		return -1;
	}
	int tmp;
	int res = 1;
	do {
		int res = fread(&tmp, sizeof(tmp), 1, Fp);
		printf("Square root of %d=%d\n", tmp, square_root(tmp));
		if (square_root(tmp) % 2 == 1) {
			k++;
		}
		if (res != 1) {
			break;
		}
	} while (!feof(Fp));
	printf("Result is %d", k-1);
	fclose(Fp);
}
