#include <stdio.h>
#include <math.h>
#define N 100

int main() {
    const char* fname = "F.dat";
    FILE* F = fopen(fname, "rb");
    int mas[N];
    int item;
    int k = 0;
    while (!feof(F)) {
        int res = fread(&item, sizeof(item), 1, F);
        if (res != 1) break;
        mas[k++] = item;
    }

    int v = 0;
    int d = 0;
    for (int i = 0; i < k; i++) {
        if (mas[i] > 0)d++;
        if (mas[i] < 0)v++;
    }
    if (d != v) {
        printf("There are not equal numbers of positive and negative numbers");
        return 0;
    }
    int v1 = 0;
    int d1 = 0;
    int mas2[N];
    for (int i = 0; i < k; i++) {
        if (mas[i] > 0) {
            mas2[d1] = mas[i];
            d1++;
        }
        if (mas[i] < 0) {
            mas2[v + v1] = mas[i];
            v1++;
        }
    }

    const char* fname2 = "G.dat";
    FILE* G = fopen(fname2, "wb");
    fwrite(mas2, sizeof(mas2), 2 * v, G);
    fclose(F);
    fclose(G);
}