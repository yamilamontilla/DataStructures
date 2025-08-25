#include "assert.h"
#include "ordenacionQuickSort.h"

int compararEnteros(const void *punteroAOperando1, const void *punteroAOperando2) {
	assert(punteroAOperando1 != NULL && punteroAOperando2 != NULL);

	// Convertimos los punteros gen�ricos pasados como par�metros en punteros a enteros
	int *puntero1 = (int*)punteroAOperando1;
	int *puntero2 = (int*)punteroAOperando2;

	// Extraemos los valores apuntados por los punteros
	int operando1 = *puntero1;
	int operando2 = *puntero2;

	// Devolvemos la resta de ambos valores
	return (operando1 - operando2);
}