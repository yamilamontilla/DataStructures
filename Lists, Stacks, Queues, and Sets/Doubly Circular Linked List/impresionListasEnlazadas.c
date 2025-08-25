#include "impresionListasEnlazadas.h"
#include "assert.h"
#include "stdio.h"
#include "stdlib.h"


void imprimirListaEnlazada(ListaEnlazada* lista) {
	assert(lista != NULL);
	assert(lista->n >= 0);

	// Imprimimos tamaño
	printf("n=%d|ListaEnlazada=", lista->n);

	// Si la lista está vacía, imprimimos algo especial
	if (lista->n == 0) printf("vacia");

	// Si no está vacía, imprimimos los elementos separados por comas, siempre que no sea demasiado grande
	// Si es demasiado grande, imprimimos un mensaje especial
	else {
		if (lista->n > 20) printf("demasiadosElementosParaMostrar");
		else {
			for (int i = 0; i < lista->n; i++) {
				printf("%d", getValor(lista, i));
				if (i < lista->n - 1) printf(","); // Imprimimos "," si no estamos al final
			}
		}
	}
	printf("\n");
}
