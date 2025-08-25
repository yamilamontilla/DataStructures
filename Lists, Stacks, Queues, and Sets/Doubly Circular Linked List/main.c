#include "stdio.h"
#include "ListaEnlazada.h"
#include "impresionListasEnlazadas.h"


void main () {

	// Creamos una lista que nos servirá para las pruebas
	ListaEnlazada* lista = construirListaEnlazada();
	printf("Nueva ListaEnlazada creada:\n");
	imprimirListaEnlazada(lista);

	// Prueba de insercion en lista vacia
	printf("Inserto 10 con la lista vacia:\n");
	insertar(lista, 0, 10);
	imprimirListaEnlazada(lista);

	// Prueba de insercion al final
	printf("Inserto 20 y 21 al final:\n");
	for (int i = 20; i <= 21; i++) {
		insertar(lista, lista->n, i); // Insertamos al final
		imprimirListaEnlazada(lista);
	}

	// Prueba de insercion al principio
	printf("Inserto 30 al principio:\n");
	insertar(lista, 0, 30);
	imprimirListaEnlazada(lista);

	// Prueba de insercion en medio
	printf("Inserto 40 en la posicion 2:\n");
	insertar(lista, 2, 40);
	imprimirListaEnlazada(lista);

	// Prueba de eliminacion al principio
	printf("Elimino el primer elemento:\n");
	eliminar(lista, 0);
	imprimirListaEnlazada(lista);

	// Prueba de eliminación del final
	printf("Elimino el ultimo elemento:\n");
	eliminar(lista, lista->n - 1);
	imprimirListaEnlazada(lista);

	// Prueba de eliminación del medio
	printf("Elimino el elemento del medio:\n");
	eliminar(lista, 1);
	imprimirListaEnlazada(lista);

	// Prueba de eliminacion hasta dejar la lista vacia
	printf("Elimino el 20 y el 10 para dejar la lista vacia:\n");
	eliminar(lista, 1); imprimirListaEnlazada(lista);
	eliminar(lista, 0); imprimirListaEnlazada(lista);

	// Vuelvo a repetir las inserciones del principio,
	// para comprobar que realmente las eliminaciones lo han hecho bien
	// y no han dejado inconsistente a la lista
	printf("Vuelvo a repetir las inserciones del principio:\n");

	// Prueba de insercion en lista vacia
	printf("Inserto 10 con la lista vacia:\n");
	insertar(lista, 0, 10);
	imprimirListaEnlazada(lista);

	// Prueba de insercion al final
	printf("Inserto 20 y 21 al final:\n");
	for (int i = 20; i <= 21; i++) {
		insertar(lista, lista->n, i); // Insertamos al final
		imprimirListaEnlazada(lista);
	}

	// Prueba de insercion al principio
	printf("Inserto 30 al principio:\n");
	insertar(lista, 0, 30);
	imprimirListaEnlazada(lista);

	// Prueba de insercion en medio
	printf("Inserto 40 en la posicion 2:\n");
	insertar(lista, 2, 40);
	imprimirListaEnlazada(lista);

	// Insertamos otros dos para hacer mejores pruebas luego
	printf("Insertamos 50 y 60 al final:\n");
	insertar(lista, 5, 50);
	insertar(lista, 6, 60);
	imprimirListaEnlazada(lista);

	// Ver elementos
	printf("Elemento 0 es %d\n", getValor(lista, 0));
	printf("Elemento 4 es %d\n", getValor(lista, 4));
	printf("Elemento 2 es %d\n", getValor(lista, 2));
	printf("Elemento 6 es %d\n", getValor(lista, 6));

	// Modificar elementos
	printf("Cambio elementos 0, 4, 2 y 6 por sus inversos. El resultado es:\n");
	setValor(lista, 0, -30);
	setValor(lista, 4, -21);
	setValor(lista, 2, -40);
	setValor(lista, 6, -60);
	imprimirListaEnlazada(lista);

	// Buscar elementos
	printf("Elemento -30 encontrado en posicion %d\n", buscar(lista, -30));
	printf("Elemento 20 encontrado en posicion %d\n", buscar(lista, 20));
	printf("Elemento -60 encontrado en posicion %d\n", buscar(lista, -60));
	printf("Elemento 100 encontrado en posicion %d\n", buscar(lista, 100));

	// Creamos una segunda lista, la inicializamos con 500 a 505 y la imprimimos
	printf("Nueva lista2:\n");
	ListaEnlazada* lista2 = construirListaEnlazada();
	for (int i = 0; i <= 5; i++) insertar(lista2, i, i+500);
	imprimirListaEnlazada(lista2);

	// Concatenamos la lista2 con la primera lista, e imprimimos esta ultima
	printf("Concatenamos la nueva lista a la vieja:\n");
	concatenar(lista, lista2);
	imprimirListaEnlazada(lista);

	// Destruimos las listas
	destruirListaEnlazada(lista);
	destruirListaEnlazada(lista2);
}


