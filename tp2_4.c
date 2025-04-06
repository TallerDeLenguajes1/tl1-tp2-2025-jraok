#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 5 //maximo de computadoras

// Definición de la estructura computadora
struct{
    int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio; // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
} typedef computadora;

void iniciarComputadoras(computadora *computadoras); /* funcion que inicializa las computadoras con valores aleatorios */
void mostrarComputadora(computadora pc); /* funcion que muestra una computadora */
void listarComputadoras(computadora lista[MAX], int cantidad); /* funcion que muestra todas las computadoras */
void mostrarMasVieja(computadora lista[MAX], int cantidad); /* funcion que muestra la computadora mas vieja */
void mostrarMasVeloz(computadora lista[MAX], int cantidad); /* funcion que muestra la computadora mas rapida */
void liberarMemoria(computadora *computadoras); /* funcion que libera la memoria de las computadoras */

int main(){
    // Inicialización de la semilla para la generación de números aleatorios
    srand(time(NULL));
    
    return 0;
}
