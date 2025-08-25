#pragma once
#include "ListaContigua.h"


// Imprime un subarbol montículo por pantalla en forma de esquema, sangrando los hijos con tabulaciones. Es recursivo.
// Si el subarbol no tiene elementos, no imprime nada
// Parámetros:
// - vector: lista contigua que representa al montículo completo
// - raiz: posición del nodo raíz del subarbol que queremos imprimir (empezando la numeración por 1). 
//   Si ese numero de nodo no existe (que sea mayor que el numero de nodos), no se imprime nada
// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendrán una tabulación más
// Precondiciones: 
// - vector != NULL && n >= 0 && capacidad >= n (lista contigua es coherente)
// - raiz >= 1
// - numeroTabulaciones >= 0
// Complejidad temporal: O(n), siendo n el número de nodos del subárbol que empieza en raizSubarbol
void imprimirRecursivo(ListaContigua *vector, int raizSubarbol, int numeroTabulaciones);


// Imprime el montículo en forma de esquema con tabulaciones. Si no tiene elementos, no imprime nada.
// Parámetros:
// - vector: lista contigua que representa al montículo
// Precondiciones: 
// - vector != NULL && n >= 0 && capacidad >= n (lista contigua es coherente)
// Complejidad temporal: O(n) 
void imprimir(ListaContigua* vector);


// Comprueba recursivamente si el subárbol que empieza en el nodo dado como argumento es un monticulo
// Si el subárbol es vacío (la posición de la raiz es mayor que n), sí es un montículo
// Parámetros:
// - vector: lista contigua que representa al montículo completo
// - raizSubarbol: posición del elemento que es la raiz del subarbol que queremos comprobar
// Retorno: 1 si el subárbol es un montículo, 0 si no lo es
// Precondiciones: 
// - vector != NULL && n >= 0 && capacidad >= n (lista contigua es coherente)
// - raizSubarbol >= 1
// Complejidad temporal: O(n)
int isMonticulo(ListaContigua *vector, int raizSubarbol);


// Inserta un nuevo elemento en el monticulo
// Parámetros:
// - vector: lista contigua que representa al montículo completo
// - nuevoElemento: nuevo elemento a insertar
// Precondiciones: 
// - vector != NULL && n >= 0 && capacidad >= n (lista contigua es coherente)
// Postcondicion: el árbol con el nuevoElemento ya insertado sigue siendo un montículo
// Complejidad temporal: O(logn)
void insertarEnMonticulo(ListaContigua *vector, int nuevoElemento);





