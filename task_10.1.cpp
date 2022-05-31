#include <stdio.h>
#include <stdlib.h>

//a
struct Date
{
    unsigned day;
    unsigned month;
    int year;
};

//b
struct ChessField
{
    char v;
    unsigned char h;
};


//c
//struct Vertex
//{
//    float x, y;
//};


typedef struct 
{
    float x, y;    
} Vertex;

//struct Rectangle
//{
//    struct Vertex A;
//    struct Vertex B;
//}

typedef struct 
{
    Vertex A;
    Vertex B;
} Rectangle;

//d
typedef struct 
{
    size_t n;
    double* a; 
}Polynome;

int Rectangle_input(Rectangle* r)
{
    printf("A(x,y):");
    scanf("%f %f", &(r->A.x), &(r->A.y));
    printf("B(x,y):");
    scanf("%f %f", &(r->B.x), &(r->B.y));
    return EXIT_SUCCESS;
}

void Rectangle_output(Rectangle r)
{
    printf("A(%f, %f) - B(%f, %f)", r.A.x, r.A.y, r.B.x, r.B.y);
}

int main()
{

    Rectangle r;
    Rectangle_input(&r);
    Rectangle_output(r);
}