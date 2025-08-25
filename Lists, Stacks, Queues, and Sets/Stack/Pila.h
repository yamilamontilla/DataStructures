#pragma once
#include "ListaEnlazada.h"

// Mete un nuevo elemento en la cima de la pila
// Par�metros: 
// - lista: puntero a la lista enlazada que representa a la pila
// - nuevoElemento: nuevo elemento que copiaremos en la cima
// Precondiciones: 
// - lista != NULL && n >= 0 (la pila existe y su tama�o tiene sentido)
// Complejidad temporal: O(1)
void push(ListaEnlazada *lista, int nuevoElemento);

// Obtiene una copia del elemento que est� en la cima y lo borra de ah�
// Par�metros: 
// - lista: puntero a la lista enlazada que representa a la pila
// Retorno: una copia del elemento que est� en la cima
// Precondiciones: 
// - lista != NULL && n > 0 (la pila existe y no est� vac�a)
// Complejidad temporal: O(1)
int pop(ListaEnlazada* lista);

// Obtiene una copia del elemento que est� en la cima sin borrarlo de ah�
// Par�metros: 
// - lista: puntero a la lista enlazada que representa a la pila
// Retorno: una copia del elemento que est� en la cima
// Precondiciones: 
// - lista != NULL && n > 0 (la pila existe y no est� vac�a)
// Complejidad temporal: O(1)
int verCima(ListaEnlazada* lista);

// Comprueba si la pila est� vac�a
// Par�metros: 
// - lista: puntero a la lista enlazada que representa a la pila
// Retorno: 1 si est� vac�a, 0 si no lo est�
// Precondiciones: 
// - lista != NULL && n >= 0 (la pila existe y su tama�o tiene sentido)
// Complejidad temporal: O(1)
int isVacia(ListaEnlazada* lista);





