#pragma once
#include "ListaEnlazada.h"

// Imprime una lista enlazada por pantalla (su "n" y sus elementos), con un maximo de 20 elementos
// Parámetros:
// - lista: puntero a la lista enlazada que queremos imprimir
// Precondiciones: 
// - lista!=NULL
// - n >= 0 (el tamaño de la lista tiene sentido)
// Complejidad temporal: O(n^2). Realmente es O(1) porque como maximo imprime 20 elementos
void imprimirListaEnlazada(ListaEnlazada *lista);

