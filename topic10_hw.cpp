#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct {
    float R, x, y, z;
}Param;


typedef struct {
    Param O;
} Sphere;


int inputSphere(Sphere* s) {
    printf("R, O(x,y,z):");
    scanf_s("%f %f %f %f", &(s->O.R), &(s->O.x), &(s->O.y), &(s->O.z));
    return EXIT_SUCCESS;
}

void outputSphere(Sphere s) {
    printf("O(%g, %g, %g), R= %g", s.O.x, s.O.y, s.O.z, s.O.R);
}

void prog10_6j() {
    Sphere s;
    inputSphere(&s);
    outputSphere(s);
}




typedef struct {
    char n, gr;
    int m1, m2, m3;
} Student;


int low(int m1,int m2,int m3) {
    int min = 0;
    if (m1 < m2) {
        min = m1;
    }
    else min=m2;
    if (m3 < min) {
        min = m3;
    }
    if (min == m1) {
        printf("subject number %d = %d",1, min);
    }
    if (min == m2) {
        printf("subject number %d = %d", 2, min);
    }
    if (min == m2) {
        printf("subject number %d = %d", 3, min);
    }
    return 1;
}

void prog10_16bv() {
    Student one;
    one.n = 'a';
    one.gr = '1';
    one.m1 = 5;
    one.m2 = 5;
    one.m3 = 5;
    Student two;
    two.n = 'b';
    two.gr = '1';
    two.m1 = 3;
    two.m2 = 5;
    two.m3 = 2;
    Student three;
    three.n = 'a';
    three.gr = '1';
    three.m1 = 4;
    three.m2 = 3;
    three.m3 = 5;
    low(one.m1,one.m2,one.m3);
    low(two.m1, two.m2, two.m3);
    low(three.m1, three.m2, three.m3);
}

int main() {
	//prog10_6j(); 
	//prog10_16bv();
}