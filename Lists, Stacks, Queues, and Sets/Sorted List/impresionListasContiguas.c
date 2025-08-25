#include "impresionListasContiguas.h"
#include "stdio.h"
#include "assert.h"

void imprimirListaContigua(ListaContigua* lista) {
	assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n); // n y capacidad tienen sentido

	// Imprimimos tamaño y capacidad
	printf("n=%d|Max=%d|ListaContigua=", lista->n, lista->capacidad);

	// Si la ListaContigua está vacía, imprimimos algo especial
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
