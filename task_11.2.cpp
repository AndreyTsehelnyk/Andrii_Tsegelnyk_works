#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "files_work.h"

int write(FILE* fp)
{
    double x;
    int cnt = 0;
    char c;

    while (1) 
    {
        printf("Input another real? y/n");
        c = (char) getchar();
        c = tolower(c);

        while (c!='y' && c!='n') 
        {
            printf("Yes or No? y/n");
            c = (char) getchar();
            c = tolower(c);
        }

        if(c=='n')break;
        printf("x = ");
        scanf("%lf", &x);
        fwrite(&x, sizeof(x), 1, fp);
    }
    return cnt;
}


int read(FILE* fp)
{
    double x;
    int cnt = 0;

    do 
    {
        int r = fread(&x, sizeof(x), 1, fp);
        if (r!=1) break;
        printf("%f", x);
        cnt++;
    } while (1);
    return cnt;
}


int transfer(FILE* F, FILE* G, double a)
{
    double x;

    do 
    {
        int r = fread(&x, sizeof(x), 1, F);
        if (r!=1) break;
        if (x<a) {
            fwrite(&x, sizeof(x), 1, G);
        }
    } while (1);
    return 0;
}

int exclude(FILE* F, double a)
{
    FILE* ftmp = fopen("file.dat", "wb");
    double x;
    
    do 
    {
        int r = fread(&x, sizeof(x), 1, F);
        if (r!=1) break;
        if (x>=a) {
            fwrite(&x, sizeof(x), 1, ftmp);
        }
    } while (1);

    fclose(ftmp);
    return 0;
}


int main()
{
    char fname[] = "F.dat";
    char gname[] = "G.dat";
    FILE* F = fopen(fname,"wb");

    if (F==NULL)
    {
        printf("Error");
        return -1;
    }
    write(F);
    fclose(F);
    F = fopen(fname, "rb");

    if(F==NULL)
    {
        printf("Error1");
        return -2;
    }

    FILE* G = fopen(gname,"wb");
    if(G==NULL)
    {
        printf("Error2");
        return -3;
    }

    double a;
    printf("a = ");
    scanf("%lf", &a);
    transfer(F,G,a);
    fclose(G);
    fclose(F);
    
    F = fopen(fname, "rb");
    printf("F = ");
    read(F);
    printf("\n");
    printf("G = ");
    G = fopen(gname, "rb");
    read(G);
    printf("\n");
    fclose(F);
    fclose(G);
    F = fopen(fname, "rb");
    exclude(F, a);
    fclose(F);
    rename("file.dat", fname);
    F = fopen(fname, "rb");
    read(F);
    printf("\n");
    fclose(F);
}