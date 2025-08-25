#pragma once
#include "ListaContigua.h"


// Imprime un subarbol mont�culo por pantalla en forma de esquema, sangrando los hijos con tabulaciones. Es recursivo.
// Si el subarbol no tiene elementos, no imprime nada
// Par�metros:
// - vector: lista contigua que representa al mont�culo completo
// - raiz: posici�n del nodo ra�z del subarbol que queremos imprimir (empezando la numeraci�n por 1). 
//   Si ese numero de nodo no existe (que sea mayor que el numero de nodos), no se imprime nada
// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendr�n una tabulaci�n m�s
// Precondiciones: 
// - vector != NULL && n >= 0 && capacidad >= n (lista contigua es coherente)
// - raiz >= 1
// - numeroTabulaciones >= 0
// Complejidad temporal: O(n), siendo n el n�mero de nodos del sub�rbol que empieza en raizSubarbol
void imprimirRecursivo(ListaContigua *vector, int raizSubarbol, int numeroTabulaciones);


// Imprime el mont�culo en forma de esquema con tabulaciones. Si no tiene elementos, no imprime nada.
// Par�metros:
// - vector: lista contigua que representa al mont�culo
// Precondiciones: 
// - vector != NULL && n >= 0 && capacidad >= n (lista contigua es coherente)
// Complejidad temporal: O(n) 
void imprimir(ListaContigua* vector);


// Comprueba recursivamente si el sub�rbol que empieza en el nodo dado como argumento es un monticulo
// Si el sub�rbol es vac�o (la posici�n de la raiz es mayor que n), s� es un mont�culo
// Par�metros:
// - vector: lista contigua que representa al mont�culo completo
// - raizSubarbol: posici�n del elemento que es la raiz del subarbol que queremos comprobar
// Retorno: 1 si el sub�rbol es un mont�culo, 0 si no lo es
// Precondiciones: 
// - vector != NULL && n >= 0 && capacidad >= n (lista contigua es coherente)
// - raizSubarbol >= 1
// Complejidad temporal: O(n)
int isMonticulo(ListaContigua *vector, int raizSubarbol);


// Inserta un nuevo elemento en el monticulo
// Par�metros:
// - vector: lista contigua que representa al mont�culo completo
// - nuevoElemento: nuevo elemento a insertar
// Precondiciones: 
// - vector != NULL && n >= 0 && capacidad >= n (lista contigua es coherente)
// Postcondicion: el �rbol con el nuevoElemento ya insertado sigue siendo un mont�culo
// Complejidad temporal: O(logn)
void insertarEnMonticulo(ListaContigua *vector, int nuevoElemento);





