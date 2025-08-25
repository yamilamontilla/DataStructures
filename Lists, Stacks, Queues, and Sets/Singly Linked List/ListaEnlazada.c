#include "ListaEnlazada.h"
#include "assert.h"
#include "stdlib.h"


Nodo* getNodo(ListaEnlazada* lista, int posicion) {
	assert(lista != NULL);
	assert(lista->n > 0);
	assert(posicion >= 0 && posicion <= lista->n-1);

	Nodo *resultado = NULL; // Aquí guardaremos el puntero al nodo resultado 
	
	// Recorremos la lista hasta la posición correcta
	resultado = lista->punteroPrimerNodo; // Hacemos que el resultado apunte al primer nodo
	for (int i=0; i<posicion; i++) 
		resultado = resultado->siguienteNodo;

	return (resultado);
}


ListaEnlazada* construirListaEnlazada() {
	ListaEnlazada* lista = (ListaEnlazada*)malloc(sizeof(ListaEnlazada));
	lista->punteroPrimerNodo = NULL;
	lista->n=0;
	return(lista);
}


int getValor(ListaEnlazada* lista, int posicion) {
	assert(lista != NULL);
	assert(lista->n > 0);
	assert(posicion >= 0 && posicion <= lista->n-1); 
	
	// Obtenemos el nodo que contiene el elemento
	Nodo *nodoQueContieneResultado = getNodo (lista, posicion);
	return (nodoQueContieneResultado->elemento);
}


void setValor(ListaEnlazada* lista, int posicion, int nuevoValor) {
	assert(lista != NULL);
	assert(lista->n > 0);
	assert (posicion >= 0 && posicion <= lista->n-1); 
	getNodo(lista, posicion)->elemento = nuevoValor;
}


void insertar(ListaEnlazada* lista, int posicion, int nuevoValor) {
	assert(lista != NULL && lista->n >= 0); // La lista existe y su tamaño tiene sentido
	assert(posicion >= 0 && posicion <= lista->n); 

	// Creamos el nuevo nodo con el nuevo valor
	Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->elemento = nuevoValor;

	// Si la lista estaba vacia...
	if (lista->n==0) {
		lista->punteroPrimerNodo = nuevoNodo;
		nuevoNodo->siguienteNodo = NULL;
	}

	// Si la lista no está vacía, distinguimos dos casos
	else {
		
		// Si estamos insertando al principio, el siguiente del insertado
		// es el que antes era el primero (apuntado por "punteroPrimerNodo")
		if (posicion == 0) {
			nuevoNodo->siguienteNodo = lista->punteroPrimerNodo;
			lista->punteroPrimerNodo = nuevoNodo;
		}

		// En cualquier otro caso, hay un nodo anterior y otro posterior 
		// (puede que el posterior sea NULL si estamos insertando al final)
		else {
			// Obtenemos los nodos anterior y siguiente al que queremos insertar
			Nodo *anterior = getNodo(lista, posicion - 1); // Nodo que estará antes del que queremos insertar
			Nodo *siguiente = anterior->siguienteNodo; // Nodo que estará después del que queremos insertar

			// Hacemos que cada uno apunte al lugar adecuado
			anterior->siguienteNodo = nuevoNodo;
			nuevoNodo->siguienteNodo = siguiente;
		}

	} // Fin else

	// Incrementamos el numero de elementos
	lista->n++;
}


void eliminar(ListaEnlazada* lista, int posicion) {
	assert(lista != NULL);
	assert(lista->n > 0);
	assert(posicion >= 0 && posicion <= lista->n-1); 

	Nodo *nodoAEliminar = NULL; // Puntero al nodo que queremos eliminar

	// Si el nodo que queremos eliminar es el primero
	if (posicion == 0) {
		nodoAEliminar = lista->punteroPrimerNodo;
		Nodo *nodoSiguiente = nodoAEliminar->siguienteNodo; // Obtenemos el siguiente, o NULL si no lo hay
		lista->punteroPrimerNodo = nodoSiguiente; // Apuntamos al que antes era el segundo nodo, o NULL si solo había un nodo en la lista
	}

	// Si el nodo que queremos eliminar no es el primero
	// Nota que en este caso n>=2 pues si fuera n==1 ya se hubiera ejecutado el anterior caso
	// Nota también que este caso incluye el hecho de que el nodo a eliminar pueda ser el último
	else {
		Nodo *nodoAnterior = getNodo(lista, posicion-1); // Nodo anterior al que queremos eliminar
		nodoAEliminar = nodoAnterior->siguienteNodo; // Nodo que queremos eliminar
		Nodo *nodoSiguiente = nodoAEliminar->siguienteNodo; // Nodo siguiente al que queremos eliminar
		nodoAnterior->siguienteNodo = nodoSiguiente; // Hacemos que el anterior apunte al siguiente
	}

	// Liberamos la memoria del nodo
	free(nodoAEliminar);

	// Actualizamos n
	lista->n--;
}


void destruirListaEnlazada(ListaEnlazada* lista) {
	assert(lista != NULL && lista->n >= 0); // La lista existe y su tamaño tiene sentido

	// Eliminamos todos los nodos. Para ello, eliminamos el primer elemento de la lista
	// repetidamente, hasta que ya no haya elementos.
	// Eliminar el primer elemento de la lista es O(1)
	while (lista->n > 0) eliminar(lista, 0);

	// Eliminamos la lista en sí misma
	free(lista);
}



