#include "AVL.h"
#include "assert.h"
#include "stdio.h"
#include "stdlib.h"


AVL* construirAVL() {
	AVL* arbol = (AVL*)malloc(sizeof(AVL));
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


int buscar(AVL* arbol, int elementoABuscar) {
	assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	if (arbol->n == 0) return(0);
	else {
		Nodo* nodo = buscarRecursivo(arbol->raiz, elementoABuscar);
		if (nodo->contenido == elementoABuscar) return(1);
		else return (0);
	}
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


void imprimir(AVL* arbol) {
	assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	if (arbol->n > 0) imprimirRecursivo(arbol->raiz, 0, 0);
	else printf("Arbol vacio\n");
}


void eliminarSubarbol(AVL* arbol, Nodo* raizSubarbol) {
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


void destruirAVL(AVL* arbol) {
	assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	if (arbol->n > 0) eliminarSubarbol(arbol, arbol->raiz);
	free(arbol);
}


void actualizarAlturaYFactorDeEquilibrio(Nodo* nodo) {
	assert(nodo != NULL);

	// Calculamos las alturas de los hijos
	int alturaHijoIzquierdo = (nodo->hijoIzquierdo == NULL) ? (-1) : nodo->hijoIzquierdo->altura;
	int alturaHijoDerecho = (nodo->hijoDerecho == NULL) ? (-1) : nodo->hijoDerecho->altura;

	// Calculamos la altura del nodo
	if (alturaHijoIzquierdo >= alturaHijoDerecho) nodo->altura = alturaHijoIzquierdo + 1;
	else nodo->altura = alturaHijoDerecho + 1;

	// Calculamos el factor de equilibrio
	nodo->factorEquilibrio = (alturaHijoDerecho - alturaHijoIzquierdo);
}


void setHijo(Nodo* padre, Nodo* nuevoHijo, int lado) {
	assert(padre != NULL);
	assert(lado == 0 || lado == 1); // 0 es como hijo derecho, 1 es como hijo izquierdo

	// Queremos establecer el hijo derecho
	if (lado == 0) padre->hijoDerecho = nuevoHijo;

	// Queremos establecer el hijo izquierdo
	else padre->hijoIzquierdo = nuevoHijo;

	// Hacemos que el nuevo hijo apunte al padre
	if (nuevoHijo != NULL) nuevoHijo->padre = padre;
}


void cambiarHijo(AVL* arbol, Nodo* antiguoHijo, Nodo* nuevoHijo) {
	assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	assert(antiguoHijo != NULL);
	assert(nuevoHijo != NULL);

	// Averiguamos el padre
	Nodo* padre = antiguoHijo->padre;

	// Si el antiguo hijo no tiene padre, es que el antiguo hijo es la raíz del árbol AVL completo
	// En ese caso, cambiamos el atributo del AVL que apunta a la raíz para que apunte al nuevoHijo
	if (padre == NULL) {
		arbol->raiz = nuevoHijo;
		nuevoHijo->padre = NULL;
	}

	// En caso de que el antiguoHijo tenga padre, hacemos que el padre apunte al nuevoHijo
	else {
		if (padre->hijoDerecho == antiguoHijo) setHijo(padre, nuevoHijo, 0);
		if (padre->hijoIzquierdo == antiguoHijo) setHijo(padre, nuevoHijo, 1);
	}

	// Hacemos que el antiguoHijo no apunte a nadie, ya que ahora no tiene padre
	antiguoHijo->padre = NULL;
}


Nodo* rotarSimpleIzquierda(AVL *arbol, Nodo* raizSubarbol) {
	assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido

	// Precondición: la raiz existe y tiene un factor de equilibrio de 2
	assert(raizSubarbol != NULL);
	assert(raizSubarbol->factorEquilibrio == 2);

	// Precondición: el hijo derecho existe y tiene un factor de equilibrio de 1
	Nodo* hijoDerecho = raizSubarbol->hijoDerecho; // Hijo derecho de la raiz 
	assert(hijoDerecho != NULL);
	assert(hijoDerecho->factorEquilibrio == 1);

	// Para mayor claridad, vamos a usar la nomenclatura de 
	// la diapositiva que explica esta rotación: "x", "y", "A", "B" y "C"
	// No necesitamos guardar ni "A" ni "C" porque no cambian de sitio
	Nodo* x = raizSubarbol;
	Nodo* y = hijoDerecho;
	Nodo* B = y->hijoIzquierdo;

	// Hacemos que el padre de "x" pase a apuntar a "y" en vez de a "x"
	cambiarHijo(arbol, x, y);

	// Hacemos que "B" sea hijo derecho de "x"
	setHijo(x, B, 0);

	// Hacemos que "x" sea hijo izquierdo de "y"
	setHijo(y, x, 1);

	// Recalculamos las alturas de "x" e "y", en este orden
	actualizarAlturaYFactorDeEquilibrio(x);
	actualizarAlturaYFactorDeEquilibrio(y);

	// Devolvemos la nueva raiz del subarbol
	return(y);
}


Nodo* rotarSimpleDerecha(AVL *arbol, Nodo* raizSubarbol) {
	assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido

	// Precondición: la raiz existe y tiene un factor de equilibrio de -2
	assert(raizSubarbol != NULL);
	assert(raizSubarbol->factorEquilibrio == -2);

	// Precondición: el hijo izquierdo existe y tiene un factor de equilibrio de -1
	Nodo* hijoIzquierdo = raizSubarbol->hijoIzquierdo; // Hijo izquierdo de la raiz 
	assert(hijoIzquierdo != NULL);
	assert(hijoIzquierdo->factorEquilibrio == -1);

	// Para mayor claridad, vamos a usar la nomenclatura de 
	// la diapositiva que explica esta rotación: "x", "y", "A", "B" y "C"
	// No necesitamos guardar ni "A" ni "C" porque no cambian de sitio
	Nodo* x = hijoIzquierdo;
	Nodo* y = raizSubarbol;
	Nodo* B = x->hijoDerecho;

	// Hacemos que el padre de "y" pase a apuntar a "x" en vez de a "y"
	cambiarHijo(arbol, y, x);

	// Hacemos que "B" sea hijo izquierdo de "y"
	setHijo(y, B, 1);

	// Hacemos que "y" sea hijo derecho de "x"
	setHijo(x, y, 0);

	// Recalculamos las alturas de "y" y "x", en este orden	
	actualizarAlturaYFactorDeEquilibrio(y);
	actualizarAlturaYFactorDeEquilibrio(x);

	// Devolvemos la nueva raiz del subarbol
	return(x);
}


Nodo* rotarCompuestaDerechaIzquierda(AVL *arbol, Nodo* raizSubarbol) {
	assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido

	// Precondición: la raiz existe y tiene un factor de equilibrio de 2
	assert(raizSubarbol != NULL);
	assert(raizSubarbol->factorEquilibrio == 2);

	// Precondición: el hijo derecho existe y tiene un factor de equilibrio de -1
	Nodo* hijoDerecho = raizSubarbol->hijoDerecho; // Hijo derecho de la raiz 
	assert(hijoDerecho != NULL);
	assert(hijoDerecho->factorEquilibrio == -1);

	// Para mayor claridad, vamos a usar la nomenclatura de 
	// la diapositiva que explica esta rotación: "x", "y", "z", "A", "B", "C" y "D"
	// No necesitamos guardar ni "A" ni "D" porque no cambian de sitio
	Nodo* x = raizSubarbol;
	Nodo* z = hijoDerecho;
	Nodo* y = z->hijoIzquierdo;
	Nodo* B = y->hijoIzquierdo;
	Nodo* C = y->hijoDerecho;

	// Hacemos que el padre de "x" pase a apuntar a "y" en vez de a "x"
	cambiarHijo(arbol, x, y);

	// Hacemos que "B" sea hijo derecho de "x"
	setHijo(x, B, 0);

	// Hacemos que "C" sea hijo izquierdo de "z"
	setHijo(z, C, 1);

	// Hacemos que "x" y "z" sean hijos de "y"
	setHijo(y, x, 1);
	setHijo(y, z, 0);

	// Recalculamos las alturas de "x", "z" e "y", en este orden	
	actualizarAlturaYFactorDeEquilibrio(x);
	actualizarAlturaYFactorDeEquilibrio(z);
	actualizarAlturaYFactorDeEquilibrio(y);

	// Devolvemos la nueva raiz del subarbol
	return(y);
}


Nodo* rotarCompuestaIzquierdaDerecha(AVL *arbol, Nodo* raizSubarbol) {
	assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido

	// Precondición: la raiz existe y tiene un factor de equilibrio de -2
	assert(raizSubarbol != NULL);
	assert(raizSubarbol->factorEquilibrio == -2);

	// Precondición: el hijo izquierdo existe y tiene un factor de equilibrio de 1
	Nodo* hijoIzquierdo = raizSubarbol->hijoIzquierdo; // Hijo izquierdo de la raiz 
	assert(hijoIzquierdo != NULL);
	assert(hijoIzquierdo->factorEquilibrio == 1);

	// Para mayor claridad, vamos a usar la nomenclatura de 
	// la diapositiva que explica esta rotación: "x", "y", "z", "A", "B", "C" y "D"
	// No necesitamos guardar ni "A" ni "D" porque no cambian de sitio
	Nodo* z = raizSubarbol;
	Nodo* x = hijoIzquierdo;
	Nodo* y = x->hijoDerecho;
	Nodo* B = y->hijoIzquierdo;
	Nodo* C = y->hijoDerecho;

	// Hacemos que el padre de "z" pase a apuntar a "y" en vez de a "z"
	cambiarHijo(arbol, z, y);

	// Hacemos que "B" sea hijo derecho de "x"
	setHijo(x, B, 0);

	// Hacemos que "C" sea hijo izquierdo de "z"
	setHijo(z, C, 1);

	// Hacemos que "x" y "z" sean hijos de "y"
	setHijo(y, x, 1);
	setHijo(y, z, 0);

	// Recalculamos las alturas de "x", "z" e "y", en este orden	
	actualizarAlturaYFactorDeEquilibrio(x);
	actualizarAlturaYFactorDeEquilibrio(z);
	actualizarAlturaYFactorDeEquilibrio(y);

	// Devolvemos la nueva raiz del subarbol
	return(y);
}


Nodo* insertarHoja(AVL* arbol, int nuevoElemento) {
	assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	assert(!buscar(arbol, nuevoElemento)); // El nuevo elemento no estaba ya en el árbol

	// Creamos el nuevo nodo que contiene al elemento
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->contenido = nuevoElemento;
	nuevoNodo->padre = NULL;
	nuevoNodo->hijoIzquierdo = NULL;
	nuevoNodo->hijoDerecho = NULL;
	nuevoNodo->altura = 0;
	nuevoNodo->factorEquilibrio = 0;

	// Si el arbol está vacío, lo metemos en la raiz sí o sí
	if (arbol->n == 0) {
		arbol->raiz = nuevoNodo;
	}

	// En caso contrario, buscamos el hueco en donde meterlo como una hoja
	else {
		// Buscamos el hueco
		Nodo* padreDelHueco = buscarRecursivo(arbol->raiz, nuevoElemento); // Puntero al nodo que es el padre del hueco

		// Metemos el nuevo nodo como hijo izquierdo o derecho
		if (nuevoElemento < padreDelHueco->contenido) setHijo(padreDelHueco, nuevoNodo, 1);
		else setHijo(padreDelHueco, nuevoNodo, 0);
	}

	// Incrementamos el número de nodos
	arbol->n++;

	// Devolvemos puntero al nuevo nodo
	return(nuevoNodo);
}


void reequilibrar(AVL *arbol, Nodo* hoja) {
	assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	assert(hoja != NULL);

	// Desde el padre de la hoja, vamos ascendiendo hasta llegar a la raíz.
	// No necesitamos comprobar la hoja, ya que al ser una hoja su altura es 0 y su factor
	// de equilibrio siempre es 0.
	// Por cada nodo que examinamos, actualizamos su altura y su factor de equilibrio,
	// y finalmente rotamos en caso de que dicho factor de equilibrio sea 2 ó -2
	Nodo* nodoActual = hoja->padre; // Calculamos el padre de la hoja inicial
	while (nodoActual != NULL) {

		// Primero calculamos la altura del nodo y su factor de equilibrio
		actualizarAlturaYFactorDeEquilibrio(nodoActual);
		int factorEquilibrio = nodoActual->factorEquilibrio;

		// Si el factor de equilibrio es 2, tenemos dos casos
		if (factorEquilibrio == 2) {
			int factorEquilibrioDerecho = nodoActual->hijoDerecho->factorEquilibrio;
			if (factorEquilibrioDerecho == 1) nodoActual = rotarSimpleIzquierda(arbol, nodoActual);
			if (factorEquilibrioDerecho == -1) nodoActual = rotarCompuestaDerechaIzquierda(arbol, nodoActual);
		}

		// Si el factor de equilibrio es -2, tenemos otros dos casos
		if (factorEquilibrio == -2) {
			int factorEquilibrioIzquierdo = nodoActual->hijoIzquierdo->factorEquilibrio;
			if (factorEquilibrioIzquierdo == -1) nodoActual = rotarSimpleDerecha(arbol, nodoActual);
			if (factorEquilibrioIzquierdo == 1) nodoActual = rotarCompuestaIzquierdaDerecha(arbol, nodoActual);
		}

		// En la siguiente iteracion, haremos lo mismo con el padre del nodo actual
		nodoActual = nodoActual->padre;

	} // Fin while
} // Fin método reequilibrar


void insertar(AVL* arbol, int nuevoElemento) {
	assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	assert(!buscar(arbol, nuevoElemento));

	// Insertamos el nuevo elemento como una hoja
	Nodo* hojaInsertada = insertarHoja(arbol, nuevoElemento);

	// Reequilibramos el árbol
	reequilibrar(arbol, hojaInsertada);

} // Fin método insertar

