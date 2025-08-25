#include "stdio.h"
#include "ListaContigua.h"
#include "impresionListasContiguas.h"


void main() {

	// Creamos una ListaContigua que nos servirá para las pruebas
	ListaContigua *lista = crearListaContigua();

	printf("Nueva ListaContigua creada:\n");
	imprimirListaContigua(lista);

	printf("Rellenando ListaContigua:\n");
	for (int i = 0; i <= 11; i++) {
		insertarAlFinal(lista, i); // Introducimos el nuevo elemento
		imprimirListaContigua(lista);
	}
	printf("Elemento0=%d|Elemento11=%d\n", getValor(lista, 0), getValor(lista, 11));

	printf("Cambio elemento 4 por 50. Nueva ListaContigua:\n");
	setValor(lista, 4, 50);
	imprimirListaContigua(lista);

	// Borramos los ultimos cuatro elementos
	for (int i = 0; i < 4; i++) {
		printf("Borramos el ultimo elemento. Nueva ListaContigua:\n");
		eliminarAlFinal(lista);
		imprimirListaContigua(lista);
	}

	// Insertamos 100, 101, 102 y 103 al final
	for (int i = 100; i <= 103; i++) {
		printf("Insertamos %d al final. Nueva ListaContigua:\n", i);
		insertarAlFinal(lista, i);
		imprimirListaContigua(lista);
	}

	// Destruimos la lista para liberar su memoria
	destruirListaContigua(lista);
}


