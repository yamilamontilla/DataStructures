// Bibliotecas nuestras
#include "impresionVectores.h" // Funciones nuestras para imprimir vectores
#include "ordenacionQuickSort.h" // Funciones nuestras para ordenar por QuickSort
#include "ordenacionSeleccion.h" // Funciones nuestras para imprimir por Seleccion

// Bibliotecas est�ndar
#include "stdio.h"
#include "time.h" // Para usar "time()" y "clock()"
#include "stdlib.h" // Para usar "srand()" y "qsort()"
#include "assert.h"

void main() {

	int n; // Tama�o del vector

	// Inicializamos el generador de numeros aleatorios con el numero de segundos transcurrido desde 1970
	srand(time(NULL));

	// Pedimos el tama�o del vector
	printf("Introduce el tamano del vector (numero mayor o igual que 1): ");
	scanf("%d", &n);

	// Creamos el vector y lo rellenamos con n�meros aleatorios
	int *vectorSinOrdenar = (int*)malloc(n*sizeof(int));
	for (int i = 0; i<n; i++) vectorSinOrdenar[i] = rand();

	// Copiamos el vector en otros dos vectores, cada uno de ellos para ordenarlo con un m�todo
	int *vectorParaSeleccion = (int*)malloc(n*sizeof(int)); // Origen y resultado del algoritmo de selecci�n
	int *vectorParaQuickSort = (int*)malloc(n*sizeof(int)); // Origen y resultado del algoritmo QuickSort
	memcpy(vectorParaSeleccion, vectorSinOrdenar, sizeof(int)*n);
	memcpy(vectorParaQuickSort, vectorSinOrdenar, sizeof(int)*n);

	// Imprimimos el vector original
	printf("\nEl vector original es el siguiente:\n");
	escribir(vectorSinOrdenar, n);
	printf("\n\n");

	// Lo ordenamos por seleccion
	unsigned long int numeroClicksInicio = clock();
	printf("Clocks de inicio con ordenacion por seleccion: %d\n", numeroClicksInicio);
	ordenarPorSeleccion(vectorParaSeleccion, n);
	unsigned long int numeroClicksFin = clock();
	printf("Clocks de fin con ordenacion por seleccion:    %d\n", numeroClicksFin);
	printf("CLOCK_PER_SEC:                                 %d\n", CLOCKS_PER_SEC);

	// Calculamos el tiempo que ha llevado la ordenaci�n
	// Hacemos el divisor float para que la divisi�n sea real y no entera
	// La cte CLOKS_PER_SEC (en ctime) nos dice el numero de clocks por segundo
	float segundosTranscurridos = (numeroClicksFin - numeroClicksInicio) / (float)CLOCKS_PER_SEC; 

	// Imprimimos el tiempo transcurrido con tres decimales
	printf ("Con ordenacion por seleccion he tardado %.3f segundos en ordenarlo.\nEl vector resultado es:\n", segundosTranscurridos);
	escribir(vectorParaSeleccion, n);
	printf("\n\n");

	// Lo ordenamos por QuickSort
	numeroClicksInicio = clock();
	printf("Clocks de inicio con ordenacion por QuickSort: %d\n", numeroClicksInicio);
	qsort(vectorParaQuickSort, n, sizeof(int), compararEnteros);
	numeroClicksFin = clock();
	printf("Clocks de fin con ordenacion por QuickSort:    %d\n", numeroClicksFin);
	printf("CLOCK_PER_SEC:                                 %d\n", CLOCKS_PER_SEC);

	// Calculamos el tiempo que ha llevado la ordenaci�n
	// Hacemos el divisor float para que la divisi�n sea real y no entera
	// La cte CLOKS_PER_SEC (en ctime) nos dice el numero de clocks por segundo
	segundosTranscurridos = (numeroClicksFin - numeroClicksInicio) / (float)CLOCKS_PER_SEC;

	// Imprimimos el tiempo transcurrido con tres decimales
	printf ("Con ordenacion por QuickSort he tardado %.3f segundos en ordenarlo.\nEl vector resultado es:\n", segundosTranscurridos);
	escribir(vectorParaQuickSort, n);
	printf("\n\n");

}


