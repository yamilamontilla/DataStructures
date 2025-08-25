#include "stdio.h"
#include "Grafo.h"

void main() {

	// Creamos el grafo vacio
	Grafo* grafo = construirGrafo();

	// Insertamos los nodos
	insertarNodo(grafo, 'A');
	insertarNodo(grafo, 'B');
	insertarNodo(grafo, 'C');
	insertarNodo(grafo, 'D');
	insertarNodo(grafo, 'E');
	insertarNodo(grafo, 'F');
	insertarNodo(grafo, 'G');

	// Insertamos arcos
	insertarArco(grafo, 'A', 'B');
	insertarArco(grafo, 'A', 'D');
	insertarArco(grafo, 'B', 'D');
	insertarArco(grafo, 'B', 'E');
	insertarArco(grafo, 'C', 'A');
	insertarArco(grafo, 'C', 'D');
	insertarArco(grafo, 'C', 'F');
	insertarArco(grafo, 'D', 'E');
	insertarArco(grafo, 'D', 'F');
	insertarArco(grafo, 'D', 'G');
	insertarArco(grafo, 'E', 'G');
	insertarArco(grafo, 'G', 'F');

	// Imprimimos
	imprimir(grafo);

	// Recorrido topologico
	printf("Recorrido topologico: %s\n\n", recorrerTopologico(grafo));

	// Imprimimos
	imprimir(grafo);

	// Destruimos el grafo
	destruirGrafo(grafo);
}