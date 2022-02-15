#include <stdio.h>
#include <math.h>
#include <iostream>

void prog2_1() {
	double x;
	printf("x=");
	scanf_s("%lf", &x);
	printf("cosx=%g", cos(x));
}


void prog2_2() {
	double a,b;
	printf("a=");
	scanf_s("%lf", &a);
	printf("b=");
	scanf_s("%lf", &b);
	printf("c=%g", hypot(a,b));
}


void prog2_3() {
	double a, b, c;
	printf("a=");
	scanf_s("%lf", &a);
	printf("b=");
	scanf_s("%lf", &b);
	printf("c=");
	scanf_s("%lf", &c);
	double p = (a + b + c) / 2;
	printf("S=%g", sqrt(p*(p-a) * (p - b) * (p - c)));
}


void prog2_4a() {
	double x;
	printf("x=");
	scanf_s("%lf", &x);
	double y = pow((x * x + 1), 2);
	printf("f(x)=%g", y);
}


double Rosenbrock2d(double x, double y) {
	return 100 * (x * x - y) * (x * x - y) + (x - 1) * (x - 1);
}
void prog2_5() {
	double x1 = 5.1, y1 = -0.45245, x2 = 7294.65583, y2 = 5.328482, x3 = -48392.94487, y3 = -473.39473;
	printf("x1 = %g, y1 = %g, Rosenbrock2d(x1,y1)= %g\n", x1, y1, Rosenbrock2d(x1, y1));
	printf("x2 = %g, y2 = %g, Rosenbrock2d(x2,y2)= %g\n", x2, y2, Rosenbrock2d(x2, y2));
	printf("x3 = %g, y3 = %g, Rosenbrock2d(x3,y3)= %g", x3, y3, Rosenbrock2d(x3, y3));
}

double lenght(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
double square(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
void prog2_6()
{
	double x1, y1, x2, y2, x3, y3;
	printf("A1 A2: ");
	std::cin >> x1 >> y1;
	printf("\n");
	printf("B1 B2: ");
	std::cin >> x2 >> y2;
	printf("\n");
	printf("C1 C2: ");
	std::cin >> x3 >> y3;
	printf("S=%g", square(lenght(x1, y1, x2, y2), lenght(x2, y2, x3, y3), lenght(x1, y1, x3, y3)));
}


double func_a(double x, double y) {
	return pow(x + y, 3);
}
double func_b(double x, double y) {
	return pow(x * y, 2) + pow(x * y, 3) + pow(x * y, 4);
}
void prog2_15() {
	double x, y;
	printf("x y:");
	std::cin >> x >> y;
	printf("func1=%g\n", func_a(x, y));
	printf("func2=%g", func_b(x, y));
}

double f_x(double x) {
	return x / (1 + exp(-x));
}
double g_x(double x) {
	return (1 + exp(-x) + x * exp(-x)) / pow((1 + exp(-x)), 2);
}
void prog2_17z() {
	double x = 3.3729;
	printf("f(x)=%lf\n", f_x(x));
	printf("f'(x)=%lf", g_x(x));
}

int main() {
	//prog2_1();
	//prog2_2();
	//prog2_3();
	//prog2_4a();
	//prog2_5();
	//prog2_6();
	//prog2_15();
	//prog2_17z();
}