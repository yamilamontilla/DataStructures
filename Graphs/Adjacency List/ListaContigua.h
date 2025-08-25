#pragma once // Esta directiva evita que se incluya por error este archivo m�s de una vez en el main

#include "Aeropuerto.h"

// Struct que representa a una lista contigua en memoria y cuya capacidad se redimensiona autom�ticamente
// de modo que el usuario no tiene que preocuparse por su capacidad
typedef struct {

	// Puntero que apuntar� a la zona de memoria en donde empieza la ListaContigua
	Aeropuerto* vector;

	// Numero actual de elementos que tiene la ListaContigua
	// Precondici�n: n>=0
	int n;

	// Capacidad actual de la ListaContigua
	// Precondici�n: capacidad >= n
	int capacidad;

} ListaContigua;

// Constructor. Crea una ListaContigua de tama�o y capacidad 0
// Retorno: puntero al nuevo struct creado
// Complejidad temporal: O(1)
ListaContigua* crearListaContigua();

// Destructor. Libera memoria
// Par�metro: puntero al struct que representa la lista
// Precondiciones: 
// - lista != NULL
// - n >= 0 && capacidad >= n (n y capacidad tienen sentido)
// Complejidad temporal: O(1)
void destruirListaContigua(ListaContigua* lista);

// Nos dice si la ListaContigua est� llena o no.
// Par�metro: puntero al struct que representa la lista
// Retorno: n�mero distinto de cero si est� llena, 0 si no est� llena
// Precondiciones: 
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// Complejidad temporal: O(1)
int isLlena(ListaContigua* lista);

// Devuelve un elemento de la ListaContigua
// Par�metros: 
// - lista: puntero al struct que representa la lista
// - posicion: la posici�n del elemento
// Retorno: el elemento encontrado en esa posici�n
// Precondiciones:
// - posicion en [0, n-1]
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// Complejidad temporal: O(1)
Aeropuerto getValorEnContigua(ListaContigua* lista, int posicion);

// Modifica un elemento de la ListaContigua
// Par�metros:
// - lista: puntero al struct que representa la lista
// - posicion: la posici�n del elemento que queremos modificar
// - nuevoValor: el nuevo valor del elemento
// Precondiciones:
// - posicion en [0, n-1]
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// Complejidad temporal: O(1)
void setValorEnContigua(ListaContigua* lista, int posicion, Aeropuerto nuevoValor);

// Ampl�a o disminuye la capacidad en un valor
// Par�metros: 
// - lista: puntero al struct que representa la lista
// - incremento: cantidad a aumentar (si es positivo) o disminuir (si es negativo) la capacidad actual de la lista
// Precondiciones:
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// Complejidad temporal: O(n)
void ampliarCapacidad(ListaContigua* lista, int incremento);

// Inserta un nuevo elemento en la �ltima posici�n de la ListaContigua, 
// ampliando previamente la capacidad si es necesario
// Par�metros:
// - lista: puntero al struct que representa la lista
// - nuevoValor: el nuevo elemento que queremos poner
// Precondiciones:
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// Complejidad temporal: O(n)
void insertarAlFinal(ListaContigua* lista, Aeropuerto nuevoValor);

// Elimina el elemento de la �ltima posici�n de la ListaContigua,
// disminuyendo posteriormente la capacidad si es necesario
// Par�metro: puntero al struct que representa la lista
// Precondiciones:
// - lista != NULL
// - n > 0 (la lista no est� vac�a)
// - capacidad >= n (valor de "capacidad" tiene sentido)
// Complejidad temporal: O(1)
void eliminarAlFinal(ListaContigua* lista);

// Inserta un nuevo elemento en una posici�n de la lista, dejando primero un hueco para meterlo ah�
// Los elementos que hab�a desde la posici�n hasta el final de la ListaContigua se desplazar�n una posici�n a la derecha
// Par�metros:
// - lista: puntero al struct que representa la lista
// - posici�n: la posici�n en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
// - nuevoValor: el nuevo elemento que queremos poner
// Precondiciones:
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// - posicion en [0, n]
// Complejidad temporal: O(n)
void insertarEnContigua(ListaContigua *lista, int posicion, Aeropuerto nuevoValor);

// Elimina un elemento en una posici�n dada.
// Los elementos que hab�a desde posicion+1 hasta el final de la ListaContigua se desplazar�n una posici�n a la izquierda
// Par�metros:
// - lista: puntero al struct que representa la lista
// - posicion: la posici�n del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el �ltimo
// Precondiciones:
// - lista != NULL
// - n > 0 (la lista no est� vac�a)
// - capacidad >= n (valor de "capacidad" tiene sentido)
// - posicion en [0, n-1]
// Complejidad temporal: O(n)
void eliminarEnContigua(ListaContigua *lista, int posicion);

// Concatena una lista (lista origen) al final de otra (lista destino). 
// Cada uno de los elementos de la lista origen se copian, en orden, al final de la lista destino,
// por lo tanto la lista de origen no se ve modificada, pero la lista destino s�
// Par�metros: 
// - listaDestino: puntero al struct que representa a la lista destino
// - listaOrigen: puntero al struct que representa a la lista origen
// Precondiciones: 
// - listaDestino != NULL && listaOrigen != NULL
// - listaDestino->n >= 0 && listaOrigen->n >= 0 (el tama�o de ambas listas tiene sentido)
// - listaDestino->capacidad >= listaDestino->n (la capacidad de la listaDestino tiene sentido)
// - listaOrigen->capacidad >= listaOrigen->n (la capacidad de la listaOrigen tiene sentido)
// Complejidad temporal: O(n+m), siendo n y m los tama�os de la listaDestino y listaOrigen respectivamente
void concatenarContiguas(ListaContigua *listaDestino, const ListaContigua *listaOrigen);

// Busca la posici�n de un elemento en la lista, usando el m�todo de b�squeda secuencial
// Par�metros: 
// - lista: puntero al struct que representa la lista
// - elementoABuscar: el elemento a buscar
// Retorno: posici�n del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
// Precondiciones:
// - lista != NULL
// - n >= 0 && capacidad >= n (n y capacidad tienen sentido)
// Complejidad temporal: O(n)
int buscarEnContigua(ListaContigua *lista, Aeropuerto elementoABuscar);









