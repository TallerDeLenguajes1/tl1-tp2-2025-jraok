#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int main(){
    srand(time(NULL));
    // codigo a completar
    double vt[N];
    // recorrido del arrglo con notacion indexada
    for(int i = 0;i<N; i++){
        vt[i]=1+rand()%100;
        printf("\t%.2f", *(vt+i));
    }
    
    return 0;
}