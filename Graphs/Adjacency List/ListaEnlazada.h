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

// Estructura que representa a una lista enlazada doble y circular. No tiene restricci�n de tama�o
// Se trata de una lista enlazada de nodos, en donde cada nodo tiene un elemento (un int), 
// y punteros tanto al nodo anterior como al siguiente. El siguiente al �ltimo es el primero y 
// el anterior al primero es el �ltimo.
typedef struct {
	// Puntero que apuntar� al primer nodo de la lista, o ser� NULL si la lista est� vac�a
	Nodo* punteroPrimerNodo;

	// Numero actual de elementos que tiene la lista
	// Precondici�n: n>=0
	int n;

	// Posici�n y puntero del nodo que devolvi� la �ltima llamada a getNodo()
	int posicionUltimoNodoAccedido;
	Nodo* punteroUltimoNodoAccedido;

} ListaEnlazada;


// Obtiene un nodo de la lista
// Par�metros: 
// - lista: puntero a la lista
// - posici�n: la posici�n del nodo (de 0 a n-1, ambos inclusive)
// Retorno: un puntero al nodo que est� en dicha posici�n
// Precondiciones: 
// - lista != NULL 
// - la posici�n debe estar en el intervalo [0, n-1]
// - La lista no esta vacia (n>0)
// Complejidad temporal: O(n). Como m�ximo hace n/2 iteraciones porque decide si ir hacia delante o hacia atr�s
Nodo* getNodo(ListaEnlazada* lista, int posicion);

// Constructor. Crea una lista de tama�o 0
// Retorno: puntero a la lista reci�n creada
// Complejidad temporal: O(1)
ListaEnlazada* construirListaEnlazada();

// Devuelve un elemento de la lista en determinada posici�n
// Par�metros: 
// - lista: puntero a la lista 
// - posici�n: la posici�n del elemento
// Retorno: una copia del elemento encontrado en esa posici�n
// Precondiciones: 
// - lista != NULL
// - posicion en [0, n-1]
// - n>0 (lista no vac�a)
// Complejidad temporal: O(n)
Ruta getValor(ListaEnlazada* lista, int posicion);

// Modifica un elemento de la lista
// Par�metros:
// - lista: puntero a la lista
// - posicion: la posici�n en donde est� el elemento que queremos modificar
// - nuevoValor: el nuevo valor del elemento
// Precondiciones: 
// - lista != NULL
// - posicion en [0, n-1] 
// - n>0 (lista no vac�a)
// Complejidad temporal: O(n)
void setValor(ListaEnlazada* lista, int posicion, Ruta nuevoValor);

// Inserta un nuevo elemento en una posici�n de la lista
// Par�metros:
// - lista: puntero a la lista
// - posici�n: la posici�n en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
// - nuevoValor: el nuevo elemento que queremos poner
// Precondiciones: 
// - lista != NULL && n >= 0 (la lista existe y su tama�o tiene sentido)
// - posicion en [0, n]
// Complejidad temporal: O(n)
void insertar(ListaEnlazada* lista, int posicion, Ruta nuevoValor);

// Elimina un elemento en una posici�n dada.
// Par�metros:
// - lista: puntero a la lista
// - posicion: la posici�n del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el �ltimo
// Precondiciones: 
// - lista != NULL
// - posicion en [0, n-1]
// - n>0 (lista no vac�a)
// Complejidad temporal: O(n)
void eliminar(ListaEnlazada* lista, int posicion);

// Concatena una lista (lista origen) al final de otra (lista destino). 
// Cada uno de los elementos de la lista origen se copian, en orden, al final de la lista destino,
// por lo tanto la lista de origen no se ve modificada, pero la lista destino s�
// Par�metros: 
// - listaDestino: puntero a la lista destino
// - listaOrigen: puntero a la lista origen
// Precondiciones: 
// - listaDestino != NULL && listaOrigen != NULL
// - listaDestino->n >= 0 && listaOrigen->n >= 0 (el tama�o de ambas listas tiene sentido)
// Complejidad temporal: O(m), siendo m el tama�o de la listaOrigen
void concatenar(ListaEnlazada* listaDestino, ListaEnlazada* listaOrigen);

// Busca la posici�n de un elemento en la lista, usando el m�todo de b�squeda secuencial
// Par�metros: 
// - lista: puntero a la lista en donde buscar
// - elementoABuscar: el elemento a buscar
// Retorno: posici�n del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
// Precondiciones:
// - lista != NULL && n >= 0 (la lista existe y su tama�o tiene sentido)
// Complejidad temporal: O(n)
int buscar(ListaEnlazada* lista, Ruta elementoABuscar);

// Destructor. Libera memoria
// Par�metro: puntero a la lista a eliminar
// Precondici�n: lista != NULL && n >= 0 (la lista existe y su tama�o tiene sentido)
// Complejidad temporal: O(n)
void destruirListaEnlazada(ListaEnlazada* lista);









