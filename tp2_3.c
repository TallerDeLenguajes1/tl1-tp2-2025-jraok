// librerias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// columnas y filas para la matriz
#define N 5
#define M 7

// funcion principal
int main(){
    // semilla para el generador de numeros aleatorios
    srand(time(NULL));
    // matriz y puntero de enteros
    int mt[N][M], *puntero = &mt[0][0];
    // recorrido de la matriz con puntero
    printf("Recorrido de la matriz con puntero:\n");
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < M ; j++)
        {
            // asignacion de valores aleatorios entre 1 y 100
            *(puntero + i * M + j) = 1 + rand() % 100; /* primero me situo en la ubicacion del puntero (el inicio), me muevo a la posicion de la fila y luego a la columna, por ultimo asigno el valor */
            printf("%d\t", *(puntero + i * M + j));
        }
        printf("\n");
    }

    return 0;

}
