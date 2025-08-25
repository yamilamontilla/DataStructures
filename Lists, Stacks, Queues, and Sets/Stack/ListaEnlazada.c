#include "ListaEnlazada.h"
#include "assert.h"
#include "stdlib.h"


Nodo* getNodo(ListaEnlazada* lista, int posicion) {
	assert(lista != NULL);
	assert(lista->n > 0);
	assert(posicion >= 0 && posicion <= lista->n - 1);

	Nodo* resultado = NULL; // Aquí guardaremos el puntero al nodo resultado 

	// Si el nodo que queremos buscar es igual que el último accedido
	if (posicion == lista->posicionUltimoNodoAccedido && lista->posicionUltimoNodoAccedido != -1)
		resultado = lista->punteroUltimoNodoAccedido;

	// Si el nodo que queremos buscar es el siguiente al último accedido
	else if (posicion == lista->posicionUltimoNodoAccedido + 1 && lista->posicionUltimoNodoAccedido != -1) {
		resultado = lista->punteroUltimoNodoAccedido->siguienteNodo;
	}

	// Si el nodo que queremos buscar es el anterior al último accedido
	else if (posicion == lista->posicionUltimoNodoAccedido - 1 && lista->posicionUltimoNodoAccedido != -1) {
		resultado = lista->punteroUltimoNodoAccedido->anteriorNodo;
	}

	// Si el nodo no es contiguo al ultimo accedido, y se llega antes a él iterando hacia delante	
	else if (posicion <= lista->n / 2) {
		resultado = lista->punteroPrimerNodo; // Hacemos que el resultado apunte al primer nodo
		for (int i = 0; i < posicion; i++) resultado = resultado->siguienteNodo;
	}

	// Si el nodo no es contiguo al ultimo accedido, y se llega antes a él iterando hacia atrás	
	else {
		resultado = lista->punteroPrimerNodo->anteriorNodo; // Hacemos que el resultado apunte al último nodo
		for (int i = lista->n - 1; i > posicion; i--)
			resultado = resultado->anteriorNodo;
	}

	// Actualizamos los atributos del ultimo nodo accedido
	lista->posicionUltimoNodoAccedido = posicion;
	lista->punteroUltimoNodoAccedido = resultado;

	return (resultado);
}


ListaEnlazada* construirListaEnlazada() {
	ListaEnlazada* lista = (ListaEnlazada*)malloc(sizeof(ListaEnlazada));
	lista->punteroPrimerNodo = NULL;
	lista->n = 0;
	lista->posicionUltimoNodoAccedido = -1; // -1 significa que no se ha accedido aun a ninguno
	lista->punteroUltimoNodoAccedido = NULL; // NULL significa que no se ha accedido aun a ninguno
	return(lista);
}


int getValor(ListaEnlazada* lista, int posicion) {
	assert(lista != NULL);
	assert(lista->n > 0);
	assert(posicion >= 0 && posicion <= lista->n - 1);

	// Obtenemos el nodo que contiene el elemento
	Nodo* nodoQueContieneResultado = getNodo(lista, posicion);
	return (nodoQueContieneResultado->elemento);
}


void setValor(ListaEnlazada* lista, int posicion, int nuevoValor) {
	assert(lista != NULL);
	assert(lista->n > 0);
	assert(posicion >= 0 && posicion <= lista->n - 1);
	getNodo(lista, posicion)->elemento = nuevoValor;
}


void insertar(ListaEnlazada* lista, int posicion, int nuevoValor) {
	assert(lista != NULL & lista->n >= 0); // La lista existe y su tamaño tiene sentido
	assert(posicion >= 0 && posicion <= lista->n);

	// Creamos el nuevo nodo con el nuevo valor
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->elemento = nuevoValor;

	// Si la lista estaba vacia...
	if (lista->n == 0) {
		nuevoNodo->siguienteNodo = nuevoNodo;
		nuevoNodo->anteriorNodo = nuevoNodo;
	}

	// Si la lista no está vacía
	else {
		// Primero obtenemos el nodo que está a continuación del que queremos insertar
		// Nota que, si queremos insertar al final, su siguiente es el primero
		Nodo* nodoSiguiente; // Nodo a continuación del que queremos insertar
		if (posicion == lista->n) nodoSiguiente = lista->punteroPrimerNodo;
		else nodoSiguiente = getNodo(lista, posicion);

		// Obtenemos el nodo anterior al que queremos insertar
		// Tengamos cuidado en hacerlo en O(1)
		Nodo* nodoAnterior = nodoSiguiente->anteriorNodo;

		// Actualizamos los punteros del nuevo nodo
		nuevoNodo->anteriorNodo = nodoAnterior;
		nuevoNodo->siguienteNodo = nodoSiguiente;

		// Actualizamos los punteros de los dos nodos que rodean al nuevo nodo
		// El puntero siguiente del anterior y el puntero anterior del siguiente apuntarán ambos al nuevo nodo
		nodoSiguiente->anteriorNodo = nuevoNodo;
		nodoAnterior->siguienteNodo = nuevoNodo;
	} // Fin else

	// Si estamos insertando al principio de la lista, hay que modificar el puntero a la lista
	if (posicion == 0) lista->punteroPrimerNodo = nuevoNodo;

	// Incrementamos el numero de elementos
	lista->n++;

	// Como hemos cambiado la configuracion de la lista, reseteamos el ultimo nodo accedido
	lista->posicionUltimoNodoAccedido = -1; // -1 significa que no se ha accedido aun a ninguno
	lista->punteroUltimoNodoAccedido = NULL; // NULL significa que no se ha accedido aun a ninguno
}


void eliminar(ListaEnlazada* lista, int posicion) {
	assert(lista != NULL);
	assert(lista->n > 0);
	assert(posicion >= 0 && posicion <= lista->n - 1);

	// Obtenemos el nodo que queremos eliminar
	Nodo* nodoAEliminar = getNodo(lista, posicion);

	// Si la lista sólo tiene un elemento, actualizamos el atributo punteroPrimerNodo pues la lista se queda vacia
	if (lista->n == 1) lista->punteroPrimerNodo = NULL;

	// Si la lista tiene más de un elemento, hacemos el caso general
	else {

		// Obtenemos los dos nodos que le rodean
		Nodo* nodoAnterior = nodoAEliminar->anteriorNodo;
		Nodo* nodoSiguiente = nodoAEliminar->siguienteNodo;

		// Modificamos los punteros de cada uno de los dos nodos que rodean al que queremos eliminar
		nodoAnterior->siguienteNodo = nodoSiguiente;
		nodoSiguiente->anteriorNodo = nodoAnterior;

		// Si el nodo a eliminar era el 0, tenemos que actualizar el atributo punteroPrimerNodo
		if (posicion == 0) lista->punteroPrimerNodo = nodoSiguiente;
	} // Fin else

	// Liberamos la memoria del nodo
	free(nodoAEliminar);

	// Actualizamos n
	lista->n--;

	// Como hemos cambiado la configuracion de la lista, reseteamos el ultimo nodo accedido
	lista->posicionUltimoNodoAccedido = -1; // -1 significa que no se ha accedido aun a ninguno
	lista->punteroUltimoNodoAccedido = NULL; // NULL significa que no se ha accedido aun a ninguno
}


void concatenar(ListaEnlazada* listaDestino, ListaEnlazada* listaOrigen) {
	assert(listaDestino != NULL && listaOrigen != NULL); // Ambas listas existen
	assert(listaDestino->n >= 0 && listaOrigen->n >= 0); // El tamaño de ambas listas tiene sentido

	// Tamaño de la lista origen. Por convención, cuando tenemos
	// dos listas, el tamaño de una es "n" y el de la otra es "m"
	int m = listaOrigen->n;

	// Vamos insertando al final elemento a elemento. Fíjate en que insertar un elemento al final
	// es O(1) porque la lista es circular, y por lo tanto podemos acceder al ultimo nodo en O(1)
	// si hemos hecho bien getNodo()
	// Complejidad temporal O(m). Las sucesivas llamadas a getValor(listaOrigen, i) son O(1),
	// porque getNodo() recuerda el último nodo accedido.
	// OJO: no podemos enlazar simplemente el último elemento de listaDestino con el primero de
	// listaOrigen porque entonces destruiríamos la listaOrigen (la dejaríamos inconsistente).
	for (int i = 0; i < m; i++) {
		int elementoACopiar = getValor(listaOrigen, i);
		insertar(listaDestino, listaDestino->n, elementoACopiar);
	}
}


int buscar(ListaEnlazada* lista, int elementoABuscar) {
	assert(lista != NULL && lista->n >= 0); // Lista existe y su tamaño tiene sentido

	int posicion = 0; // Posición actual en donde buscamos
	int encontrado = 0; // Booleano que nos indica si hemos encontrado o no el elemento

	// Buscamos el elemento hasta que lo encontremos o hasta que lleguemos al final
	while (!encontrado && posicion < lista->n) {
		// Cada llamada a getValor() es O(1) porque getNodo() recuerda el último nodo accedido
		if (getValor(lista, posicion) == elementoABuscar) encontrado = 1;
		posicion++;
	}

	// Devolvemos la posición si lo hemos encontrado, o -1 en caso contrario
	if (encontrado) return (posicion - 1);
	else return (-1);
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

