#pragma once

#include "ListaContigua.h"

// Imprime una lista contigua por pantalla (su "n", su "capacidad" y sus elementos), si es menor que 20 elementos.
// Si es mayor, imprime "demasiados elementos para mostrar"
// Par�metros:
// - lista: puntero a la lista contigua que queremos imprimir
// Precondiciones: 
// - lista!=NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// Complejidad temporal: O(n). Realmente es O(1) porque como maximo imprime 20 elementos
void imprimirListaContigua(ListaContigua *lista);

