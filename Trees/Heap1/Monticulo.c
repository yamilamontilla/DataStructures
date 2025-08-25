#include "Monticulo.h"
#include "stdio.h"
#include "assert.h"


void imprimirRecursivo(ListaContigua *vector, int raizSubarbol, int numeroTabulaciones) {
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
	while (posicion > 1 && getValor(vector, posicion-1) < getValor(vector, posicion/2-1)) {
		// Intercambiamos
		int padre = getValor(vector, posicion/2-1);
		setValor(vector, posicion/2-1, getValor(vector, posicion-1));
		setValor(vector, posicion-1, padre);
		
		// Actualizamos la posicion actual del nuevo elemento
		posicion = posicion/2;
	}

	assert(isMonticulo(vector, 1)); // Postcondicion
}







