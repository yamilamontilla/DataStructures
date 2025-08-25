#include "ArbolBinarioDeBusqueda.h"
#include "assert.h"
#include "stdio.h"
#include "stdlib.h"


ArbolBinarioDeBusqueda* construirArbolBinarioDeBusqueda() {
	ArbolBinarioDeBusqueda* arbol = (ArbolBinarioDeBusqueda*)malloc(sizeof(ArbolBinarioDeBusqueda));
	arbol->n = 0;
	arbol->raiz = NULL;
	arbol->orientacionSiguienteEliminacion = 1;
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
		Nodo* padreDelHueco = buscarRecursivo(arbol->raiz, nuevoElemento); // Puntero al nodo que es el padre del hueco

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


void eliminarSubarbol(ArbolBinarioDeBusqueda* arbol, Nodo* raizSubarbol) {
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


Nodo* buscarMaximo(Nodo* raizSubarbol) {
	// Vamos recursivamente por la rama derecha hasta que no podamos más
	assert(raizSubarbol != NULL);
	if (raizSubarbol->hijoDerecho == NULL) return (raizSubarbol);
	else return (buscarMaximo(raizSubarbol->hijoDerecho));
}


Nodo* buscarMinimo(Nodo* raizSubarbol) {
	// Vamos recursivamente por la rama izquierda hasta que no podamos más
	assert(raizSubarbol != NULL);
	if (raizSubarbol->hijoIzquierdo == NULL) return (raizSubarbol);
	else return (buscarMinimo(raizSubarbol->hijoIzquierdo));
}


void eliminarNodo(ArbolBinarioDeBusqueda* arbol, Nodo* nodoParaEliminar) {
	assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	assert(nodoParaEliminar != NULL);

	Nodo* nodoDesdeDondeCopiar = NULL; // Nodo cuyo contenido se copiará en nodoParaEliminar, si éste último tiene hijos

	// Tenemos cuatro casos excluyentes: 
	// 1. Que no se tenga ningún hijo
	// 2. Que se tengan dos
	// 3. Que se tenga sólo el derecho
	// 4. O que se tenga sólo el izquierdo

	// Primer caso: no tenemos ningún hijo (somos un nodo hoja). Lo eliminamos sin más
	if (nodoParaEliminar->hijoIzquierdo == NULL && nodoParaEliminar->hijoDerecho == NULL) {
		eliminarSubarbol(arbol, nodoParaEliminar);
	}

	else {

		// Segundo caso. Tenemos dos hijos. Cogemos el maximo de la izquierda o el minimo de la derecha segun lo que hicimos la ultima vez
		if (nodoParaEliminar->hijoIzquierdo != NULL && nodoParaEliminar->hijoDerecho != NULL) {

			if (arbol->orientacionSiguienteEliminacion == 1) {
				nodoDesdeDondeCopiar = buscarMinimo(nodoParaEliminar->hijoDerecho);
				arbol->orientacionSiguienteEliminacion = -1;
			}
			else {
				nodoDesdeDondeCopiar = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
				arbol->orientacionSiguienteEliminacion = 1;
			}
		}

		// Tercer caso. Tenemos sólo el hijo derecho
		else if (nodoParaEliminar->hijoIzquierdo == NULL && nodoParaEliminar->hijoDerecho != NULL) {
			nodoDesdeDondeCopiar = buscarMinimo(nodoParaEliminar->hijoDerecho);
			arbol->orientacionSiguienteEliminacion = -1;
		}

		// Cuarto caso. Tenemos sólo el hijo izquierdo
		else { // nodoParaEliminar->getHijoIzquierdo() != NULL && nodoParaEliminar->getHijoDerecho() == NULL
			nodoDesdeDondeCopiar = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
			arbol->orientacionSiguienteEliminacion = 1;
		}

		// Ahora que ya tenemos claro el nodoDesdeDondeCopiar, lo copiamos en el hueco dejado por nodoParaEliminar
		nodoParaEliminar->contenido = nodoDesdeDondeCopiar->contenido;

		// Borramos recursivamente el nodoDesdeDondeCopiar, pues ya lo hemos copiado en el hueco que hemos dejado.
		eliminarNodo(arbol, nodoDesdeDondeCopiar);

	} // Fin del caso 2, 3 y 4

} // Fin procedimiento eliminarNodo()


void eliminar(ArbolBinarioDeBusqueda* arbol, int elementoAEliminar) {
	assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	assert(buscar(arbol, elementoAEliminar)); // El elemento a eliminar tiene que estar
	Nodo* nodoParaEliminar = buscarRecursivo(arbol->raiz, elementoAEliminar);
	eliminarNodo(arbol, nodoParaEliminar);
}
