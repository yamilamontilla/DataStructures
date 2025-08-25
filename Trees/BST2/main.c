#include "stdio.h"
#include "ArbolBinarioDeBusqueda.h"


void main() {

	ArbolBinarioDeBusqueda* arbol = construirArbolBinarioDeBusqueda();

	// Creamos la lista de inserciones
	int inserciones[] = { 5, 1, 6, 3, 7, 2, 4 };
	const int n = 7;

	// Insertamos e imprimimos
	for (int i = 0; i < n; i++) insertar(arbol, inserciones[i]);
	printf("Arbol inicial:\n");
	imprimir(arbol);

	printf("Eliminamos 5\n");
	eliminar(arbol, 5);
	imprimir(arbol);

	printf("Eliminamos 6\n");
	eliminar(arbol, 6);
	imprimir(arbol);

	printf("Eliminamos 4\n");
	eliminar(arbol, 4);
	imprimir(arbol);

	printf("Eliminamos 7\n");
	eliminar(arbol, 7);
	imprimir(arbol);

	destruirArbolBinarioDeBusqueda(arbol);
}
