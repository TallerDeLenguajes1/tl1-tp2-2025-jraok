#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int main()
{
    srand(time(NULL));
    double vt[N], *puntero = &vt[0];
    for(int i = 0;i<N; i++)
    {
        vt[i]= 1 + rand()%100;
        printf("%.2f ", *(puntero + i));
    }
    return 0;
}