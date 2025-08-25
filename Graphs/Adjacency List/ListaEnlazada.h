#pragma once

#include "Ruta.h"


// Estructura que representa un nodo de una lista enlazada doblemente circular. Como es una 
// autoreferencia, hay que hacerlo en dos pasos: primero crear la estructura, y luego el typedef
struct _Nodo {
	Ruta elemento; // El elemento que guarda el nodo
	struct _Nodo* anteriorNodo; // Puntero al nodo anterior de la lista enlazada
	struct _Nodo* siguienteNodo; // Puntero al siguiente nodo de la lista enlazada
};

typedef struct _Nodo Nodo;

// Estructura que representa a una lista enlazada doble y circular. No tiene restricción de tamaño
// Se trata de una lista enlazada de nodos, en donde cada nodo tiene un elemento (un int), 
// y punteros tanto al nodo anterior como al siguiente. El siguiente al último es el primero y 
// el anterior al primero es el último.
typedef struct {
	// Puntero que apuntará al primer nodo de la lista, o será NULL si la lista está vacía
	Nodo* punteroPrimerNodo;

	// Numero actual de elementos que tiene la lista
	// Precondición: n>=0
	int n;

	// Posición y puntero del nodo que devolvió la última llamada a getNodo()
	int posicionUltimoNodoAccedido;
	Nodo* punteroUltimoNodoAccedido;

} ListaEnlazada;


// Obtiene un nodo de la lista
// Parámetros: 
// - lista: puntero a la lista
// - posición: la posición del nodo (de 0 a n-1, ambos inclusive)
// Retorno: un puntero al nodo que está en dicha posición
// Precondiciones: 
// - lista != NULL 
// - la posición debe estar en el intervalo [0, n-1]
// - La lista no esta vacia (n>0)
// Complejidad temporal: O(n). Como máximo hace n/2 iteraciones porque decide si ir hacia delante o hacia atrás
Nodo* getNodo(ListaEnlazada* lista, int posicion);

// Constructor. Crea una lista de tamaño 0
// Retorno: puntero a la lista recién creada
// Complejidad temporal: O(1)
ListaEnlazada* construirListaEnlazada();

// Devuelve un elemento de la lista en determinada posición
// Parámetros: 
// - lista: puntero a la lista 
// - posición: la posición del elemento
// Retorno: una copia del elemento encontrado en esa posición
// Precondiciones: 
// - lista != NULL
// - posicion en [0, n-1]
// - n>0 (lista no vacía)
// Complejidad temporal: O(n)
Ruta getValor(ListaEnlazada* lista, int posicion);

// Modifica un elemento de la lista
// Parámetros:
// - lista: puntero a la lista
// - posicion: la posición en donde está el elemento que queremos modificar
// - nuevoValor: el nuevo valor del elemento
// Precondiciones: 
// - lista != NULL
// - posicion en [0, n-1] 
// - n>0 (lista no vacía)
// Complejidad temporal: O(n)
void setValor(ListaEnlazada* lista, int posicion, Ruta nuevoValor);

// Inserta un nuevo elemento en una posición de la lista
// Parámetros:
// - lista: puntero a la lista
// - posición: la posición en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
// - nuevoValor: el nuevo elemento que queremos poner
// Precondiciones: 
// - lista != NULL && n >= 0 (la lista existe y su tamaño tiene sentido)
// - posicion en [0, n]
// Complejidad temporal: O(n)
void insertar(ListaEnlazada* lista, int posicion, Ruta nuevoValor);

// Elimina un elemento en una posición dada.
// Parámetros:
// - lista: puntero a la lista
// - posicion: la posición del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el último
// Precondiciones: 
// - lista != NULL
// - posicion en [0, n-1]
// - n>0 (lista no vacía)
// Complejidad temporal: O(n)
void eliminar(ListaEnlazada* lista, int posicion);

// Concatena una lista (lista origen) al final de otra (lista destino). 
// Cada uno de los elementos de la lista origen se copian, en orden, al final de la lista destino,
// por lo tanto la lista de origen no se ve modificada, pero la lista destino sí
// Parámetros: 
// - listaDestino: puntero a la lista destino
// - listaOrigen: puntero a la lista origen
// Precondiciones: 
// - listaDestino != NULL && listaOrigen != NULL
// - listaDestino->n >= 0 && listaOrigen->n >= 0 (el tamaño de ambas listas tiene sentido)
// Complejidad temporal: O(m), siendo m el tamaño de la listaOrigen
void concatenar(ListaEnlazada* listaDestino, ListaEnlazada* listaOrigen);

// Busca la posición de un elemento en la lista, usando el método de búsqueda secuencial
// Parámetros: 
// - lista: puntero a la lista en donde buscar
// - elementoABuscar: el elemento a buscar
// Retorno: posición del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
// Precondiciones:
// - lista != NULL && n >= 0 (la lista existe y su tamaño tiene sentido)
// Complejidad temporal: O(n)
int buscar(ListaEnlazada* lista, Ruta elementoABuscar);

// Destructor. Libera memoria
// Parámetro: puntero a la lista a eliminar
// Precondición: lista != NULL && n >= 0 (la lista existe y su tamaño tiene sentido)
// Complejidad temporal: O(n)
void destruirListaEnlazada(ListaEnlazada* lista);









