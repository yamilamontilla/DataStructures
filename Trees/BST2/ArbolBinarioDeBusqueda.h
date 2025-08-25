#pragma once


// Nodo del �rbol binario de b�squeda
struct _Nodo {
	int contenido; // Contenido del nodo (el elemento)
	struct _Nodo* padre; // Apunta al padre, o NULL si no tiene
	struct _Nodo* hijoIzquierdo; // Apunta al hijo izquierdo, o NULL si no tiene hijo izquierdo
	struct _Nodo* hijoDerecho; // Apunta al hijo derecho, o NULL si no tiene hijo derecho
};

typedef struct _Nodo Nodo;


// Estructura que representa al �rbol binario de b�squeda. No se permiten duplicados
typedef struct {
	Nodo* raiz; // Raiz del �rbol, o NULL si el arbol est� vac�o
	int n; // Numero de nodos del arbol
	int orientacionSiguienteEliminacion; // Orientacion (-1 si es izquierdo, 1 si es derecho) que tendr� que tener la siguiente eliminaci�n a realizar
} ArbolBinarioDeBusqueda;


// Construye un �rbol binario de b�squeda vac�o
// Retorno: puntero al struct del nuevo �rbol binario de b�squeda creado
// Complejidad temporal: O(1)
ArbolBinarioDeBusqueda* construirArbolBinarioDeBusqueda();


// Busca recursivamente un elemento en un sub�rbol binario de busqueda
// Par�metros:
// - raizSubarbol: puntero al nodo ra�z del sub�rbol en donde buscar
// - elementoABuscar: elemento que queremos encontrar
// Retorno: puntero al nodo que contiene el elementoABuscar si lo encuentra, o, 
//          si no lo encuentra, puntero al nodo que ser�a su padre si lo quisi�ramos insertar
// Precondiciones: 
// - raizSubarbol != NULL
// Complejidad temporal: O(lgn) con la mejor topolog�a, O(n) con la peor (n es n�mero de nodos del sub�rbol)
Nodo* buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar);


// Busca un elemento en un arbol binario de busqueda
// Par�metros:
// - arbol: puntero al struct que representa al �rbol binario de b�squeda
// - elementoABuscar: elemento que queremos encontrar
// Retorno: 1 (verdadero) si se encuentra en el �rbol, 0 (falso) si no
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// Complejidad temporal: O(lgn) con la mejor topolog�a, O(n) con la peor
int buscar(ArbolBinarioDeBusqueda* arbol, int elementoABuscar);


// Inserta un elemento en un arbol binario de b�squeda (siempre se insertar� como hoja)
// Par�metros: 
// - arbol: puntero al struct que representa al �rbol binario de b�squeda
// - nuevoElemento: nuevo elemento a insertar. Lo coloca en su sitio adecuado
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// - nuevoElemento no exist�a previamente en el �rbol (no se permiten duplicados)
// Complejidad temporal: O(lgn) con la mejor topolog�a, O(n) con la peor
void insertar(ArbolBinarioDeBusqueda* arbol, int nuevoElemento);


// Imprime un subarbol binario de b�squeda por consola en forma de esquema tabulado, 
// sangrando los hijos con una tabulaci�n m�s. Esta pensado para ser recursivo
// Par�metros:
// - raizSubarbol: nodo ra�z del subarbol que queremos imprimir
// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendr�n una tabulaci�n m�s
// - orientacion indica si el nodo ra�z del subarbol es un hijo izquierdo de su padre (-1) o es derecho (+1) o no tiene padre (0)
// Precondiciones: 
// - subarbol != NULL
// - numeroTabulaciones>=0
// - orientacion == 1 || orientacion == -1 || orientacion == 0
// Complejidad temporal: O(n), tanto con la mejor topolog�a (T(n)=c+2T(n/2)) como con la peor (T(n)=c+T(n-1))
//                       (n es n�mero de nodos del sub�rbol)
void imprimirRecursivo(Nodo* raizSubarbol, int numeroTabulaciones, int orientacion);


// Imprime el �rbol en forma de esquema tabulado, indicando si cada nodo es hijo izquiero o derecho de su padre
// Par�metros: 
// - arbol: puntero al struct que representa al �rbol binario de b�squeda
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// Complejidad temporal: O(n), tanto con la mejor topolog�a como con la peor
void imprimir(ArbolBinarioDeBusqueda* arbol);


// Elimina recursivamente los nodos de un subarbol binario de b�squeda
// Par�metros: 
// - arbol: puntero al struct que representa al �rbol binario de b�squeda completo
// - raizSubarbol: puntero al nodo ra�z del subarbol a eliminar
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// - raizSubarbol != NULL
// Complejidad temporal: O(n), siendo n el n�mero de nodos del sub�rbol, tanto con la mejor topolog�a como con la peor
void eliminarSubarbol(ArbolBinarioDeBusqueda* arbol, Nodo* raizSubarbol);


// Destruye el �rbol, liberando la memoria de todos los nodos
// Par�metros: 
// - arbol: puntero al struct que representa al �rbol binario de b�squeda
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// Complejidad temporal: O(n), tanto con la mejor topolog�a como con la peor
void destruirArbolBinarioDeBusqueda(ArbolBinarioDeBusqueda* arbol);


// Buscar recursivamente el maximo de un subarbol
// Par�metro: puntero a la raiz del subarbol en donde buscar
// Retorno: puntero al nodo que contiene el m�ximo
// Precondicion: raizSubarbol != NULL
// Complejidad temporal: O(lgn) con la mejor topolog�a, O(n) con la peor (n n�mero de nodos del sub�rbol)
Nodo* buscarMaximo(Nodo* raizSubarbol);


// Buscar recursivamente el minimo de un subarbol
// Par�metro: puntero a la raiz del subarbol en donde buscar
// Retorno: puntero al nodo que contiene el minimo
// Precondicion: raizSubarbol != NULL
// Complejidad temporal: O(lgn) con la mejor topolog�a, O(n) con la peor (n n�mero de nodos del sub�rbol)
Nodo* buscarMinimo(Nodo* raizSubarbol);


// Elimina el nodo pasado como parametro. Lo sustituye por un descendiente suyo (recursivamente)
// Par�metros: 
// - arbol: puntero al struct que representa al �rbol binario de b�squeda
// - nodoParaEliminar: puntero al nodo que queremos eliminar
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// - nodoParaEliminar != NULL
// Complejidad temporal: O(lgn) con la mejor topolog�a, O(n) con la peor
//                       (siendo n n�mero de nodos del subarbol que empieza en nodoParaEliminar)
void eliminarNodo(ArbolBinarioDeBusqueda *arbol, Nodo* nodoParaEliminar);


// Elimina el primer nodo que se encuentre con un elemento dado
// Par�metros: 
// - arbol: puntero al struct que representa al �rbol binario de b�squeda
// - elementoAEliminar: elemento a eliminar
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// - elementoAEliminar existe en el �rbol
// Complejidad temporal: O(lgn) con la mejor topolog�a, O(n) con la peor
void eliminar(ArbolBinarioDeBusqueda *arbol, int elementoAEliminar);
