#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>


void prog7_1() {
    int mas[] = { 5,12,3,4,7 };
    int N = 5;
    double a;
    printf("a=");
    scanf_s("%lf", &a);

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (mas[i] < a) count++;
    }

    printf("K=%d", count);
}


void prog7_2() {
    int mas[] = { 5,112,4,3 };
    for (int i = 3; i > -1; i--) {
        printf("%d\n", mas[i]);
    }
}


#define N 10
double func(double m[N]) {
    double sum = 0;
    for (int i = 0; i < N; i++) {
        if (m[i] > M_E) {
            sum += m[i];
        }
    }
    return sum;
}
void prog7_3() {
    double mas[N];

    for (int i = 0; i < N; i++) {
        printf("mas[%d] = ", i);
        scanf_s("%lf", &mas[i]);
    }
    printf("result: %lf", func(mas));
}


#define N 5
int max(int m[N]) {
    int f = 0;
    for (int i = 0; i < N; i++) {
        printf("%d,", m[i]);
        if (m[i] > f) {
            f = m[i];
        }
    }
    printf("]");
    return f;
}
void prog7_4() {
    int mas[N];

    for (int i = 0; i < N; i++) {
        printf("mas[%d] = ", i);
        scanf_s("%d", &mas[i]);
    }
    printf("[");
    printf("\nmax: %d", max(mas));
}


#define N 50
int count(int m[N]) {
    int even = 0;
    int odd = 0;
    for (int i = 0; i < N; i++) {
        if (m[i] % 2 != 0) {
            odd++;
        }
        else even++;
        if (m[i] == 0) {
            even--;
            break;
        }
    }
    printf("odd: %d,even: %d\n", odd, even);
    return 1;
}
void prog7_5() {
    int mas[N];

    for (int i = 0; i < N; i++) {
        printf("mas[%d] = ", i);
        scanf_s("%d", &mas[i]);
        if (mas[i] == 0) {
            break;
        }
    }
    count(mas);
}


#define N 20
int input(double mas[], int size);
void output(const double mas[], int size);
int scal_sum(const double mas1[], const double mas2[], double mas3[], int size);
double scal_mult(const double mas1[], const double mas2[], int size);
double* diff_vect(const double mas1[], const double mas2[], int size);

void prog7_6() {

    double mas1[N];
    double mas2[N];
    double mas3[N];

    unsigned n;
    double dob;

    do {
        printf("N=");
        scanf_s("%u", &n);
    } while (n == 0 || n > 20);


    input(mas1, n);
    input(mas2, n);

    dob = scal_mult(mas1, mas2, n);

    scal_sum(mas1, mas2, mas3, n);

    printf("Dobutok =%lf", dob);

    output(mas3, n);
}
int input(double mas[], int size) {

    for (int i = 0; i < size; i++) {
        printf("mas[%d]=", i);
        scanf_s("%lf", &mas[i]);
    }

    return size;
}
void output(const double mas[], int size) {

    for (int i = 0; i < size; i++) {
        printf("\n mas[%d]= %lf", i, mas[i]);
    }
}
int scal_sum(const double mas1[], const double mas2[], double mas3[], int size) {

    for (int i = 0; i < size; i++) {
        mas3[i] = mas1[i] + mas2[i];
    }

    return 0;
}
double scal_mult(const double mas1[], const double mas2[], int size) {

    double res = 0;
    for (int i = 0; i < size; i++) {
        res += mas1[i] * mas2[i];
    }

    return res;
}
double* diff_vect(const double mas1[], const double mas2[], int size) {
    static double mas3[N];
    for (int i = 0; i < size; i++) {
        mas3[i] = mas1[i] - mas2[i];
    }

    return mas3;
}


void enter_arr(int n, double* arr) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf_s("%lf", &arr[i]);
    }
}
void print_arr(int n, const double* arr) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %lf", i, arr[i]);
    }
    printf("\n");
}
void sum_arr(int n, const double* arr1, const double* arr2, double* a) {

    for (int i = 0; i < n; i++) {
        a[i] = arr1[i] + arr2[i];
    }

}
double dob_arr(int n, const double arr1[], const double arr2[]) {
    double dob = 0;
    for (int i = 0; i < n; i++) {
        dob += arr1[i] * arr2[i];
    }
    return dob;
}
int prog7_6a() {

    double arr1[4];
    enter_arr(4, arr1);
    print_arr(4, arr1);
    double arr2[4];
    enter_arr(4, arr2);
    print_arr(4, arr2);
    double arr3[4];
    sum_arr(4, arr1, arr2, arr3);
    print_arr(4, arr3);
    printf("Dob:%lf \n", dob_arr(4, arr1, arr2));
}


void prog7_9e() {
    int n = 6, i;
    double a1 = 5.3, a2 = -7.8, a3 = 4.456, a4 = -9.27, a5 = 8.452, a6 = 9.123;
    double mas[] = { a1,a2,a3,a4,a5,a6 };
    double max = a1;
    for (i = 0; i < n; i++) {
        double v = mas[i];
        if (v < 0) {
            v = -v;
        }
        if (v > max) {
            max = v;
        }
    }
    printf("[");
    for (i = 0; i < n; i++)
        printf("m[%d] = %.3f, ", i+1, mas[i]);
    printf("]");
    printf("\nmax abcolute value: %.3f", max);
}


void prog7_17() {
    int n = 12, i;
    int a1 = 5, a2 = 1, a3 = 2, a4 = 2, a5 = 1, a6 = 2, a7 = 3, a8 = 5, a9 = 4, a10 = 5, a11 = 5, a12 = 2;
    int mas[] = { a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12 };
    int max = a1, min = a1;
    double val = 0;
    for (i = 0; i < n; i++) {
        int v = mas[i];
        printf("mas[%d]=%d ", i + 1, v);
        val += v;
        if (v > max) {
            max = v;
        }
        if (v < min) {
            min = v;
        }
    }
    printf("\nyour result: %.2f", (val - max - min) / (n - 2));
}


int main() {
    //prog7_1();
    //prog7_2();
    //prog7_3();
    //prog7_4();
    //prog7_5();
    //prog7_6();
    //prog7_6a();
    //prog7_9e();
    //prog7_17();
}