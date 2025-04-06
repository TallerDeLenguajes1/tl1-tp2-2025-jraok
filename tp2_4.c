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
    computadora computadoras[MAX], *puntero_pc = computadoras; // Arreglo de computadoras y puntero a la primera computadora
    iniciarComputadoras(puntero_pc); // Llama a la función para inicializar las computadoras
    
    int opcion = 0; // Variable para almacenar la opción del menú
    do
    {
        printf("\n\t\t\tMENU DE FUNCIONES\n");
        printf("\t\t\t-----------------\n");
        printf("\t1. Mostrar todas las computadoras\n");
        printf("\t2. Mostrar la computadora mas vieja\n");
        printf("\t3. Mostrar la computadora mas veloz\n");
        printf("\t4. SALIR\n");
        scanf("%d", &opcion); // Lee la opción del usuario
        switch (opcion)
        {
        case 1:
            listarComputadoras(puntero_pc, MAX); // Llama a la función para listar todas las computadoras
            break;
        
        case 2:
            mostrarMasVieja(puntero_pc, MAX); // Llama a la función para mostrar la computadora mas vieja
            break;
        
        case 3:
            mostrarMasVeloz(puntero_pc, MAX); // Llama a la función para mostrar la computadora mas veloz
            break;

        default:
            break;
        }
        if (opcion == 4) // Si la opción es 4, se sale del menú
        {
            printf("Saliendo del programa...\n");
            liberarMemoria(puntero_pc); // Llama a la función para liberar la memoria asignada
        }
        else if (opcion < 1 || opcion > 4) // Si la opción no es valida, se muestra un mensaje de error
        {
            printf("Opción no valida. Por favor, elija una opción entre 1 y 4.\n");
        }
        printf("\n"); // Salto de línea 
        
    } while (opcion != 4); // Repite el menú hasta que la opción sea 6 (salir)
    

    return 0;
}

void iniciarComputadoras(computadora *computadoras){
    // Inicialización de las computadoras con valores aleatorios
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
        
    for(int i = 0; i < 5; i++){
        int cpu_random = rand() % 6; // Genera un número aleatorio entre 0 y 5 para el tipo de CPU
        computadoras[i].velocidad = rand() % 3 + 1; // Velocidad entre 1 y 3 GHz
        computadoras[i].anio = rand() % 10 + 2015; // Año entre 2015 y 2024
        computadoras[i].cantidad_nucleos = rand() % 8 + 1; // Cantidad de núcleos entre 1 y 8
        computadoras[i].tipo_cpu = (char *)malloc(strlen(tipos[cpu_random])+1); // Reserva memoria para el tipo de CPU contando el null terminator
        if (computadoras[i].tipo_cpu == NULL) { // Verifica si la memoria se asignó correctamente
            fprintf(stderr, "Error al asignar memoria para el tipo de CPU\n");
            exit(1); // Termina el programa si no se pudo asignar memoria
        }
        strcpy(computadoras[i].tipo_cpu, tipos[cpu_random]); // Copia el tipo de CPU a la estructura  
    }
}

void mostrarComputadora(computadora pc)
{
    // Muestra los detalles de una computadora
    printf("Velocidad: %d GHz\n", pc.velocidad);
    printf("Anio: %d\n", pc.anio);
    printf("Cantidad de nucleos: %d\n", pc.cantidad_nucleos);
    printf("Tipo de CPU: %s\n", pc.tipo_cpu);
}

void listarComputadoras(computadora lista[MAX], int cantidad)
{
    // Muestra todas las computadoras en la lista
    for(int i = 0; i < cantidad; i++){
        printf("\tComputadora %d:\n", i + 1);
        printf("\tDetalles:\n");
        printf("\t----------------\n");
        mostrarComputadora(lista[i]);
        printf("\n");
    }
}

void mostrarMasVieja(computadora lista[MAX], int cantidad)
{
    // Muestra la computadora mas vieja
    int anio_mas_viejo = lista[0].anio;
    int indice_mas_viejo = 0;
    
    for(int i = 1; i < cantidad; i++){
        if(lista[i].anio < anio_mas_viejo){
            anio_mas_viejo = lista[i].anio;
            indice_mas_viejo = i;
        }
    }
    
    printf("La computadora mas vieja es:\n");
    mostrarComputadora(lista[indice_mas_viejo]);
    printf("\n");
}

void mostrarMasVeloz(computadora lista[MAX], int cantidad)
{
    // Muestra la computadora mas veloz
    int velocidad_mas_alta = lista[0].velocidad;
    int indice_mas_veloz = 0;
    
    for(int i = 1; i < cantidad; i++){
        if(lista[i].velocidad > velocidad_mas_alta){
            velocidad_mas_alta = lista[i].velocidad;
            indice_mas_veloz = i;
        }
    }
    
    printf("La computadora mas veloz es:\n");
    mostrarComputadora(lista[indice_mas_veloz]);
    printf("\n");
}

void liberarMemoria(computadora *computadoras)
{
    // Libera la memoria asignada para el tipo de CPU de cada computadora
    for(int i = 0; i < MAX; i++){
        free(computadoras[i].tipo_cpu);
    }
}
