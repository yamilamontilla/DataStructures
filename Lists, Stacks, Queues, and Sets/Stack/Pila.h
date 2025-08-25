#pragma once
#include "ListaEnlazada.h"

// Mete un nuevo elemento en la cima de la pila
// Parámetros: 
// - lista: puntero a la lista enlazada que representa a la pila
// - nuevoElemento: nuevo elemento que copiaremos en la cima
// Precondiciones: 
// - lista != NULL && n >= 0 (la pila existe y su tamaño tiene sentido)
// Complejidad temporal: O(1)
void push(ListaEnlazada *lista, int nuevoElemento);

// Obtiene una copia del elemento que está en la cima y lo borra de ahí
// Parámetros: 
// - lista: puntero a la lista enlazada que representa a la pila
// Retorno: una copia del elemento que está en la cima
// Precondiciones: 
// - lista != NULL && n > 0 (la pila existe y no está vacía)
// Complejidad temporal: O(1)
int pop(ListaEnlazada* lista);

// Obtiene una copia del elemento que está en la cima sin borrarlo de ahí
// Parámetros: 
// - lista: puntero a la lista enlazada que representa a la pila
// Retorno: una copia del elemento que está en la cima
// Precondiciones: 
// - lista != NULL && n > 0 (la pila existe y no está vacía)
// Complejidad temporal: O(1)
int verCima(ListaEnlazada* lista);

// Comprueba si la pila está vacía
// Parámetros: 
// - lista: puntero a la lista enlazada que representa a la pila
// Retorno: 1 si está vacía, 0 si no lo está
// Precondiciones: 
// - lista != NULL && n >= 0 (la pila existe y su tamaño tiene sentido)
// Complejidad temporal: O(1)
int isVacia(ListaEnlazada* lista);





