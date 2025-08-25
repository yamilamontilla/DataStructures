#include "ListaContigua.h"
#include "assert.h"
#include "stdlib.h"
#include "string.h"

// Numero de posiciones en que se incrementa/decrementa la capacidad de la ListaContigua cada vez que es necesario
// Precondición: INCREMENTO >= 1
#define INCREMENTO 2

ListaContigua* crearListaContigua() {
	ListaContigua* lista = (ListaContigua*)malloc(sizeof(ListaContigua));
	lista->vector = NULL; // No hay que reservar memoria ya que la ListaContigua se crea vacía en un principio
	lista->n = 0;
	lista->capacidad = 0;
	return(lista);
}

void destruirListaContigua(ListaContigua* lista) {
	assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n); // n y capacidad tienen sentido
	free(lista->vector); // Liberamos la zona de memoria para guardar los elementos
	free(lista); // Liberamos el struct en si mismo
}

int isLlena(ListaContigua* lista) {
	assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);
	return (lista->n == lista->capacidad);
}

Aeropuerto getValorEnContigua(ListaContigua* lista, int posicion) {
	assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);
	assert(posicion >= 0 && posicion <= lista->n - 1);
	return (lista->vector[posicion]);
}

void setValorEnContigua(ListaContigua* lista, int posicion, Aeropuerto nuevoValor) {
	assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);
	assert(posicion >= 0 && posicion <= lista->n - 1);
	lista->vector[posicion] = nuevoValor;
}

void ampliarCapacidad(ListaContigua* lista, int incremento) {
	assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);
	lista->vector = (Aeropuerto*)realloc(lista->vector, sizeof(Aeropuerto) * (lista->capacidad + incremento));
	lista->capacidad += incremento;
}

void insertarAlFinal(ListaContigua* lista, Aeropuerto nuevoValor) {
	assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);

	insertarEnContigua(lista, lista->n, nuevoValor);
}

void eliminarAlFinal(ListaContigua* lista) {
	assert(lista != NULL);
	assert(lista->n > 0);
	assert(lista->capacidad >= lista->n);

	eliminarEnContigua(lista, lista->n - 1);
}

void insertarEnContigua(ListaContigua *lista, int posicion, Aeropuerto nuevoValor) {
	assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);
	assert(posicion >= 0 && posicion <= lista->n);

	// Si la ListaContigua está ya llena, antes de insertar ampliamos su capacidad en INCREMENTO
	if (isLlena(lista)) ampliarCapacidad(lista, INCREMENTO);

	// Dejamos hueco para el nuevo elemento, desplazando a la derecha los que hay a partir de posicion hasta el final
	memmove(lista->vector+posicion+1, lista->vector+posicion, sizeof(Aeropuerto)*(lista->n - posicion));

	// Metemos el nuevo elemento
	lista->n++;
	setValorEnContigua(lista, posicion, nuevoValor);
}

void eliminarEnContigua(ListaContigua *lista, int posicion) {
	assert(lista != NULL);
	assert(lista->n > 0);
	assert(lista->capacidad >= lista->n);
	assert(posicion >= 0 && posicion <= lista->n-1);

	// Tapamos el hueco dejado por el elemento eliminado. Para ello, desplazamos a la izquierda los
	// elementos que hay a partir de posicion+1 hasta el final
	memmove(lista->vector+posicion, lista->vector+posicion+1, sizeof(Aeropuerto)*(lista->n - posicion - 1));
	lista->n--;

	// Si la capacidad sobrante es demasiada (2*INCREMENTO), la reducimos en INCREMENTO unidades
	if (lista->capacidad - lista->n >= 2 * INCREMENTO) ampliarCapacidad(lista, -INCREMENTO);
}

void concatenarContiguas(ListaContigua* listaDestino, const ListaContigua* listaOrigen) {
	assert(listaDestino != NULL && listaOrigen != NULL);
	assert(listaDestino->n >= 0 && listaOrigen->n >= 0); // El tamaño de ambas listas tiene sentido
	assert(listaDestino->capacidad >= listaDestino->n); // La capacidad de la listaDestino tiene sentido
	assert(listaOrigen->capacidad >= listaOrigen->n); // La capacidad de la listaOrigen tiene sentido
	
	// Tamaño de la lista a concatenar. Por convención, cuando tenemos
	// dos listas, el tamaño de una es "n" y el de la otra es "m"
	int n = listaDestino->n;
	int m = listaOrigen->n; 
	
	// Primero vamos a ampliar la capacidad para asegurarnos de que los
	// nuevos elementos quepan. Para ello, ampliamos la 
	// capacidad de la lista destino en m (tamaño de la lista origen)
	// Complejidad temporal O(n) 
	ampliarCapacidad(listaDestino, m);

	// Vamos insertando al final elemento a elemento. Fíjate en que insertar un elemento al final
	// es O(1) si no tenemos que ampliar la capacidad (la cual ya está ampliada)
	// Complejidad temporal O(m)
	for (int i = 0; i < m; i++) {
		insertarAlFinal(listaDestino, getValorEnContigua(listaOrigen, i));
	}
}

int buscarEnContigua(ListaContigua* lista, Aeropuerto elementoABuscar) {
	assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n); // n y capacidad tienen sentido

	int posicion = 0; // Posición actual en donde buscamos
	int encontrado = 0; // Booleano que nos indica si hemos encontrado o no el elemento

	// Buscamos el elemento hasta que lo encontremos o hasta que lleguemos al final
	while (!encontrado && posicion < lista->n) {
		if (strcmp(lista->vector[posicion].nombre, elementoABuscar.nombre) == 0) encontrado = 1;
		posicion++;
	}

	// Devolvemos la posición si lo hemos encontrado, o -1 en caso contrario
	if (encontrado) return (posicion - 1);
	else return (-1);
}





