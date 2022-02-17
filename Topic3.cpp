#include <stdio.h>
#include <math.h>
#include <inttypes.h>

void prog3_1() {
	int x = 346;
	int a = x / 100;
	int b = x / 10 - a*10;
	int c = x - a * 100 - b * 10;
	printf("a) %i: %i, %i, %i\n",x, a, b, c);
	printf("suma: %i\n",a+b+c);
	printf("%i%i%i", c, b, a);
}


void prog3_2() {
	int x;
	printf("x= ");
	scanf_s("%i", &x);
	int a = x / 100;
	int b = x / 10 - a * 10;
	int c = x - a * 100 - b * 10;
	if (a != b && c != b && a != c){
		printf("%i%i%i\n", a, b, c);
		printf("%i%i%i\n", c, c, b);
		printf("%i%i%i\n", b, a, a);
		printf("%i%i%i\n", b, a, c);
		printf("%i%i%i\n", c, b, a);
		printf("%i%i%i", c, a, b);
	}
	else
		printf("repeated number");
}


void prog3_3() {
  int32_t a, b, c;
  printf("a,b,c:\n");
  scanf_s("%d,%d,%d", &a, &b, &c);
  // a)
  int32_t d = a * b * c;
  printf("p=%d\n", d);

  // b)
  int64_t d1 = (int64_t)a * b * c;
  printf("p=%" PRId64"\n",d1);
}


uint16_t dobutok(uint8_t a, uint8_t b) {
	return (uint16_t)a * b;
}
void prog3_4() {
	unsigned char a, b;
	scanf_s("%hhu", &a);
	scanf_s("%hhu", &b);
	printf("%hu", dobutok(a, b));
}


void prog3_5() {
	unsigned a, b;
	scanf_s("%u %u", &a, &b);
	if (a > b) {
		printf("max=%u, min=%u,", a, b);
	}
	else {
		printf("max=%u, min=%u,", b, a);
	}
}


void prog3_6() {
	float a=4.435, b=-5.3819, c=-11.675;

	a = fabs(a);
	b = fabs(b);
	c = fabs(c);

	float f_min = a, f_max = b;

	if (b < a) {
		f_min = b;
		f_max = a;
	}
	if (f_min > c) {
		f_min = c;
	}
	if (f_max < c) {
		f_max = c;
	}
	printf("max = %f, min = %f", f_max, f_min);
}


#define EPS 0.000001
void prog3_7() {
	double a, b, c, x1, x2, d;

	scanf_s("%lf %lf %lf", &a, &b, &c);

	if (fabs(a) < EPS)
	{
		if (fabs(b) < EPS) {
			if (fabs(c) < EPS) {
				printf("Infinite number of solution");
			}
			else {
				printf("None solution");
			}
		}
		else {
			printf("1 solution: %lf", -c / b);
		}
	}
	else {
		d = b * b - 4 * a * c;
		if (fabs(d) < EPS) {
			printf("1 solution: %lf", -b / 2 / a);
		}
		else if (d > 0) {
			x1 = (-b + sqrt(d)) / 2 / a;
			x2 = (-b - sqrt(d)) / 2 / a;
			printf("2 solutions: %lf,%lf", x1, x2);
		}
		else {
			printf("None solutions");
		}
	}
}


uint32_t suma(uint32_t a, uint32_t b) {
	if (a + b > 4294967295) {
		printf("too big");
	}
	return (uint32_t)a + b;
}
uint32_t mult(uint32_t a, uint32_t b) {
	return (uint32_t)a * b;
}
void prog3_8() {
	unsigned long a, b;
	scanf_s("%lu", &a);
	scanf_s("%lu", &b);
	printf("%lu\n", suma(a, b));
	printf("%lu\n", mult(a, b));
}


double f_x_a(double x, double a) {
	if (x < 0) {
		return x / sqrt(1 + a * x * x);
	}
	else {
		return x;
	}
}
double g_x_a(double x, double a) {
	if (x < 0) {
		return (sqrt(1 + a * x * x) - a * x * x / sqrt(1 + a * x * x)) / (1 + a * x * x);
	}
	else {
		return 1;
	}
}
void prog3_23e() {

	double x = -0.3832, a = 462;

	printf("f(x,a) = %lf\n", f_x_a(x,a));
	printf("f'(x,a) = %lf", g_x_a(x, a));
}


int main() {
	//prog3_1();
	//prog3_2();
	//prog3_3();
	//prog3_4();
	//prog3_5();
	//prog3_6();
	//prog3_7();
	//prog3_8();
	//prog3_23e();
}
