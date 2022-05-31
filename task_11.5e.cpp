#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>


typedef struct {
    double coef;
    unsigned deg;
} Poly_Coef;


typedef struct Poly {
    unsigned m;
    Poly_Coef* coefs;
} Poly;


int input(Poly_Coef* r) {

    printf("deg=");
    scanf(" %d", &r->deg);

    printf("coef=");
    scanf(" %lf", &r->coef);
    return 0;
}

void printCoef(const Poly_Coef r) {
    printf("%lf*x^%u", r.coef, r.deg);
}

int inputPolynom(Poly* p) {

    printf("Power n=");
    scanf(" %u", &p->m);
    p->coefs = calloc(p->m, sizeof(Poly_Coef));

    Poly_Coef x;
    for (int i = 0; i < m; ++i) {
        input(&x);
        p->coefs[i] = x;
    }

}

void deletePoly(Poly* p) {
    free(p->coefs);
}

int createPoly(unsigned m, Poly* p) {
    p->m = m;
    p->coefs = calloc(p->m, sizeof(Poly_Coef));
}



Poly readFilePoly(const char* fname, unsigned num) {
    FILE* fp = fopen(fname, "rb"); // open file binary, for reading
    if (fp == NULL) {
        fprintf(stderr, "Error open file %s", fname);
        return -1;
    }
    Poly_Coef x;
    Poly z;
    unsigned number = 0;
    while (!feof(fp)) {
        int m;
        int res = fread(&m, sizeof(m), 1, fp); // read number of monoms  
        if (res < 1) { printf("EOF %d\n", res); break; }

        number++;
        if (number == num) {

            createPoly(z);

            for (int j = 0; j < m; ++j) {
                res = fread(&x, sizeof(x), 1, fp); // read 1 struct from F
                if (res < 1) { printf("EOF %d\n", res); break; }
                z.coef[j] = x;
            }

            if (res < 1) { printf("EOF %d\n", res); break; }

        }
        printf("\n");
        fclose(fp);
        return z;
    }


    int inputPoly(const char* fname) {

        FILE* f1 = fopen(fname, "a+b");

        if (f1 == NULL) {
            printf("error file %s", fname);
            return -1;
        }
        unsigned m;
        printf("number of monoms=");
        scanf("%u", &m);

        fwrite(&m, sizeof(m), 1, f1);

        Poly_Coef coef;
        for (unsigned i = 0; i < m; i++) {
            input(&coef);
            fwrite(&coef, sizeof(coef), 1, f1);
        }

        fclose(f1);
        return 0;
    }


    int writePolynomesToFile(const char* fname) {

        remove(fname);

        int n;
        printf("Number of Polinomes:");
        scanf("%d", &n);

        for (int i = 0; i < n; ++i) {
            inputPoly(fname);
        }
        return 0;
    }


    int readFile(const char* fname, unsigned num) {
        FILE* fp = fopen(fname, "rb"); // open file binary, for reading
        if (fp == NULL) {
            fprintf(stderr, "Error open file %s", fname);
            return -1;
        }
        Poly_Coef x;
        unsigned number = 0;
        while (!feof(fp)) {
            int m;
            int res = fread(&m, sizeof(m), 1, fp); // read number of monoms  
            if (res < 1) { printf("EOF %d\n", res); break; }

            number++;

            for (int j = 0; j < m; ++j) {
                res = fread(&x, sizeof(x), 1, fp); // read 1 struct from F
                if (res < 1) { printf("EOF %d\n", res); break; }
                if (number == num) {
                    printf("+");
                    printCoef(x);
                }
            }

            if (res < 1) { printf("EOF %d\n", res); break; }

        }
        printf("\n");
        fclose(fp);
    }


    int readFileDerivative(const char* fname, unsigned num) {
        FILE* fp = fopen(fname, "rb"); // open file binary, for reading
        if (fp == NULL) {
            fprintf(stderr, "Error open file %s", fname);
            return -1;
        }
        Poly_Coef x;
        unsigned number = 0;
        while (!feof(fp)) {
            int m;
            int res = fread(&m, sizeof(m), 1, fp); // read number of monoms  
            if (res < 1) { printf("EOF %d\n", res); break; }

            number++;

            for (int j = 0; j < m; ++j) {
                res = fread(&x, sizeof(x), 1, fp); // read 1 struct from F
                if (res < 1) { printf("EOF %d\n", res); break; }
                if (number == num) {
                    int deg = x.deg - 1;
                    double coef1 = x.coef * x.deg;
                    if (coef1 == 0) {
                        continue;
                    }
                    if (deg == 0)
                        printf("+%lf", coef);
                    else {
                        printf("+%lf*x^%d", coef, deg);
                    }

                }
            }

            if (res < 1) { printf("EOF %d\n", res); break; }

        }
        printf("\n");
        fclose(fp);
    }


    int getPoly(const char* fname, unsigned num, double* poly, unsigned pwr) {

        FILE* fp = fopen(fname, "rb"); // open file binary, for writing
        if (fp == NULL) {
            fprintf(stderr, "Error open file %s", fname);
            return -1;
        }
        Poly_Coef x;
        int k = -1;
        while (!feof(fp)) {

            int res = fread(&x, sizeof(x), 1, fp); // read 1 struct from F

            if (res < 1) {
                // printf("EOF %d\n",res); 
                break;
            }

            if (x.num == num) {
                if (x.deg < pwr) {
                    poly[x.deg] = x.coef;
                    if (k < x.deg) {
                        k = x.deg;
                    }
                }
                else {
                    printf("degree %u> power %u", x.deg, pwr);
                }
            }

        }

        fclose(fp);

        return k;

    }

    int safeGetPoly(const char* fname, unsigned num, double** pol) {
        FILE* fp = fopen(fname, "rb"); // open file binary, for writing
        if (fp == NULL) {
            fprintf(stderr, "Error open file %s", fname);
            return -1;
        }
        Poly_Coef x;
        int k = -1;
        while (!feof(fp)) {

            int res = fread(&x, sizeof(x), 1, fp); // read 1 struct from F

            if (res < 1) {
                // printf("EOF %d\n",res); 
                break;
            }

            if (x.num == num) {
                if (k < x.deg) {
                    k = x.deg;
                }

            }

        }

        if (k == -1) return 0;

        //fclose(fp);  
        double* p = (double*)calloc(k + 1, sizeof(*p));

        freopen(fname, "rb", fp);
        while (!feof(fp)) {
            int res = fread(&x, sizeof(x), 1, fp); // read 1 struct from F    
            if (res < 1) {
                // printf("EOF %d\n",res); 
                break;
            }

            if (x.num == num) {
                p[x.deg] = x.coef;
            }

        }

        fclose(fp);

        *pol = p;
        return k;
    }


    void printPoly(const double* a, unsigned pwr) {

        printf("%lf*x^%u", a[pwr - 1], pwr - 1);
        for (int i = pwr - 2; i >= 0; i--) {
            if (fabs(a[i]) < 0.001) continue;
            if (a[i] < 0) {
                printf("%lf*x^%u", a[i], i);
            }
            else {
                printf("+%lf*x^%u", a[i], i);
            }
        }

    }

    int replacePoly(const char* fname, unsigned num, unsigned deg, double coef) {

    }

        FILE* fp = fopen(fname, "ab");
        if (fp == NULL) {
            fprintf(stderr, "Error open file %s", fname);
            return -1;
        }

        fseek(fp, n, 0);

        fwrite(&r, sizeof(r), 1, fp);

        fclose(fp);
    }

#define MAX_POLY_DEG 10

int main() {
    char* f = "poly.dat";

    replacePoly(f, 1, 1, 2.0);
}