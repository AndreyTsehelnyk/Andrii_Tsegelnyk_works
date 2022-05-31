#include <stdio.h>
#include <stdbool.h>


typedef struct
{
    int numerator;
    unsigned int denominator;
} Rational;


void outputR(Rational x)
{
    printf("%d/%u\n", x.numerator, x.denominator);
}


int inputR(Rational* x)
{
    printf("Num: ");
    scanf("%d", &x->numerator);
    printf("Den: ");
    scanf("%u", &x->denominator);
    if(x->denominator == 0) return 0;
    return 2;
}


Rational addR(Rational x, Rational y)
{
    Rational z;
    z.numerator = x.numerator * y.denominator + y.numerator * x.denominator;
    z.denominator = x.denominator * y.denominator;
    return z;
}


Rational multR(Rational x, Rational y)
{
    Rational z;
    z.numerator = x.numerator * y.numerator;
    z.denominator = x.denominator * y.denominator;
    return z;
}


bool greaterR(Rational x, Rational y)
{
    return (x.numerator * y.denominator > y.numerator * x.denominator);
}


bool cmpR(Rational x, Rational y)
{
    return (x.numerator * y.denominator == y.numerator * x.denominator);
}


unsigned gcd( unsigned x, unsigned y)
{
    if(y>x) return gcd(x,y);
    if(y==0) return x;
    return gcd(y, x%y);
}


void reduce(Rational* x)
{
    unsigned d = gcd(x->numerator, x->denominator);
    x->numerator /= d;
    x->denominator /= d;
}


int main()
{
    Rational r1, r2, r3;
    inputR(&r1);
    inputR(&r2);
    r3 = addR(r1, r2);
    outputR(r3);
    r3 = multR(r1, r2);
    outputR(r3);

    if (cmpR (r1, r2)) 
    {
        printf("R1 == R2");
    } else{
        printf("R2 > R1");
    }
}