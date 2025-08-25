#include "Pila.h"
#include "assert.h" // Para "assert()"


void push(ListaEnlazada* lista, int nuevoElemento) {
	assert(lista != NULL);
	assert(lista->n >= 0);
	insertar(lista, 0, nuevoElemento);
}

int pop(ListaEnlazada* lista) {
	assert(lista != NULL);
	assert(!isVacia(lista));

	int resultado = verCima(lista); // Obtenemos la cima
	eliminar(lista, 0); // Eliminamos la cima
	return(resultado);
}

int verCima(ListaEnlazada* lista) {
	assert(lista != NULL);
	assert(!isVacia(lista));
	return(getValor(lista, 0));
}

int isVacia(ListaEnlazada* lista) {
	assert(lista != NULL);
	assert(lista->n >= 0);
	return (lista->n==0);
}


