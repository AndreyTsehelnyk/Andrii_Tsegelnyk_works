#include <stdio.h>
#include <stdlib.h>

void input(double* ar, int n) {
    for (int i = 0; i < n; ++i) {
        printf("a[%d]=", i);
        scanf("%lf", &ar[i]);
    }

}

int writeFile(const char* fname, double* ar, int n) {

    FILE* fp = fopen(fname, "wb"); 
    int res = fwrite(ar, sizeof(*ar), n, fp); 
    fclose(fp); 
    printf("re=%d", res);
    return res;
}

int readFile(const char* fname, double* ar) {

    FILE* fp = fopen(fname, "rb"); 
    double item;
    int k = 0;
    while (!feof(fp)) {
        int res = fread(&item, sizeof(item), 1, fp); 
        if (res != 1) break;
        ar[k++] = item;
    }

    fclose(fp);
    return k;
}


int main() {
    int n;
    printf("n=");
    scanf("%d", &n);
    double* mas = (double*)malloc(n * sizeof(double));
    input(mas, n);

    char fname[20];
    printf("file name:");
    scanf("%s", fname);

    int res = writeFile(fname, mas, n);
    if (res != n) {
        printf("Not all data were written");
    }
    else {
        double* mas2 = (double*)malloc(n * sizeof(double));

        int m = readFile(fname, mas2);
        printf("\n");
        for (int i = 0; i < m - 1; ++i) {
            printf("%lf, ", mas2[i]);
        }
        printf("%lf", mas2[m - 1]);
        free(mas2);
    }


    free(mas);
}