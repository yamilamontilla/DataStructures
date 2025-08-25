#pragma once
#include "ListaContigua.h"


// Grafo dirigido, no acíclico, no multigrafo, pseudografo, no necesariamente conexo, no etiquetado
// Implementado con matriz de adyacencia
typedef struct {
	ListaContigua** matriz; // Puntero al comienzo de un array de punteros a listas. Cada lista será una fila de la matriz de adyacencia
	int n; // Numero de nodos del grafo
	char *nombresNodos; // Lista de nombres de los nodos. Como el nombre de cada nodo es un carácter. Es un texto terminado en '\0'
} Grafo;


// Obtiene el indice de un nodo (número de columna o fila de la matriz de adyacencia en donde está)
// Parámetros: 
// - grafo: puntero al struct que representa al grafo
// - nombreNodo: nombre del nodo cuyo índice se quiere obtener (una letra)
// Retorno: el índice del nodo (de 0 a n-1) si está en el grafo, -1 si no está
// Precondiciones:
// - grafo != NULL && n >= 0 (el grafo tiene sentido)
// Complejidad temporal: O(n) porque buscamos secuencialmente el nodo en la lista de nombres de nodos
int obtenerIndice(Grafo* grafo, char nombreNodo);


// Comprueba si un nodo está o no está en el grafo
// Parámetros: 
// - grafo: puntero al struct que representa al grafo
// - nombreNodo: nombre del nodo se quiere ver si está en el grafo
// Retorno: 1 si está, 0 si no está
// Precondiciones:
// - grafo != NULL && n >= 0 (el grafo tiene sentido)
// Complejidad temporal: O(n) porque buscamos secuencialmente el nodo en la lista de nombres de nodos
int existeNodo(Grafo* grafo, char nombreNodo);


// Comprobamos si existe un arco entre dos nodos
// Parámetros: 
// - grafo: puntero al struct que representa al grafo
// - nombreNodoOrigen: el nombre del nodo origen
// - nombreNodoDestino: el nombre del nodo destino
// Retorno: 1 si existe el arco, 0 si no
// Precondiciones:
// - grafo != NULL && n >= 0 (el grafo tiene sentido)
// - los nodos tienen que existir en el grafo
// Complejidad temporal: O(1)
int existeArco (Grafo *grafo, char nombreNodoOrigen, char nombreNodoDestino);


// Crea un grafo vacío
// Retorno: puntero al struct que representa al nuevo grafo creado
// Complejidad temporal: O(1)
Grafo *construirGrafo();


// Destruye el grafo y libera la memoria de todos sus nodos
// Parámetros: 
// - grafo: puntero al struct que representa al grafo
// Precondiciones:
// - grafo != NULL && n >= 0 (el grafo tiene sentido)
// Complejidad temporal: O(n) porque hay que llamar al destructor de cada fila, el cual es O(1)
void destruirGrafo(Grafo* grafo);


// Inserta un nodo desconectado en el grafo
// Parámetros: 
// - grafo: puntero al struct que representa al grafo
// - nombreNodo: nombre del nuevo nodo que queremos insertar
// Precondiciones:
// - grafo != NULL && n >= 0 (el grafo tiene sentido)
// - no existe ningún nodo en el grafo que tenga dicho nombre
// Complejidad temporal: O(n^2) 
void insertarNodo(Grafo *grafo, char nombreNodo);


// Inserta un nuevo arco en el grafo
// Parámetros: 
// - grafo: puntero al struct que representa al grafo
// - nodoOrigen: nombre del nodo origen del arco que queremos añadir
// - nodoDestino: nombre del nodo destino del arco que queremos añadir
// Precondiciones:
// - grafo != NULL && n >= 0 (el grafo tiene sentido)
// - los dos nodos deben existir previamente en el grafo
// - no existía previamente el arco
// Complejidad temporal: O(n) porque hay que obtener el indice del nodo a partir de su nombre
void insertarArco (Grafo *grafo, char nodoOrigen, char nodoDestino);


// Borrar un nodo del grafo. Borramos automáticamente todos los arcos que llegan y que parten del nodo a eliminar
// Parámetros: 
// - grafo: puntero al struct que representa al grafo
// - nombreNodo: nombre del nodo a eliminar
// Precondiciones:
// - grafo != NULL && n >= 0 (el grafo tiene sentido)
// - el nodo debe previamente existir
// Complejidad temporal: O(n^2)
void borrarNodo(Grafo *grafo, char nombreNodo);


// Borra un arco del nodo
// Parámetros: 
// - grafo: puntero al struct que representa al grafo
// - nodoOrigen: nombre del nodo origen del arco que queremos eliminar
// - nodoDestino: nombre del nodo destino del arco que queremos eliminar
// Precondiciones:
// - grafo != NULL && n >= 0 (el grafo tiene sentido)
// - los dos nodos deben existir previamente en el grafo
// - existía previamente el arco en el grafo
// Complejidad temporal: O(n) porque hay que obtener el indice del nodo a partir de su nombre
void borrarArco (Grafo *grafo, char nodoOrigen, char nodoDestino);



// Imprime el grafo por pantalla en forma de matriz de adyacencia, imprimiendo títulos de las columnas y filas
// OJO: este método viola el principio de separación entre interfaz y modelo
// Parámetros: 
// - grafo: puntero al struct que representa al grafo
// Precondiciones:
// - grafo != NULL && n >= 0 (el grafo tiene sentido)
// Complejidad temporal: O(n^2) porque imprimimos todos los posibles arcos
void imprimir(Grafo *grafo);


