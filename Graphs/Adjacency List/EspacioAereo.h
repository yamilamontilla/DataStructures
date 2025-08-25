#pragma once
#define _CRT_SECURE_NO_WARNINGS // Para quitar los avisos por métodos deprecados por inseguros (scanf, strcpy, etc)

#include "Ruta.h"
#include "Aeropuerto.h"
#include "ListaEnlazada.h"
#include "ListaContigua.h"


// Averigua si un aeropuerto existe en el grafo o no
// Parámetros: 
// - grafo: puntero a la lista contigua que representa al grafo
// - nombre: nombre del aeropuerto
// Retorno: 1 si existe, 0 si no
// Precondiciones:
// - grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n (la lista que representa al grafo tiene sentido)
// - nombre != NULL
// Complejidad temporal: O(n), porque es búsqueda secuencial en lista contigua
int existeAeropuerto(ListaContigua *grafo, char *nombre);


// Obtiene la lista de rutas que parten desde un origen
// Parámetros: 
// - grafo: puntero a la lista contigua que representa al grafo
// - origen: nombre del aeropuerto de origen
// Retorno: puntero a una lista enlazada con las rutas que parten desde el origen
// Precondiciones:
// - grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n (la lista que representa al grafo tiene sentido)
// - origen != NULL
// - el aeropuerto de origen existe en el grafo
// Complejidad temporal: O(n), pues hay que encontrar el nodo origen
ListaEnlazada* getDestinos(ListaContigua *grafo, char *origen);


// Obtiene la lista de rutas que llegan a un destino
// Parámetros: 
// - grafo: puntero a la lista contigua que representa al grafo
// - destino: nombre del aeropuerto de destino
// Retorno: puntero a una lista con las rutas que llegan al estino
// Precondiciones:
// - grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n (la lista que representa al grafo tiene sentido)
// - destino != NULL
// - el aeropuerto de destino existe en el grafo
// Complejidad temporal: O(n), pues hay que encontrar el nodo destino
ListaEnlazada* getOrigenes(ListaContigua *grafo, char *destino);


// Averigua si hay una ruta entre dos aeropuertos
// Parámetros: 
// - grafo: puntero a la lista contigua que representa al grafo
// - origen: nombre del aeropuerto origen
// - destino: nombre del aeropuerto destino
// Retorno: 1 si hay ruta desde el origen hasta el destino, 0 si no
// Precondiciones:
// - grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n (la lista que representa al grafo tiene sentido)
// - origen != NULL && destino != NULL
// - ambos aeropuertos existen en el grafo
// Complejidad temporal: O(n). El algoritmo tiene dos fases: buscar el aeropuerto origen (O(n)) y,
// dentro de su lista enlazada, el aeropuerto destino. Esto último también es O(n), porque el grafo
// NO es multigrafo, y por lo tanto el número de arcos que salen de un nodo en el peor caso sería n. 
// Si el grafo SI fuera multigrafo, sería O(arcos), pues en la segunda fase tendríamos que hacer
// una búsqueda secuencial en la lista enlazada con tamaño "arcos", y el número de arcos de un grafo
// suele ser muy superior al número de nodos, por lo que el algoritmo completo sería O(arcos). 
int existeRuta(ListaContigua *grafo, char *origen, char *destino);


// Imprime por consola el espacio aereo entero
// Parámetros: 
// - grafo: puntero a la lista contigua que representa al grafo
// Precondiciones:
// - grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n (la lista que representa al grafo tiene sentido)
// OJO: este método viola el principio de separación entre interfaz y modelo
// Complejidad temporal: O(arcos), siendo arcos el numero de arcos del grafo
void imprimirGrafo(ListaContigua *grafo);


// Inserta un nuevo aeropuerto, sin rutas entrantes ni salientes
// Parámetros: 
// - grafo: puntero a la lista contigua que representa al grafo
// - nombre: nombre del nuevo aeropuerto
// Precondiciones:
// - grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n (la lista que representa al grafo tiene sentido)
// - nombre != NULL
// - el nombre del nuevo aeropuerto no debe existir previamente en el grafo
// Complejidad temporal: O(1)
void insertarAeropuerto(ListaContigua *grafo, char *nombre);


// Inserta una nueva ruta en el espacio aéreo
// Parámetros:
// - grafo: puntero a la lista contigua que representa al grafo
// - origen: nombre del aeropuerto origen
// - destino: nombre del aeropuerto destino
// - distancia: numero de kilómetros de la ruta
// - empresa: nombre de la compañía aérea que opera la línea
// Precondiciones: 
// - grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n (la lista que representa al grafo tiene sentido)
// - origen, destino y empresa son != NULL
// - Origen y destino existen en el grafo
// - No existe aún en el grafo una ruta entre origen y destino
// - distancia > 0
// Complejidad temporal: O(n), pues hay que buscar secuencialmente el aeropuerto de origen
void insertarRuta(ListaContigua *grafo, char *origen, char *destino, int distancia, char *empresa);


// Elimina una ruta
// Parámetros: 
// - grafo: puntero a la lista contigua que representa al grafo
// - origen: nombre del aeropuerto origen
// - destino: nombre del aeropuerto destino
// Precondiciones: 
// - grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n (la lista que representa al grafo tiene sentido)
// - origen != NULL && destino != NULL
// - ambos aeropuertos y la ruta existen en el grafo
// Complejidad temporal: O(n), porque no es multigrafo
void eliminarRuta(ListaContigua *grafo, char *origen, char *destino);


// Elimina un aeropuerto de la red. Elimina también todas las rutas que parten y llegan a él
// Parámetros: 
// - grafo: puntero a la lista contigua que representa al grafo
// - nombre: nombre del aeropuerto a eliminar
// Precondiciones: 
// - grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n (la lista que representa al grafo tiene sentido)
// - nombre != NULL
// - el aeropuerto tiene que existir en el grafo
// Complejidad temporal: O(n), ya que, al no ser un multigrafo, en el peor de los casos
// llegan n arcos al nodo y parten n arcos del nodo, por lo tanto habría que eliminar 2n arcos
void eliminarAeropuerto(ListaContigua *grafo, char *nombre);


