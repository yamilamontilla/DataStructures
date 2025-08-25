#pragma once


// Nodo de un árbol
typedef struct Nodo {
	char contenido[20]; // Contenido del nodo (el elemento)
	struct Nodo* padre; // Puntero al nodo padre. NULL si no hay
	struct Nodo* primerHijo; // Puntero al primer hijo. NULL si no hay
	struct Nodo* hermanoDerecho; // Puntero al hermano derecho. NULL si no hay
} Nodo;


// Struct que representa un árbol genealógico sencillo
typedef struct {
	Nodo* raiz; // Puntero al nodo raíz del árbol. NULL si el árbol está vacío
	int n; // Número de elementos (y nodos) del árbol. Sólo sirve para las precondiciones
} ArbolGenealogico;


// Obtiene el número de hijos directos de un nodo
// Parámetro: nodo cuyo número de hijos queremos obtener
// Retorno: número de hijos del nodo
// Precondición: padre!=NULL
// Complejidad temporal: O(hijos), siendo hijos el número de hijos del nodo pasado como parámetro
int getNumeroHijos(Nodo *padre);


// Obtiene el puntero a un hijo concreto de un nodo
// Parámetros:
// - padre: puntero al nodo cuyo hijo queremos obtener
// - posicionHijo: posición del hijo que queremos obtener (de 0 a hijos-1)
// Retorno: puntero al nodo hijo
// Precondiciones:
// - padre!=NULL
// - getNumeroHijos(padre)>0
// - posicionHijo pertenece a [0, getNumeroHijos(padre)-1]
// Complejidad temporal: O(hijos), siendo hijos el número de hijos del nodo pasado como parámetro
Nodo *getHijo(Nodo *padre, int posicionHijo);


// Obtiene el puntero a un nodo con un determinado contenido en un subárbol (método recursivo)
// Parámetros: 
// - raizSubarbol: nodo raíz en donde empieza el subárbol (NULL si es árbol vacío)
// - contenido: contenido que queremos buscar en el subárbol
// Retorno: puntero al primer nodo encontrado con el contenido buscado, o NULL si no se encuentra ningun nodo
// Precondición: contenido != NULL
// Complejidad temporal: O(n), siendo n el número de nodos del subárbol que empieza en raizSubarbol 
Nodo *buscarNodo (Nodo *raizSubarbol, char* contenido);
	

// Imprime un subarbol por pantalla en forma de esquema, sangrando los hijos con tabulaciones. Es recursivo
// Parámetros:
// - subarbol: nodo raíz del subarbol que queremos imprimir
// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendrán una tabulación más
// Precondiciones: subarbol != NULL && numeroTabulaciones>=0
// Complejidad temporal: O(n), siendo n el número de nodos del subárbol que empieza en raizSubarbol
void imprimirRecursivo (Nodo *raizSubarbol, int numeroTabulaciones);


// Elimina recursivamente los nodos de un subarbol. No toca los punteros que apuntan a la raíz del subarbol
// Parámetro: el nodo raíz del subarbol a eliminar
// Precondición: subarbol != NULL
// Complejidad temporal: O(n^2), siendo n el número de nodos del subárbol que empieza en raizSubarbol
void eliminarSubarbol (Nodo *subarbol);


// Crea un árbol de un solo nodo (su raíz)
// Parámetro: el contenido de la raíz
// Retorno: puntero al struct del nuevo árbol construido
// Precondición: nombre != NULL
// Complejidad temporal: O(1)
ArbolGenealogico *construirArbolGenealogico(char* nombre);


// Inserta un nuevo nombre en el árbol genealógico, como último hijo de un nodo indicado en el parámetro
// Parámetros:
// - arbol: puntero al árbol genealógico
// - nuevoNombre: nombre que queremos insertar
// - nombrePadre: padre del nombre que queremos insertar. Será su último hijo
// Precondiciones: 
// - arbol != NULL && n >= 0 (el árbol tiene sentido)
// - El árbol no está vacío
// - nuevoNombre != NULL && nombrePadre != NULL
// - nombrePadre existe en el árbol
// Complejidad temporal: O(n) 
void insertarNombre (ArbolGenealogico *arbol, char* nuevoNombre, char* nombrePadre);


// Imprime el árbol en forma de esquema con tabulaciones
// Parámetros:
// - arbol: puntero al árbol genealógico
// Precondiciones: 
// - arbol != NULL && n >= 0 (el árbol tiene sentido)
// - El árbol no está vacío
// Complejidad temporal: O(n) 
void imprimir(ArbolGenealogico *arbol);


// Destructor. Destruye toda la memoria ocupada por los nodos del árbol
// Parámetros:
// - arbol: puntero al árbol genealógico
// Precondiciones: 
// - arbol != NULL && n >= 0 (el árbol tiene sentido)
// Complejidad temporal: O(n) 
void destruirArbolGenealogico(ArbolGenealogico *arbol);


