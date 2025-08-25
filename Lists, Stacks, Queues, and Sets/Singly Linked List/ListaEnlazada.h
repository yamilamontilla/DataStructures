#pragma once

// Estructura que representa un nodo de una lista enlazada. Como es una autoreferencia,
// hay que hacerlo en dos pasos: primero crear la estructura, y luego el typedef
struct _Nodo {
	int elemento; // El elemento que guarda el nodo
	struct _Nodo* siguienteNodo; // Puntero al siguiente nodo de la lista enlazada
};

typedef struct _Nodo Nodo;

// Estructura que representa a una lista enlazada simple. No tiene restricción de tamaño
// Se trata de una lista enlazada de nodos, en donde cada nodo tiene un elemento (un int), y un puntero al siguiente nodo
typedef struct {
	// Puntero que apuntará al primer nodo de la lista, o será NULL si la lista está vacía
	Nodo* punteroPrimerNodo;

	// Numero actual de elementos que tiene la lista
	// Precondición: n>=0
	int n;
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
// Complejidad temporal: O(n)
Nodo *getNodo (ListaEnlazada *lista, int posicion);

// Constructor. Crea una lista de tamaño 0
// Retorno: puntero a la lista recién creada
// Complejidad temporal: O(1)
ListaEnlazada *construirListaEnlazada();

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
int getValor(ListaEnlazada *lista, int posicion);

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
void setValor(ListaEnlazada *lista, int posicion, int nuevoValor);

// Inserta un nuevo elemento en una posición de la lista
// Parámetros:
// - lista: puntero a la lista
// - posición: la posición en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
// - nuevoValor: el nuevo elemento que queremos poner
// Precondiciones: 
// - lista != NULL && n >= 0 (la lista existe y su tamaño tiene sentido)
// - posicion en [0, n]
// Complejidad temporal: O(n)
void insertar (ListaEnlazada *lista, int posicion, int nuevoValor);

// Elimina un elemento en una posición dada.
// Parámetros:
// - lista: puntero a la lista
// - posicion: la posición del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el último
// Precondiciones: 
// - lista != NULL
// - posicion en [0, n-1]
// - n>0 (lista no vacía)
// Complejidad temporal: O(n)
void eliminar (ListaEnlazada *lista, int posicion);

// Destructor. Libera memoria
// Parámetro: puntero a la lista a eliminar
// Precondición: lista != NULL && n >= 0 (la lista existe y su tamaño tiene sentido)
// Complejidad temporal: O(n)
void destruirListaEnlazada(ListaEnlazada *lista);








