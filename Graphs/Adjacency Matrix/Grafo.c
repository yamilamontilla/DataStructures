#include "Grafo.h"
#include "assert.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"


int obtenerIndice(Grafo* grafo, char nombreNodo) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido

	// Si strchr() no encuentra el caracter, devuelve NULL.
	// Si lo encuentra, devuelve el puntero a su posición
	if (grafo->n == 0) return (-1); // Si el grafo está vacío, no está el nodo
	char* punteroNodo = strchr(grafo->nombresNodos, nombreNodo);
	if (punteroNodo == NULL) return -1; // No está el nodo
	else return (punteroNodo - grafo->nombresNodos); // Está. Devolvemos su índice.
}


int existeNodo(Grafo* grafo, char nombreNodo) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	int posicionNodo = obtenerIndice(grafo, nombreNodo);
	if (posicionNodo == -1) return (0);
	else return (1);
}


int existeArco(Grafo* grafo, char nombreNodoOrigen, char nombreNodoDestino) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	assert(existeNodo(grafo, nombreNodoOrigen));
	assert(existeNodo(grafo, nombreNodoDestino));

	int indiceNodoOrigen = obtenerIndice(grafo, nombreNodoOrigen);
	int indiceNodoDestino = obtenerIndice(grafo, nombreNodoDestino);
	ListaContigua* filaMatrizAdyacencia = grafo->matriz[indiceNodoOrigen];
	if (getValor(filaMatrizAdyacencia, indiceNodoDestino) > 0) return 1;
	else return 0;
}


Grafo* construirGrafo() {
	Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
	grafo->matriz = NULL;
	grafo->n=0;
	grafo->nombresNodos = (char*)malloc(sizeof(char));
	grafo->nombresNodos[0] = '\0';
	return(grafo);
}


void destruirGrafo(Grafo* grafo) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	for (int i = 0; i < grafo->n; i++) destruirListaContigua(grafo->matriz[i]); // Destruimos cada fila
	free(grafo->matriz); // Destruimos los punteros a las filas
	free(grafo->nombresNodos); // Destruimos los nombres de los nodos
	free(grafo);
}


void insertarNodo(Grafo* grafo, char nombreNodo) {
	assert (grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	assert (!existeNodo(grafo, nombreNodo));

	// Insertamos el nuevo nombre en la lista de nombres
	char nombreNodoEnString[2];
	nombreNodoEnString[0] = nombreNodo;
	nombreNodoEnString[1] = '\0';
	grafo->nombresNodos = (char*)realloc(grafo->nombresNodos, sizeof(char) * (grafo->n + 2)); // No olvidar espacio para '\0'
	strcat(grafo->nombresNodos, nombreNodoEnString);

	// Añadimos una columna mas a todas las filas que ya hay. Para ello, añadimos un 0 al final de cada fila
	// Complejidad temporal: O(n^2), porque cada insercion al final es O(n) pues puede que haya que incrementar capacidad
	for (int i=0; i<grafo->n; i++) insertarAlFinal(grafo->matriz[i], 0);

	// Creamos la nueva fila y la rellenamos con ceros. Fijémonos en que ponemos n+1 elementos
	// Complejidad temporal: O(n^2), porque cada insercion al final es O(n) pues puede que haya que incrementar capacidad
	ListaContigua *nuevaFila = crearListaContigua();
	for (int i=0; i<grafo->n+1; i++) insertarAlFinal(nuevaFila, 0);

	// Añadimos la nueva fila al resto de filas. Para ello primero tenemos que ampliar el espacio de matriz
	// Complejidad temporal O(n), para ampliar el espacio
	grafo->matriz = (ListaContigua**)realloc(grafo->matriz, (grafo->n + 1) * sizeof(ListaContigua*));
	grafo->matriz[grafo->n] = nuevaFila;
	
	// Incrementamos n
	grafo->n++;
}


void insertarArco(Grafo* grafo, char nodoOrigen, char nodoDestino) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	assert(existeNodo(grafo, nodoOrigen));
	assert(existeNodo(grafo, nodoDestino));
	assert(!existeArco(grafo, nodoOrigen, nodoDestino));

	int posicionNodoOrigen = obtenerIndice(grafo, nodoOrigen);
	int posicionNodoDestino = obtenerIndice(grafo, nodoDestino);
	ListaContigua* fila = grafo->matriz[posicionNodoOrigen];
	setValor(fila, posicionNodoDestino, 1);
}


void borrarNodo(Grafo* grafo, char nombreNodo) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	assert(existeNodo(grafo, nombreNodo));

	// Borrar el nodo de la lista de nodos. Al usar memmove, recordar que también se tiene que copiar el carácter nulo del final
	int posicionNodo = obtenerIndice(grafo, nombreNodo); // Indice del nodo
	memmove(&grafo->nombresNodos[posicionNodo], &grafo->nombresNodos[posicionNodo + 1], sizeof(char) * (grafo->n - posicionNodo));

	// Borramos la fila del nodo
	destruirListaContigua(grafo->matriz[posicionNodo]);
	memmove(&grafo->matriz[posicionNodo], &grafo->matriz[posicionNodo + 1], sizeof(ListaContigua*) * (grafo->n - posicionNodo - 1));
	grafo->matriz = (ListaContigua**)realloc(grafo->matriz, sizeof(ListaContigua*) * grafo->n); // Antes era n+1, no olvidar espacio para '\0'

	// Borramos la columna (borramos la misma posición en todas las filas). O(n^2)
	for (int i = 0; i < grafo->n-1; i++) eliminar(grafo->matriz[i], posicionNodo);

	// Actualizamos n
	grafo->n--;
}


void borrarArco(Grafo* grafo, char nodoOrigen, char nodoDestino) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	assert(existeNodo(grafo, nodoOrigen));
	assert(existeNodo(grafo, nodoDestino));
	assert(existeArco(grafo, nodoOrigen, nodoDestino));

	int posicionNodoOrigen = obtenerIndice(grafo, nodoOrigen);
	int posicionNodoDestino = obtenerIndice(grafo, nodoDestino);
	ListaContigua* fila = grafo->matriz[posicionNodoOrigen];
	setValor(fila, posicionNodoDestino, 0);
}


void imprimir(Grafo* grafo) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido

	// Si el grafo está vacio, imprimimos mensaje informativo
	if (grafo->n == 0) printf("La matriz esta vacia\n");

	// En caso contrario, imprimimos la matriz de adyacencia bien alineada
	else {

		// Imprimimos la primera línea de la matriz, con los nombres de los nodos
		printf("  "); // Imprimimos espacio de la esquina superior izquierda de la matriz	
		for (int i = 0; i < grafo->n; i++) printf("%c ", grafo->nombresNodos[i]); // Imprimimos el nombre de los nodos en las columnas
		printf("\n");

		// Imprimimos las filas
		for (int i = 0; i < grafo->n; i++) {
			char nombreNodoOrigen = grafo->nombresNodos[i];
			printf("%c ", nombreNodoOrigen); // Imprimimos el nombre del nodo de la fila
			for (int j = 0; j < grafo->n; j++) {
				char nombreNodoDestino = grafo->nombresNodos[j];
				printf("%d ", existeArco(grafo, nombreNodoOrigen, nombreNodoDestino));
			}
			printf("\n");
		}
		printf("\n");
	}
}
