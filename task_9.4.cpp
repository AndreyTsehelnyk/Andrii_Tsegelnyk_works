#include <stdio.h>
#include <stdlib.h>
#include <cmath>


//a
double** input_mat(int n) {
	double** a = (double**)calloc(n, sizeof(*a));
	for (int i = 0; i < n; i++) {
		a[i] = (double*)calloc(n, sizeof(*a[i]));
		for (int j = 0; j < n; j++) {
			printf("a[%d][%d]", i, j);
			scanf_s("%lf", &a[i][j]);
		}
	}
	return a;
}


void free_matr(double** v1, int n) {
	for (int i = 0; i < n; i++) {
		free(v1[i]);
	}
	free(v1);
}

double** mult_matr(double** v1, double** v2, unsigned dim) {
	double** res = (double**)calloc(dim, sizeof(double*));
	for (unsigned i = 0; i < dim; i++) {
		res[i] = (double*)calloc(dim, sizeof(res[i]));
		for (unsigned j = 0; j < dim; j++) {
			for (unsigned k = 0; k < dim; k++) {
				res[i][j] += v1[i][k] * v2[i][k];
			}
		}
	}
	return res;
}


void mat_out(double** v, unsigned n) {
	unsigned i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%g  ", v[i][j]);
		}
		printf("\n");
	}
}

//b
double* input_mat1(int n) {
	double* a = (double*)calloc(n * n, sizeof(a));
	for (int i = 0; i < n * n; i++) {
		printf("a[%d]", i);
		scanf_s("%lf", &a[i]);
	}
	return a;
}

void mat_out1(double* v, unsigned n) {
	unsigned i;
	for (i = 0; i < n * n; i++) {
		printf("%g  ", v[i]);
		if ((i + 1) % n == 0 && i != 0) printf("\n");
	}
}

void free_matr1(double* v1) {
	free(v1);
}

double* mult_matr1(double* v1, double* v2, unsigned n, unsigned j) {
	double* res = (double*)calloc(n * n, sizeof(double));
	unsigned j = 0, k = 0, i = 0;
	for (unsigned i = 0; i < n * n; i++) {

		if ((i + 1) % n != 0) {

			for (unsigned t = 0; t < n; t++) {
				res[i] += v1[j] * v2[k];
				j += 1;
				k += n;
			}
			k = j;
			j -= i;
		}
		else {
		}

	}

	return res;
}


int main() {
	/*a
	int n;
	printf("n=");
	scanf_s("%d", &n);
	double** v1 = input_mat(n);
	double** v2 = input_mat(n);
	double** v3 = mult_matr(v1, v2, n);
	mat_out(v3, n);
	free_matr(v1, n);
	free_matr(v2, n);
	free_matr(v3, n);*/

	/*b
	int m;
	printf("n=");
	scanf_s("%d", &m);

	double* v4 = input_mat1(m);
	double* v5 = input_mat1(m);


	double* v6 = mult_matr1(v4, v5, m);

	mat_out1(v6, m);
	free_matr1(v4);
	free_matr1(v5);
	free_matr1(v6);
	*/
}