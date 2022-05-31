#include <stdio.h>
#include <stdlib.h>

float sum_sqr(float* arr, int n) {
    float s = 0.f;
    for (int i = 0; i < n; i++) {
        s += arr[i] * arr[i];
    }
    return s;
}

int main() {
    int n;
    scanf_s("%d", &n);
    float* mas = (float*)malloc(n * sizeof(float)); // dynamic array   
    if (!mas) {
        printf("error in alloc memory");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("a[%d]=", i);
        scanf_s("%f", &mas[i]);
    }

    printf(" s= %f", sum_sqr(mas, n));

    free(mas);
}