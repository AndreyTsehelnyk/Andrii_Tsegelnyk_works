#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ChessField
{
    char h;
    unsigned char v;
};

int inputChessField(struct ChessField * cf) 
{
    printf("\nH:");
    scanf("%c", &(cf->h));
    printf("V:");
    scanf("%hhu",&(cf->v));
    if(cf->v>8 || cf->v==0) return 1;
    if(cf->h<'a' || cf->h>'h') return 2;
    return 0;
}

void outputChessField(struct ChessField cf)
{
    printf("%c%hhu:",cf.h, cf.v);
}


int main()
{
    struct ChessField w1, w2;
    if (inputChessField(&w1)) 
    {
        outputChessField(w1);
    };
    if (inputChessField(&w2))
    {
        outputChessField(w2);
    };
}