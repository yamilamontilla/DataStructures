#include "stdio.h"
#include "ListaContigua.h"
#include "impresionListasContiguas.h"


void main() {

	// Creamos una ListaContigua que nos servirá para las pruebas
	ListaContigua* lista = crearListaContigua();

	printf("Nueva ListaContigua creada:\n");
	imprimirListaContigua(lista);

	printf("Rellenando ListaContigua:\n");
	for (int i = 0; i <= 10; i++) {
		insertarAlFinal(lista, i); // Introducimos el nuevo elemento
		imprimirListaContigua(lista);
	}

	printf("Insertar al principio de 100 a 104\n");
	for (int i = 100; i <= 104; i++) {
		insertar(lista, 0, i);
		imprimirListaContigua(lista);
	}

	printf("Insertamos 200 en la posicion 3:\n");
	insertar(lista, 3, 200);
	imprimirListaContigua(lista);

	printf("Eliminar los 5 ultimos:\n");
	for (int i = 0; i < 5; i++) {
		eliminarAlFinal(lista);
		imprimirListaContigua(lista);
	}

	printf("Eliminar los 5 primeros:\n");
	for (int i = 0; i < 5; i++) {
		eliminar(lista, 0);
		imprimirListaContigua(lista);
	}

	// Buscar elementos
	printf("Elemento 100 encontrado en posicion %d\n", buscar(lista, 100));
	printf("Elemento 2 encontrado en posicion %d\n", buscar(lista, 2));
	printf("Elemento 5 encontrado en posicion %d\n", buscar(lista, 5));
	printf("Elemento 20 encontrado en posicion %d\n", buscar(lista, 20));

	// Creamos una segunda lista, la inicializamos con 500 a 505 y la imprimimos
	printf("Nueva lista2:\n");
	ListaContigua* lista2 = crearListaContigua();
	for (int i = 500; i <= 505; i++) insertarAlFinal(lista2,i);
	imprimirListaContigua(lista2);

	// Concatenamos la lista2 con la primera lista, e imprimimos esta ultima
	printf("Concatenamos la nueva lista a la vieja:\n");
	concatenar(lista, lista2);
	imprimirListaContigua(lista);

	// Destruimos la lista
	destruirListaContigua(lista);
}


