#pragma once // Esta directiva evita que se incluya por error este archivo más de una vez en el main

#include "Aeropuerto.h"

// Struct que representa a una lista contigua en memoria y cuya capacidad se redimensiona automáticamente
// de modo que el usuario no tiene que preocuparse por su capacidad
typedef struct {

	// Puntero que apuntará a la zona de memoria en donde empieza la ListaContigua
	Aeropuerto* vector;

	// Numero actual de elementos que tiene la ListaContigua
	// Precondición: n>=0
	int n;

	// Capacidad actual de la ListaContigua
	// Precondición: capacidad >= n
	int capacidad;

} ListaContigua;

// Constructor. Crea una ListaContigua de tamaño y capacidad 0
// Retorno: puntero al nuevo struct creado
// Complejidad temporal: O(1)
ListaContigua* crearListaContigua();

// Destructor. Libera memoria
// Parámetro: puntero al struct que representa la lista
// Precondiciones: 
// - lista != NULL
// - n >= 0 && capacidad >= n (n y capacidad tienen sentido)
// Complejidad temporal: O(1)
void destruirListaContigua(ListaContigua* lista);

// Nos dice si la ListaContigua está llena o no.
// Parámetro: puntero al struct que representa la lista
// Retorno: número distinto de cero si está llena, 0 si no está llena
// Precondiciones: 
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// Complejidad temporal: O(1)
int isLlena(ListaContigua* lista);

// Devuelve un elemento de la ListaContigua
// Parámetros: 
// - lista: puntero al struct que representa la lista
// - posicion: la posición del elemento
// Retorno: el elemento encontrado en esa posición
// Precondiciones:
// - posicion en [0, n-1]
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// Complejidad temporal: O(1)
Aeropuerto getValorEnContigua(ListaContigua* lista, int posicion);

// Modifica un elemento de la ListaContigua
// Parámetros:
// - lista: puntero al struct que representa la lista
// - posicion: la posición del elemento que queremos modificar
// - nuevoValor: el nuevo valor del elemento
// Precondiciones:
// - posicion en [0, n-1]
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// Complejidad temporal: O(1)
void setValorEnContigua(ListaContigua* lista, int posicion, Aeropuerto nuevoValor);

// Amplía o disminuye la capacidad en un valor
// Parámetros: 
// - lista: puntero al struct que representa la lista
// - incremento: cantidad a aumentar (si es positivo) o disminuir (si es negativo) la capacidad actual de la lista
// Precondiciones:
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// Complejidad temporal: O(n)
void ampliarCapacidad(ListaContigua* lista, int incremento);

// Inserta un nuevo elemento en la última posición de la ListaContigua, 
// ampliando previamente la capacidad si es necesario
// Parámetros:
// - lista: puntero al struct que representa la lista
// - nuevoValor: el nuevo elemento que queremos poner
// Precondiciones:
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// Complejidad temporal: O(n)
void insertarAlFinal(ListaContigua* lista, Aeropuerto nuevoValor);

// Elimina el elemento de la última posición de la ListaContigua,
// disminuyendo posteriormente la capacidad si es necesario
// Parámetro: puntero al struct que representa la lista
// Precondiciones:
// - lista != NULL
// - n > 0 (la lista no está vacía)
// - capacidad >= n (valor de "capacidad" tiene sentido)
// Complejidad temporal: O(1)
void eliminarAlFinal(ListaContigua* lista);

// Inserta un nuevo elemento en una posición de la lista, dejando primero un hueco para meterlo ahí
// Los elementos que había desde la posición hasta el final de la ListaContigua se desplazarán una posición a la derecha
// Parámetros:
// - lista: puntero al struct que representa la lista
// - posición: la posición en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
// - nuevoValor: el nuevo elemento que queremos poner
// Precondiciones:
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// - posicion en [0, n]
// Complejidad temporal: O(n)
void insertarEnContigua(ListaContigua *lista, int posicion, Aeropuerto nuevoValor);

// Elimina un elemento en una posición dada.
// Los elementos que había desde posicion+1 hasta el final de la ListaContigua se desplazarán una posición a la izquierda
// Parámetros:
// - lista: puntero al struct que representa la lista
// - posicion: la posición del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el último
// Precondiciones:
// - lista != NULL
// - n > 0 (la lista no está vacía)
// - capacidad >= n (valor de "capacidad" tiene sentido)
// - posicion en [0, n-1]
// Complejidad temporal: O(n)
void eliminarEnContigua(ListaContigua *lista, int posicion);

// Concatena una lista (lista origen) al final de otra (lista destino). 
// Cada uno de los elementos de la lista origen se copian, en orden, al final de la lista destino,
// por lo tanto la lista de origen no se ve modificada, pero la lista destino sí
// Parámetros: 
// - listaDestino: puntero al struct que representa a la lista destino
// - listaOrigen: puntero al struct que representa a la lista origen
// Precondiciones: 
// - listaDestino != NULL && listaOrigen != NULL
// - listaDestino->n >= 0 && listaOrigen->n >= 0 (el tamaño de ambas listas tiene sentido)
// - listaDestino->capacidad >= listaDestino->n (la capacidad de la listaDestino tiene sentido)
// - listaOrigen->capacidad >= listaOrigen->n (la capacidad de la listaOrigen tiene sentido)
// Complejidad temporal: O(n+m), siendo n y m los tamaños de la listaDestino y listaOrigen respectivamente
void concatenarContiguas(ListaContigua *listaDestino, const ListaContigua *listaOrigen);

// Busca la posición de un elemento en la lista, usando el método de búsqueda secuencial
// Parámetros: 
// - lista: puntero al struct que representa la lista
// - elementoABuscar: el elemento a buscar
// Retorno: posición del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
// Precondiciones:
// - lista != NULL
// - n >= 0 && capacidad >= n (n y capacidad tienen sentido)
// Complejidad temporal: O(n)
int buscarEnContigua(ListaContigua *lista, Aeropuerto elementoABuscar);









