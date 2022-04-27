#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// examples of structures

typedef struct Date {
    unsigned day;
    unsigned month;
    int year;
}Date;

char mon[13][4] = { "", "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
unsigned daymon[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };

int inputDate(struct Date* dd) {
    do {
        printf("\nDay:");
        scanf_s(" %u", &(dd->day));
        printf("\nMonth:");
        scanf_s(" %u", &(dd->month));

        if (dd->day > daymon[dd->month]) continue;
        //TODO: leap-year month==2 
        printf("Year:");
        scanf_s(" %d", &(dd->year));
    } while (1);

    return 0;
}

void outputDate(Date dd) {

    //printf("%u.%u.%d\n", dd.day, dd.month, dd.year);
    printf("%u %s of %d\n", dd.day, mon[dd.month], dd.year);
}


Date tomorrow(Date dd) {
    Date tom = dd;
    if (dd.day >= daymon[dd.month]) {
        //TODO: leap-year month==2 
        if (dd.month == 12) {
            tom.year++;
            tom.month = 1;
            tom.day = 1;
        }
        else {
            tom.month++;
            tom.day = 1;
        }

    }
    else {
        tom.day++;
    }
    return tom;
}

const char* WEEK[] = { "Mon","Tue", "Wed","Thr","Fri", "Sut", "Sun"};

const char* weekday(Date dd) {
    unsigned d = 0;

    d = (dd.year - 1970) * 365;
    unsigned ly = (dd.year - 1968) / 4;
    d += ly;

    //TODO: leap-year
    for (unsigned i = 1; i < dd.month; i++) {
        d += daymon[i];
    }

    //d += d.day;

    return WEEK[d % 7];
}


struct ChessField {
    char h;
    unsigned char v;
};

bool inputChessField(struct ChessField* cf) {
    printf("\nH:");
    scanf_s(" %c", &(cf->h));
    printf("V:");
    scanf_s(" %hhu", &(cf->v));

    if (cf->v > 8 || cf->v == 0) return false;
    if (cf->h < 'a' || cf->h>'h') return false;
    return true;
}


void outputChessField(struct ChessField cf) {
    printf("%c%hhu:", cf.h, cf.v);
}


typedef struct {
    float x, y; // coordinates
}Vertex;


typedef struct {
    Vertex A;
    Vertex B;
} Rectangle;


int inputRectangle(Rectangle* r) {
    printf("A(x,y):");
    scanf_s("%f %f", &(r->A.x), &(r->A.y));
    printf("B(x,y):");
    scanf_s("%f %f", &(r->B.x), &(r->B.y));
    return EXIT_SUCCESS;
}

void outputRectangle(Rectangle r) {
    printf("A(%g, %g) - B(%g, %g)\n", r.A.x, r.A.y, r.B.x, r.B.y);
}

typedef struct {
    size_t n;
    double* a; //coefficients P(x) = a_0 + a_1* x + ...+ a_n*x^n 
}Polynome;

int inputPolynome(Polynome* p) {
    printf("n=");
    scanf_s("%zu", &p->n);
    p->a = (double*)calloc((p->n + 1), sizeof(*(p->a))); // *a == double
    for (size_t i = 0; i < p->n + 1; i++) {
        printf("a[%zu]=", i);
        scanf_s("%lf", &p->a[i]);
    }
    return p->n;
}

void printPolynome(const Polynome* p) {
    printf("%g", p->a[0]);
    for (size_t i = 1; i < p->n + 1; i++) {
        printf(" + %g*x^%zu", p->a[i], i);
    }
}

void freePolynome(Polynome* p) {
    free(p->a);
}

//int main() {
    /*Rectangle r;
    inputRectangle(&r);
    outputRectangle(r);

    struct ChessField w1,w2;
    if(inputChessField(&w1)){
       outputChessField(w1);
    }
   if(inputChessField(&w2)){
       outputChessField(w2);
    }*/

    /*Polynome p1;
    inputPolynome(&p1);
    printPolynome(&p1);
    freePolynome(&p1);*/

    /*Date d[] =  { {1,12,2001},
               {31,12,2001},
                  {31,3,2001},
                 {2,3,2001},
       };

   for(int i=0;i<4;i++)   {
    outputDate(tomorrow(d[i]));
   } */
//}