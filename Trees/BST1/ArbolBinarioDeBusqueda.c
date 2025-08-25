#include "ArbolBinarioDeBusqueda.h"
#include "assert.h"
#include "stdio.h"
#include "stdlib.h"


ArbolBinarioDeBusqueda* construirArbolBinarioDeBusqueda() {
	ArbolBinarioDeBusqueda* arbol = (ArbolBinarioDeBusqueda*)malloc(sizeof(ArbolBinarioDeBusqueda));
	arbol->n = 0;
	arbol->raiz = NULL;
	return(arbol);
}


Nodo* buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar) {
	assert(raizSubarbol != NULL);

	// Elemento encontrado en la raíz
	if (raizSubarbol->contenido == elementoABuscar)
		return (raizSubarbol);

	// El elemento que se busca es menor que la raíz
	else if (elementoABuscar < raizSubarbol->contenido) {
		if (raizSubarbol->hijoIzquierdo == NULL) return (raizSubarbol); // El elemento no está. Devolvemos su padre
		else return (buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar)); // Seguimos buscando por la izquierda
	}

	// El elemento que se busca es mayor que la raíz
	else {
		if (raizSubarbol->hijoDerecho == NULL) return (raizSubarbol); // El elemento no está. Devolvemos su padre
		else return (buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar)); // Seguimos buscando por la derecha
	}
}


int buscar(ArbolBinarioDeBusqueda* arbol, int elementoABuscar) {
	assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	if (arbol->n == 0) return(0);
	else {
		Nodo* nodo = buscarRecursivo(arbol->raiz, elementoABuscar);
		if (nodo->contenido == elementoABuscar) return(1);
		else return (0);
	}
}


void insertar(ArbolBinarioDeBusqueda* arbol, int nuevoElemento) {
	assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	assert(!buscar(arbol, nuevoElemento)); // El nuevo elemento no estaba ya en el árbol

	// Creamos el nuevo nodo que contiene al elemento
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->contenido = nuevoElemento;
	nuevoNodo->padre = NULL;
	nuevoNodo->hijoIzquierdo = NULL;
	nuevoNodo->hijoDerecho = NULL;

	// Si el arbol está vacío, lo metemos en la raiz sí o sí
	if (arbol->n == 0) {
		arbol->raiz = nuevoNodo;
	}

	// En caso contrario, buscamos el hueco en donde meterlo como una hoja
	else {
		// Buscamos el hueco
		Nodo *padreDelHueco = buscarRecursivo(arbol->raiz, nuevoElemento); // Puntero al nodo que es el padre del hueco

		// Metemos el nuevo nodo como hijo izquierdo o derecho
		if (nuevoElemento < padreDelHueco->contenido) padreDelHueco->hijoIzquierdo = nuevoNodo;
		else padreDelHueco->hijoDerecho = nuevoNodo;

		// Hacemos que el nuevo nodo apunte al padre
		nuevoNodo->padre = padreDelHueco;
	}

	// Incrementamos el número de nodos
	arbol->n++;
}


void imprimirRecursivo(Nodo* raizSubarbol, int numeroTabulaciones, int orientacion) {
	assert(raizSubarbol != NULL);
	assert(numeroTabulaciones >= 0);
	assert(orientacion == 1 || orientacion == -1 || orientacion == 0);

	// Imprimimos el nodo raiz con el nivel pasado como parametro
	for (int i = 0; i < numeroTabulaciones; i++) printf("\t");
	printf("%d", raizSubarbol->contenido);
	if (orientacion == -1) printf(" (izquierdo)");
	if (orientacion == 1) printf(" (derecho)");
	printf("\n");

	// Imprimimos sus hijos con una tabulacion mas
	if (raizSubarbol->hijoIzquierdo != NULL) imprimirRecursivo(raizSubarbol->hijoIzquierdo, numeroTabulaciones + 1, -1);
	if (raizSubarbol->hijoDerecho != NULL) imprimirRecursivo(raizSubarbol->hijoDerecho, numeroTabulaciones + 1, 1);
}


void imprimir(ArbolBinarioDeBusqueda* arbol) {
	assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	if (arbol->n > 0) imprimirRecursivo(arbol->raiz, 0, 0);
	else printf("Arbol vacio\n");
}


void eliminarSubarbol(ArbolBinarioDeBusqueda *arbol, Nodo* raizSubarbol) {
	assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	assert(raizSubarbol != NULL);

	// Primero eliminamos los hijos, si hay
	if (raizSubarbol->hijoIzquierdo != NULL) eliminarSubarbol(arbol, raizSubarbol->hijoIzquierdo);
	if (raizSubarbol->hijoDerecho != NULL) eliminarSubarbol(arbol, raizSubarbol->hijoDerecho);

	// Eliminamos la referencia a raizSubarbol que hay en su padre. Hay que averiguar si  
	// raizSubarbol era el hijo derecho o izquierdo de su padre. También podría no tener padre
	// si es la raíz del árbol entero
	Nodo* padre = raizSubarbol->padre; // Guardamos primero quien es el padre
	if (padre != NULL) {
		if (padre->hijoIzquierdo == raizSubarbol) padre->hijoIzquierdo = NULL;
		if (padre->hijoDerecho == raizSubarbol) padre->hijoDerecho = NULL;
	}
	else arbol->raiz = NULL; // Si no tiene padre, es la raiz del arbol binario de búsqueda entero

	// Eliminamos la raiz y actualizamos n
	free(raizSubarbol);
	arbol->n--;
}


void destruirArbolBinarioDeBusqueda(ArbolBinarioDeBusqueda* arbol) {
	assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	if (arbol->n > 0) eliminarSubarbol(arbol, arbol->raiz);
	free(arbol);
}





