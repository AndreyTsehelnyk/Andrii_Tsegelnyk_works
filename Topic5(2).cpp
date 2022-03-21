#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string>
#include <iostream>

double my_exp(double x, double eps) {
	double y = 1.0;
	double t = 1.0;
	int k = 0;

	while (fabs(t) > eps) {
		k++;
		t *= x / k;
		y += t;
	}
	return y;
}
double my_phi(double x, double eps) {
	double t = -x * x * x / 3;
	double y = x + t;
	int k = 1;

	while (fabs(t) > eps) {
		k++;
		t *= -x * x / (2 * k + 1) / (2 * k - 2);
		y += t;
	}
	return y;
}
void prog5_8() {
	double eps, x;

	printf("x= ");
	scanf_s("%lf", &x);

	do {
		printf("eps= ");
		scanf_s("%lf", &eps);
	} while (eps <= 0);

	printf("my exp(%lf): %lf, real exp(%lf) = %lf\n", x, my_exp(x, eps), x, exp(x));
	printf("my phi(%lf): %lf", x, my_phi(x, eps));
}


void prog5_11a() {
	int a1 = 0, a2 = 1, a3, k = 3, n;
	unsigned long long S = 2*a1+2*2*a2;

	printf("n = ");
	scanf_s("%d", &n);
	while (k <= n) {
		a3 = a2 + k * a1;
		S += a3 * pow(2, k);
		a1 = a2;
		a2 = a3;
		k++;
	}
	printf("S_%d = %llu", n, S);
}


void prog5_17v() {
	double eps = 0.000001, x, t = 1;
	printf("x = ");
	scanf_s("%lf", &x);
	unsigned long long s = 0;
	int k = 1;
	while (t >= eps) {
		s += t;
		printf("t_%d = %lf\n", k, t);
		t *= x * x / 2 / k;
		k++;
	}
	printf("summa %d term: %llu", k, s);
}


int item_a(int k) {
	int i = 1, p = 2,l=2;
	int res;
	if (k == 1) {
		res = 1;
	}
	while (i < k) {         	    
		i++;
		if (i%p==0) {
			res = 1;
			p+=l;
			l++;
		}
		else res = 0;
	}
	return res;
}
int item_v(int k) {
	int i = 1, len = 0;
	int res;
	while (len < k) {
		res = i * i;
		std::string s = std::to_string(res);
		len += s.size();
		
		i++;
	}

	while (len > k) {
		res = res / 10;
		len--;
	}
	if (len == k) {
		res = res % 10;
	}
	return res;
	
}
void prog5_18() {
	int k;
	printf("k = ");
	scanf_s("%d", &k);
	printf("a) %d\n", item_a(k));
	printf("v) %d\n", item_v(k));
}


double eqn(double x) {
	return tan(x) - x;
}
double root(double eps, double a, double b) {
	double mid = (a + b) / 2.0;

	if (b - a < eps) {
		return mid;
	}


	if (fabs(eqn(mid)) < eps) {
		return mid;
	}

	if (eqn(a) * eqn(mid) <= 0) {
		return root(eps, a, mid);
	}
	else {
		return root(eps, mid, b);
	}
}
void prog5_19() {
	double eps, x;

	do {
		printf("eps= ");
		scanf_s("%lf", &eps);
		if (eps > 0) break;
		printf("problem");
	} while (1);

	x = root(eps, -1, 0.5);
	printf("tg(%lf) = %lf, as tg(%lf) = %lf", x, x, x, tan(x));
}


double y(double x) {
	return x * x * x + 4 * x * x + x - 6;
}
double root2(double eps, double a, double b) {
	double x0=a, x1=a, x2=b;

	while (fabs(x2 - x1) >= eps) {
		x1 = x2;
		x2 = x1 - y(x1) * (x1 - x0) / (y(x1) - y(x0));

	}
	return x2;
}
void prog5_20() {
	double eps=0.001, x;

	x = root2(eps, 0, 2.0);
	printf("x = %lf", x);
}


int main() {
	//prog5_8();
	//prog5_11a();
	//prog5_17v();
	//prog5_18();
	//prog5_19();
	//prog5_20();
}