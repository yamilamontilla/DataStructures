#include "stdio.h"
#include "ArbolBinarioDeBusqueda.h"


void main () {

	ArbolBinarioDeBusqueda *arbol = construirArbolBinarioDeBusqueda();

	// Creamos la lista de inserciones
	int inserciones[] = {5, 1, 6, 3, 7, 2, 4};
	const int n = 7;

	// Vamos insertando e imprimiendo
	for (int i=0; i<n; i++) {
		printf("Insercion de %d:\n", inserciones[i]);
		insertar(arbol, inserciones[i]);
		imprimir(arbol);
	}

	// Ahora vamos a buscar todos los que hemos insertado, en orden directo
	printf("Buscamos todos en orden directo:\n");
	for (int i = 0; i < n; i++) {
		printf("Buscamos %d: ", inserciones[i]);
		if (buscar(arbol, inserciones[i])) printf("ENCONTRADO");
		else printf("NO ENCONTRADO");
		printf("\n");
	}

	// Ahora vamos a buscar todos los que hemos insertado, en orden inverso
	printf("Buscamos todos en orden inverso:\n");
	for (int i = n-1; i >= 0; i--) {
		printf("Buscamos %d: ", inserciones[i]);
		if (buscar(arbol, inserciones[i])) printf("ENCONTRADO");
		else printf("NO ENCONTRADO");
		printf("\n");
	}

	destruirArbolBinarioDeBusqueda(arbol);
}
