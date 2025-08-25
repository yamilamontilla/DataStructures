#include "Monticulo.h"
#include "stdio.h"
#include "assert.h"


void imprimirRecursivo(ListaContigua* vector, int raizSubarbol, int numeroTabulaciones) {
	assert(vector != NULL && vector->n >= 0 && vector->capacidad >= vector->n); // lista contigua coherente
	assert(raizSubarbol >= 1);
	assert(numeroTabulaciones >= 0);

	if (raizSubarbol <= vector->n) {

		// Imprimimos el nodo raiz con el nivel pasado como parametro
		for (int i = 0; i < numeroTabulaciones; i++) printf("\t");
		printf("%d\n", getValor(vector, raizSubarbol - 1));

		// Imprimimos sus hijos con una tabulacion mas
		imprimirRecursivo(vector, raizSubarbol * 2, numeroTabulaciones + 1);
		imprimirRecursivo(vector, raizSubarbol * 2 + 1, numeroTabulaciones + 1);
	}
}


void imprimir(ListaContigua* vector) {
	assert(vector != NULL && vector->n >= 0 && vector->capacidad >= vector->n); // lista contigua coherente
	imprimirRecursivo(vector, 1, 0);
}


int isMonticulo(ListaContigua* vector, int raizSubarbol) {
	assert(vector != NULL && vector->n >= 0 && vector->capacidad >= vector->n); // lista contigua coherente
	assert(raizSubarbol >= 1);

	// Si la posicion de la raiz del subarbol se sale de rango, el subarbol es vacio y por lo tanto sí es montículo
	if (raizSubarbol > vector->n) return(1);

	int padre = getValor(vector, raizSubarbol - 1);

	// Si existe hijo izquierdo, si éste es menor que el padre o bien el subarbol que empieza en él no es un montículo,
	// entonces nuestro árbol no es un montículo
	if (raizSubarbol * 2 <= vector->n) {
		if (!isMonticulo(vector, raizSubarbol * 2)) return(0);
		if (padre > getValor(vector, raizSubarbol * 2 - 1)) return(0);
	}

	// Si existe hijo derecho, si éste es menor que el padre o bien el subarbol que empieza en él no es un montículo,
	// entonces nuestro árbol no es un montículo
	if (raizSubarbol * 2 + 1 <= vector->n) {
		if (!isMonticulo(vector, raizSubarbol * 2 + 1)) return(0);
		if (padre > getValor(vector, raizSubarbol * 2 + 1 - 1)) return(0);
	}

	return (1); // Si hemos llegado hasta aquí, estamos en un montículo
}



void insertarEnMonticulo(ListaContigua* vector, int nuevoElemento) {
	assert(vector != NULL && vector->n >= 0 && vector->capacidad >= vector->n); // lista contigua coherente

	// Lo insertamos al final
	insertarAlFinal(vector, nuevoElemento);

	// Vamos intercambiando con su padre hasta que sea mayor que su padre o hasta que lleguemos a la raiz (posicion 1)
	int posicion = vector->n;
	while (posicion > 1 && getValor(vector, posicion - 1) < getValor(vector, posicion / 2 - 1)) {
		// Intercambiamos
		int padre = getValor(vector, posicion / 2 - 1);
		setValor(vector, posicion / 2 - 1, getValor(vector, posicion - 1));
		setValor(vector, posicion - 1, padre);

		// Actualizamos la posicion actual del nuevo elemento
		posicion = posicion / 2;
	}

	assert(isMonticulo(vector, 1)); // Postcondicion
}


void reestructurar(ListaContigua *vector) {
	assert(vector != NULL && vector->n >= 0 && vector->capacidad >= vector->n); // lista contigua coherente
	
	int n = vector->n; // Numero de elementos del arbol
	assert(n >= 2);
	assert(isMonticulo(vector, 2)); // El subarbol izquierdo que cuelga de la raiz es un monticulo
	if (n >= 3) assert(isMonticulo(vector, 3)); // El subarbol derecho que cuelga de la raiz es un monticulo

	int esMonticulo = 0; // Booleano
	int posicionPadre = 1;
	while (!esMonticulo) {

		int valorHijoMenor; // Guardará el valor del hijo menor
		int posicionHijoMenor; // Guardará la posición del hijo menor

		// Posicion y valor del padre
		int valorPadre = getValor(vector, posicionPadre - 1); // Valor del elemento padre actual

		// Calculamos la posición del hijo menor. Si sólo hay un hijo, es ese.
		// Hay al menos un hijo porque, si no lo hubiera, no hubieramos entrado en el bucle. La primera vez
		// que entramos en el bucle lo sabemos porque el padre es 1, y existe la precondición de que al menos
		// el árbol tenga dos nodos. Las siguientes veces es porque, al final de este bucle, se comprueba
		// si hemos llegado a una hoja, y en ese caso no entramos
		if (posicionPadre * 2 + 1 > n) posicionHijoMenor = posicionPadre * 2;
		else {
			// Hay dos hijos seguro. Comparamos el valor de ambos
			int valorHijoIzquierdo = getValor(vector, posicionPadre * 2 - 1);
			int valorHijoDerecho = getValor(vector, posicionPadre * 2 + 1 - 1);
			if (valorHijoIzquierdo < valorHijoDerecho) posicionHijoMenor = posicionPadre * 2;
			else posicionHijoMenor = posicionPadre * 2 + 1;
		}

		// Calculamos el valor del hijo menor
		valorHijoMenor = getValor(vector, posicionHijoMenor - 1);

		// Intercambiamos con el hijo menor, si es necesario
		if (valorPadre > valorHijoMenor) {
			// Intercambiamos
			setValor(vector, posicionPadre - 1, valorHijoMenor);
			setValor(vector, posicionHijoMenor - 1, valorPadre);

			// Actualizamos la posicion del padre
			posicionPadre = posicionHijoMenor;

			// Si el nuevo padre ya no tiene hijos (es decir ni siquiera tiene hijo
			// izquierdo), hemos terminado. Recuerda que, si no tiene hijo izquierdo,
			// tampoco puede tener hijo derecho (pues es un árbol binario completo)
			if (posicionPadre * 2 > n) esMonticulo = 1;
		}

		// Si no hacía falta intercambiar el padre con su hijo menor, hemos terminado
		else esMonticulo = 1;

	} // Fin while
} // Fin función


void borrarEnMonticulo(ListaContigua *vector) {
	assert(vector != NULL && vector->n >= 0 && vector->capacidad >= vector->n); // lista contigua coherente
	assert(vector->n > 0); // Montículo no vacío (hay algo que borrar)
	int ultimo = getValor(vector, vector->n - 1); // Obtenemos el ultimo elemento del monticulo
	setValor(vector, 0, ultimo); // Copiamos el ultimo elemento en la raiz
	eliminarAlFinal(vector); // Borramos el ultimo elemento
	if (vector->n >= 2) reestructurar(vector); // Reestructuramos si arbol tiene al menos dos elementos
}


int getRaizMonticulo(ListaContigua *vector) {
	assert(vector != NULL && vector->n >= 0 && vector->capacidad >= vector->n); // lista contigua coherente
	assert(vector->n > 0); // Montículo no vacío
	return (getValor(vector, 0));
}


void ordenarPorMonticulo(ListaContigua* lista) {
	assert(lista != NULL && lista->n >= 0 && lista->capacidad >= lista->n); // lista contigua coherente

	ListaContigua *monticulo = crearListaContigua(); // Monticulo auxiliar que servirá para ordenar
	int n = lista->n; // Numero de elementos

	// Creamos el monticulo
	for (int i = 0; i < n; i++) {
		int elemento = getValor(lista, i);
		insertarEnMonticulo(monticulo, elemento);
	}

	// Vamos sacando del monticulo y poniéndolo en la lista, en orden
	for (int i = 0; i < n; i++) {
		int elemento = getRaizMonticulo(monticulo);
		borrarEnMonticulo(monticulo);
		setValor(lista, i, elemento);
	}

	destruirListaContigua(monticulo);
}
