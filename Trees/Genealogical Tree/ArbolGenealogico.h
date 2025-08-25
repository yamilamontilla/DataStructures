#pragma once


// Nodo de un �rbol
typedef struct Nodo {
	char contenido[20]; // Contenido del nodo (el elemento)
	struct Nodo* padre; // Puntero al nodo padre. NULL si no hay
	struct Nodo* primerHijo; // Puntero al primer hijo. NULL si no hay
	struct Nodo* hermanoDerecho; // Puntero al hermano derecho. NULL si no hay
} Nodo;


// Struct que representa un �rbol geneal�gico sencillo
typedef struct {
	Nodo* raiz; // Puntero al nodo ra�z del �rbol. NULL si el �rbol est� vac�o
	int n; // N�mero de elementos (y nodos) del �rbol. S�lo sirve para las precondiciones
} ArbolGenealogico;


// Obtiene el n�mero de hijos directos de un nodo
// Par�metro: nodo cuyo n�mero de hijos queremos obtener
// Retorno: n�mero de hijos del nodo
// Precondici�n: padre!=NULL
// Complejidad temporal: O(hijos), siendo hijos el n�mero de hijos del nodo pasado como par�metro
int getNumeroHijos(Nodo *padre);


// Obtiene el puntero a un hijo concreto de un nodo
// Par�metros:
// - padre: puntero al nodo cuyo hijo queremos obtener
// - posicionHijo: posici�n del hijo que queremos obtener (de 0 a hijos-1)
// Retorno: puntero al nodo hijo
// Precondiciones:
// - padre!=NULL
// - getNumeroHijos(padre)>0
// - posicionHijo pertenece a [0, getNumeroHijos(padre)-1]
// Complejidad temporal: O(hijos), siendo hijos el n�mero de hijos del nodo pasado como par�metro
Nodo *getHijo(Nodo *padre, int posicionHijo);


// Obtiene el puntero a un nodo con un determinado contenido en un sub�rbol (m�todo recursivo)
// Par�metros: 
// - raizSubarbol: nodo ra�z en donde empieza el sub�rbol (NULL si es �rbol vac�o)
// - contenido: contenido que queremos buscar en el sub�rbol
// Retorno: puntero al primer nodo encontrado con el contenido buscado, o NULL si no se encuentra ningun nodo
// Precondici�n: contenido != NULL
// Complejidad temporal: O(n), siendo n el n�mero de nodos del sub�rbol que empieza en raizSubarbol 
Nodo *buscarNodo (Nodo *raizSubarbol, char* contenido);
	

// Imprime un subarbol por pantalla en forma de esquema, sangrando los hijos con tabulaciones. Es recursivo
// Par�metros:
// - subarbol: nodo ra�z del subarbol que queremos imprimir
// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendr�n una tabulaci�n m�s
// Precondiciones: subarbol != NULL && numeroTabulaciones>=0
// Complejidad temporal: O(n), siendo n el n�mero de nodos del sub�rbol que empieza en raizSubarbol
void imprimirRecursivo (Nodo *raizSubarbol, int numeroTabulaciones);


// Elimina recursivamente los nodos de un subarbol. No toca los punteros que apuntan a la ra�z del subarbol
// Par�metro: el nodo ra�z del subarbol a eliminar
// Precondici�n: subarbol != NULL
// Complejidad temporal: O(n^2), siendo n el n�mero de nodos del sub�rbol que empieza en raizSubarbol
void eliminarSubarbol (Nodo *subarbol);


// Crea un �rbol de un solo nodo (su ra�z)
// Par�metro: el contenido de la ra�z
// Retorno: puntero al struct del nuevo �rbol construido
// Precondici�n: nombre != NULL
// Complejidad temporal: O(1)
ArbolGenealogico *construirArbolGenealogico(char* nombre);


// Inserta un nuevo nombre en el �rbol geneal�gico, como �ltimo hijo de un nodo indicado en el par�metro
// Par�metros:
// - arbol: puntero al �rbol geneal�gico
// - nuevoNombre: nombre que queremos insertar
// - nombrePadre: padre del nombre que queremos insertar. Ser� su �ltimo hijo
// Precondiciones: 
// - arbol != NULL && n >= 0 (el �rbol tiene sentido)
// - El �rbol no est� vac�o
// - nuevoNombre != NULL && nombrePadre != NULL
// - nombrePadre existe en el �rbol
// Complejidad temporal: O(n) 
void insertarNombre (ArbolGenealogico *arbol, char* nuevoNombre, char* nombrePadre);


// Imprime el �rbol en forma de esquema con tabulaciones
// Par�metros:
// - arbol: puntero al �rbol geneal�gico
// Precondiciones: 
// - arbol != NULL && n >= 0 (el �rbol tiene sentido)
// - El �rbol no est� vac�o
// Complejidad temporal: O(n) 
void imprimir(ArbolGenealogico *arbol);


// Destructor. Destruye toda la memoria ocupada por los nodos del �rbol
// Par�metros:
// - arbol: puntero al �rbol geneal�gico
// Precondiciones: 
// - arbol != NULL && n >= 0 (el �rbol tiene sentido)
// Complejidad temporal: O(n) 
void destruirArbolGenealogico(ArbolGenealogico *arbol);


