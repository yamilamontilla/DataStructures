#include "stdio.h"
#include "Grafo.h"

void main() {

	// Creamos el grafo vacio y lo imprimimos
	Grafo* grafo = construirGrafo();

	// Insertamos los nodos
	insertarNodo(grafo, 'A');
	insertarNodo(grafo, 'B');
	insertarNodo(grafo, 'C');
	insertarNodo(grafo, 'D');
	insertarNodo(grafo, 'E');

	// Insertamos arcos
	insertarArco(grafo, 'A', 'A');
	insertarArco(grafo, 'A', 'C');
	insertarArco(grafo, 'A', 'E');
	insertarArco(grafo, 'B', 'B');
	insertarArco(grafo, 'B', 'D');
	insertarArco(grafo, 'C', 'A');
	insertarArco(grafo, 'C', 'C');
	insertarArco(grafo, 'C', 'E');
	insertarArco(grafo, 'D', 'B');
	insertarArco(grafo, 'D', 'D');
	insertarArco(grafo, 'E', 'A');
	insertarArco(grafo, 'E', 'C');
	insertarArco(grafo, 'E', 'E');

	// Borramos nodos
	borrarNodo(grafo, 'B'); 
	borrarNodo(grafo, 'A'); 
	borrarNodo(grafo, 'E'); 

	// Insertamos nuevos nodos
	insertarNodo(grafo, 'H');
	insertarNodo(grafo, 'G');
	insertarNodo(grafo, 'F');
	insertarNodo(grafo, 'E');

	// Borramos los arcos que quedan en el grafo
	borrarArco(grafo, 'C', 'C');
	borrarArco(grafo, 'D', 'D');

	// Insertamos varios arcos para formar el grafo del enunciado
	insertarArco(grafo, 'C', 'D');
	insertarArco(grafo, 'D', 'C');
	insertarArco(grafo, 'D', 'G');
	insertarArco(grafo, 'G', 'D');
	insertarArco(grafo, 'G', 'H');
	insertarArco(grafo, 'C', 'E');
	insertarArco(grafo, 'E', 'C');
	insertarArco(grafo, 'C', 'F');
	insertarArco(grafo, 'F', 'C');
	insertarArco(grafo, 'F', 'G');
	insertarArco(grafo, 'G', 'F');

	// Recorridos:
	printf("%s\n", recorrerEnProfundidad(grafo, 'C'));
	printf("%s\n", recorrerEnProfundidad(grafo, 'G'));
	printf("%s\n", recorrerEnProfundidad(grafo, 'H'));

	destruirGrafo(grafo);
}