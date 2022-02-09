#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>

void prog1_4()
{
	double G = 6.673 * pow(10, -11);

	double m1;
	printf("m1=");
	scanf_s("%lf", &m1);

	double m2;
	printf("m2=");
	scanf_s("%lf", &m2);

	double r;
	printf("r=");
	scanf_s("%lf", &r);

	double F = G * m1 * m2 * pow(r, -2);
	printf("F=%g", F);
}

void prog1_5d() 
{
	double x;
	printf("x=");
	scanf_s("%lf", &x);
	double x2 = x * x;
	double x4 = x2 * x2;
	double x8 = x4 * x4;
	double x16 = x8 * x8;
	double x28 = x16 * x8* x4;
	printf("x28 = % g", x28);
}

void prog1_6() 
{
	double C, F;
	printf("C=");
	scanf_s("%lf", &C);
	F = 9 * C / 5 + 32;
	printf("F=%g", F);
}

void prog1_7()
{
	double x;
	printf("x=");
	scanf_s("%lf", &x);

	//[x]
	int z1 = (int)x;
	if (x < 0) {
		z1--;
	}
	printf("[%lf]=%d\n", x, z1);

	//{x}
	double fp_x = x - z1;
	printf("{%lf}=%lf\n", x, fp_x);

	//]x[
	int z2 = (int)x;
	if (x >= 0) {
		if (fp_x > 0)
			z2++;
	}
	printf("]%lf[=%d\n", x, z2);
}

void prog1_8()
{
	double a, b;

	printf("a=");
	scanf_s("%lf", &a);
	printf("b=");
	scanf_s("%lf", &b);
	printf("%g - %g = %lf\n", a, b, a - b);
	printf("%g * %g = %lf\n", a, b, a * b);
}

void prog1_9() 
{
	double a, b;
	printf("введіть числа a та b");
	std::cin >> a >> b;

	double a_mean = (a + b) / 2,
		h_mean = 2 / (1 / a + 1 / b);

	printf("a_mean = %g\n", a_mean);
	printf("h_mean = %g\n", h_mean);
}

void prog1_16() {
	printf("x|    1     |    2     |    3     |    4     |    5     |\n");
	printf("-|----------|----------|----------|----------|----------|\n");
	//printf("%10.2f", 12.234657);
	double y1 = int(exp(-1 * 1) * 100 + 0.5) / 100.0;
	double y2 = int(exp(-2 * 2) * 100 + 0.5) / 100.0;
	double y3 = int(exp(-3 * 3) * 100 + 0.5) / 100.0;
	double y4 = int(exp(-4 * 4) * 100 + 0.5) / 100.0;
	double y5 = int(exp(-5 * 5) * 100 + 0.5) / 100.0;
	printf("Y| %f | %f | %f | %f | %f |\n",y1, y2, y3, y4, y5);
	double f1 = int(sqrt(1) * 100 + 0.5) / 100.0;
	double f2 = int(sqrt(2) * 100 + 0.5) / 100.0;
	double f3 = int(sqrt(3) * 100 + 0.5) / 100.0;
	double f4 = int(sqrt(4) * 100 + 0.5) / 100.0;
	double f5 = int(sqrt(5) * 100 + 0.5) / 100.0;
	printf("F| %f | %f | %f | %f | %f |\n", f1, f2, f3, f4, f5);
}

void prog1_20() 
{
	double a, b, c;
	int input = scanf_s("A=%lf, B=%lf, C=%lf", &a, &b, &c);
	if (input != 3) {
		printf("error");
	}
	double A_3 = (a + b + c) / 3;
	double G_3 = 3.0/(1/a+1/b+1/c);
	printf("A_3=%lf, G_3=%lf", A_3, G_3);
}

void prog1_14()
{
	double a=3, v=12, t=5;
	double S_t = a * t * t / 2;
	double t_v = v / a;
	printf("S(%lf)=%lf, t(%lf)=%lf", t, S_t, v, t_v);
}

int main() {
	//prog1_4();
	//prog1_5d();
	//prog1_6();
	//prog1_7();
	//prog1_8();
	//prog1_9();
	//prog1_14();
	//prog1_16();
	//prog1_20();
}