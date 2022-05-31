#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY 100
#define MAX_NAME 30


typedef struct Mount
{
    char name[MAX_NAME];
    int height;
}Mount;


void output_M(const Mount* x)
{
    printf("%s: %d", (char*)(x->name), x->height);
}


int input_M(Mount* x)
{
    printf("Name: ");
    scanf(" ");
    fgets(x->name, MAX_NAME, stdin);
    printf("Height: ");
    scanf("%d",&x->height);
    return 0;
}


void print_H(const Mount* arr, int n, const char* mname)
{
    bool isFound = false;

    for (int i=0;i<n;i++){
        if(strcmp(arr[i].name, mname) == 0){
            printf ("Height of %s is %d", mname, arr[i].height);
            isFound = true;
            break;
        }
    }

    if (!isFound) {
        printf("No mountain with name %s", mname);
    }
}

       
int max_M(const Mount* arr, int n, char* maxMnt)
{

    if (n<=0) return -1;
    int maxHeight = arr[0].height;
    int index = 0;

    for (int i=1; i<n; i++) {
        if (arr[i].height > maxHeight) {
            maxHeight = arr[i].height;
            index = i;
        }
    }
    strcpy(maxMnt, arr[index].name);
    return index;
}



int main(){
    Mount mnts[MAX_ARRAY] = { {"Everest", 8848}, {"Elbrus", 5642}, {"Hoverla", 2700}};
    char mnt[MAX_NAME];
    max_M(mnts, 3, mnt);
    puts(mnt);
}