#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Date
{
    unsigned day;
    unsigned month;
    int year;
};

char mon[13][4] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug" ,"Sep", "Oct", "Nov", "Dec"};
unsigned daymon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int inputDate(struct Date* dd) 
{
    do 
    {
        printf("\nDay:");
        scanf("%u", &(dd->day));
        printf("\nMonth:");
        scanf("%u", &(dd->month));

        if (dd->day>daymon[dd->month]) continue;
        
        printf("\nYear:");
        scanf("%d", &(dd->year));
        
    } while (1);
    return 0;
}

void outputDate (struct Date dd)
{
    printf("%u %s of %d\n",dd.day, mon[dd.month], dd.year);
}

struct Date tomorrow(struct Date dd)
{
    struct Date tom = dd;
    if (dd.day>=daymon[dd.month]) 
    {
        if (dd.month==12) 
        {
            tom.year++;
            tom.month = 1;
            tom.day = 1;
        }
        else
        {
            tom.month++;
            tom.day = 1;
        }
    }
    else
    {
        tom.day++;
    }
    return tom;
}

char* WEEK[] = {"Mon", "Tue", "Wen", "Thu", "Fri", "Sat", "Sun"};

unsigned weekday(struct Date dd)
{
    unsigned d=0;
    d = (dd.year-1970)*365;
    unsigned ly = (dd.year-1968)/4;
    d += ly;
    
    for (unsigned i=1; i<dd.month; i++) 
    {
        d += daymon[i];
    }
    d += dd.day;
    return WEEK[d%7];
}




