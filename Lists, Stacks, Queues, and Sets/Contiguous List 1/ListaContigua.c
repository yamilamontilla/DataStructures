#include "ListaContigua.h"
#include "assert.h"
#include "stdlib.h"

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

void destruirListaContigua(ListaContigua *lista) {
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

int getValor(ListaContigua* lista, int posicion) {
	assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);
	assert(posicion >= 0 && posicion <= lista->n-1);
	return (lista->vector[posicion]);
}

void setValor(ListaContigua* lista, int posicion, int nuevoValor) {
	assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);
	assert(posicion >= 0 && posicion <= lista->n-1);
	lista->vector[posicion] = nuevoValor;
}

void ampliarCapacidad(ListaContigua* lista, int incremento) {
	assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);
	lista->vector = (int*)realloc(lista->vector, sizeof(int) * (lista->capacidad + incremento));
	lista->capacidad += incremento;
}

void insertarAlFinal (ListaContigua* lista, int nuevoValor) {
	assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);

	// Si la ListaContigua está ya llena, antes de insertar ampliamos su capacidad en INCREMENTO
	if (isLlena(lista)) ampliarCapacidad(lista, INCREMENTO);
	
	// Metemos el nuevo elemento. 
	lista->vector[lista->n] = nuevoValor;
	lista->n++;
	
}

void eliminarAlFinal (ListaContigua* lista) {
	assert(lista != NULL);
	assert(lista->n > 0);
	assert(lista->capacidad >= lista->n);

	// Eliminar es simplemente disminuir el numero actual de elementos
	lista->n--;

	// Si la capacidad sobrante es demasiada (2*INCREMENTO), la reducimos en INCREMENTO unidades
	if (lista->capacidad - lista->n >= 2 * INCREMENTO) ampliarCapacidad(lista, -INCREMENTO);
}






