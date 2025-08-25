#pragma once
#include "ListaContigua.h"

// Lista que siempre se mantiene ordenada de menor a mayor

// Comprueba si una lista contigua est� ordenada de menor a mayor
// Par�metro: puntero a la lista a comprobar
// Retorno: 1 si est� ordenada, 0 si no lo est�
// Precondiciones:
// - lista != NULL (la lista existe)
// - n >= 0 && capacidad >= n (n y capacidad tienen sentido)
// Complejidad temporal: O(n)
int isOrdenada(ListaContigua* lista);

// Busca, mediante la b�squeda binaria recursiva, un elemento en una sublista de la lista actual. 
// Si no existe, devuelve la posici�n en que deber�a ser insertado para mantener la lista ordenada
// Par�metros:
// - lista: puntero a la lista contigua ordenada
// - valorABuscar: el elemento que se quiere buscar entre posicionInicioSublista y 
//   posicionInicioSublista+(nSublista-1) (ambos inclusive)
// - posicionInicioSublista: posicion de inicio de la sublista en donde buscar, dentro de la lista actual
// - nSublista: n�mero de elementos de la sublista que empieza en posicionInicioSublista
// Retorno: si lo encuentra, devuelve su posici�n en la lista. Si no lo encuentra, devuelve la 
//   posicion en que deber�a ser insertado para mantener ordenada a la lista. Si la sublista tiene
//   tama�o 0, devuelve directamente la posici�n de inicio de la sublista, 
// Precondiciones (posicionFinSublista = posicionInicioSublista+(nSublista-1)):
// - lista != NULL (la lista existe)
// - n >= 0 && capacidad >= n (n y capacidad tienen sentido)
// - la lista est� ordenada de menor a mayor
// - nSublista >= 0 (si es 0, el elemento obviamente no est� en la sublista y se podr�a insertar en posicionInicioSublista)
// - posicionInicioSublista >= 0
// - Si nSublista es 0, el elemento no est� y se devuelve la posicion en donde se insertar�a (que ser� posicionInicioSublista), por tanto:
//   - posicionInicioSublista <= n (podriamos llegar a insertar en posicion n)
// - Si nSublista > 0, entonces:
//   - posicionInicioSublista < n (no puede salirse de rango)
//   - nSublista <= (n-1)-posicionInicioSublista+1 (el tama�o m�ximo de la sublista tiene que ser l�gico)
// Complejidad temporal: O(logn), siendo n el tama�o de la sublista  
int ejecutarBusquedaBinaria(ListaContigua *lista, int valorABuscar, int posicionInicioSublista, int nSublista);

// Busca la posici�n de un elemento en una lista ordenada, usando el m�todo de b�squeda binaria
// Par�metros: 
// - lista: puntero al struct que representa la lista
// - elementoABuscar: el elemento a buscar
// Retorno: posici�n del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
// Precondiciones:
// - lista != NULL
// - n >= 0 && capacidad >= n (n y capacidad tienen sentido)
// - la lista est� ordenada de menor a mayor
// Complejidad temporal: O(logn)
int buscarEnOrdenada(ListaContigua* lista, int elementoABuscar);

// Inserta un elemento en la posicion adecuada para que la lista siga ordenada.
// El propio m�todo busca el lugar adecuado para el nuevo valor para que la lista siga siendo ordenada
// Par�metros:
// - lista: puntero al struct que representa la lista
// - nuevoValor: el nuevo elemento que queremos poner
// Precondiciones:
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// - la lista est� ordenada de menor a mayor
// Complejidad temporal: O(n) -O(logn) para buscar la posicion adecuada y O(n) para insertar el elemento ah�-
void insertarEnOrdenada(ListaContigua* lista, int nuevoValor);

// Elimina un elemento de la lista sin necesidad de dar su posici�n. Lo busca primero con b�squeda binaria
// Par�metros:
// - lista: puntero al struct que representa la lista
// - elementoAEliminar: el elemento a eliminar (el m�todo buscar� su posici�n antes de eliminarlo)
// Precondiciones:
// - lista != NULL
// - n > 0 (la lista no est� vac�a)
// - capacidad >= n (valor de "capacidad" tiene sentido)
// - la lista est� ordenada de menor a mayor
// - elementoAEliminar existe en la lista
// Complejidad temporal: O(n)
void eliminarEnOrdenada(ListaContigua* lista, int elementoAEliminar);

