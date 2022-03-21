#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void prog5_1() {
	double a;
	printf("a = ");
	scanf_s("%lf", &a);
	double k = 0;
	int i = 1;
	while (a > k) {
		k = k + 1.0 / i;
		i++;
	}
	printf("%lf > %lf\n", k, a);
	printf("n = %d", i);
}


void prog5_2() {
	double a = 1000;
	unsigned n = 1,s=0;
	long long unsigned F0, F1, F;
	F0 = 0;
	F1 = 1;
	while (F1 < a) {
		F = F0 + F1;
		s += F;
		printf("F[%d]: %llu = %llu + %llu\n", n , F, F1, F0);
		F0 = F1;
		F1 = F;
		n++;
	}
	s -= F;
	printf("b) number: %u\n", n-2);
	printf("v) number: %u\n", n-1);
	printf("g) suma = %u", s);
}


int printAllKollatz(unsigned n, bool toPrint) {
	unsigned a = n;
	int i = 0;
	while (a != 1) {

		if (a % 2 == 0) {
			a = a / 2;
		}
		else {
			a = 3 * a + 1;
		}
		i++;
		if (toPrint)
			printf("a_%d = %u", i, a);
	}
	return i;
}
void prog5_3() {
	unsigned koll,i,n;

	printf("n = ");
	scanf_s("%u", &n);

	int max_m = 0, m;
	unsigned k;

	for (unsigned i = 1; i <=1000; i++) {
		m = printAllKollatz(i, false);
		
		if (max_m < m) {
			max_m = m;
			k = i;
		}
	}

	printf("k = %u", k);
	printAllKollatz(k, true);
}


long double fact(int N)
{
	if (N < 0)
		return 0;
	if (N == 0)
		return 1;
	else
		return N * fact(N - 1);
}
void prog5_4a() {
	int n = 19, i = 1;
	double P = 1;
	while (i <= n) {
		P *= (1 + 1 / fact(i));
		i++;
	}
	printf("P(%d) = %lf", n, P);
}


size_t min_rec() {
	size_t n = 3;
	int x, x1, x2, x3;

	x1 = x2 = x3 = -99;
	while (x3 < 0) {
		x = x1 + x3 + 100;
		printf("x[%d]: %d = %d + %d + 100\n", n + 1, x, x1, x3);

		x1 = x2;
		x2 = x3;
		x3 = x;
		n++;
	}
	return n;
}
void prog5_5() {
	printf("%zu", min_rec());
}


void prog5_6a() {
	double b, b_k;
	unsigned n;
	printf("b = ");
	scanf_s("%lf", &b);
	printf("n = ");
	scanf_s("%u", &n);
	b_k = b;
	for (unsigned i = 0; i < n; i++)
		b_k = b + 1 / b_k;
	printf("b_%u = %g\n", n, b_k);
}


void prog5_7() {
	int n;
	printf("n = ");
	scanf_s("%d", &n);

	double b0=1, b1=0, bk;
	double a0=0, a1=1, ak;

	double S= 2.0 / (a0 + b0);;

	if (n == 1) {
		printf("S=%lf", S);
		return;
	}

	S += 4.0 / (a1 + b1);
	if (n == 2) {
		printf("S=%lf", S);
		return;
	}

double power_of_two = 4.0;
for (int k = 3; k <= n; ++k) {
	bk = b1 + a1;
	ak = a1 / k + a0 * bk;

	power_of_two *= 2.0;
	S += power_of_two / (ak + bk);

	b0 = b1;
	b1 = bk;
	a0 = a1;
	a1 = ak;
}

printf("S = %lf", S);
}

int main() {
	//prog5_1();
	//prog5_2();
	//prog5_3();
	//prog5_4a();
	//prog5_5();
	//prog5_6a();
	//prog5_7();
}