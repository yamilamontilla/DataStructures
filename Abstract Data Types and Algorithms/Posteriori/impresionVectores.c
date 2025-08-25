#include "assert.h"
#include "stdio.h"
#include "impresionVectores.h"

void escribir(int *vector, int n) {
	assert(vector != NULL);
	// Escribimos solo si el tamano del vector es aceptable para sacarlo por pantalla
	if (n<10)
		for (int i = 0; i<n; i++)
			printf("%d ", vector[i]);
	else printf("Vector demasiado grande para ser mostrado");
}