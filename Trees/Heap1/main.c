#include "stdio.h"
#include "Monticulo.h"


void main () {

	// Creamos el monticulo vacio
	ListaContigua* monticulo = crearListaContigua();

	// Creamos la lista de inserciones
	int inserciones[] = {3, 4, 6, 7, 5, 2};

	// Vamos insertando e imprimiendo
	for (int i=0; i<6; i++) {
		printf("Insercion de %d:\n", inserciones[i]);
		insertarEnMonticulo(monticulo, inserciones[i]);
		imprimir(monticulo);
	}

	destruirListaContigua(monticulo);	
}

