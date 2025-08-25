#pragma once


// Nodo del árbol binario de búsqueda
struct _Nodo {
	int contenido; // Contenido del nodo (el elemento)
	struct _Nodo* padre; // Apunta al padre, o NULL si no tiene
	struct _Nodo* hijoIzquierdo; // Apunta al hijo izquierdo, o NULL si no tiene hijo izquierdo
	struct _Nodo* hijoDerecho; // Apunta al hijo derecho, o NULL si no tiene hijo derecho
};

typedef struct _Nodo Nodo;


// Estructura que representa al árbol binario de búsqueda. No se permiten duplicados
typedef struct {
	Nodo* raiz; // Raiz del árbol, o NULL si el arbol está vacío
	int n; // Numero de nodos del arbol
	int orientacionSiguienteEliminacion; // Orientacion (-1 si es izquierdo, 1 si es derecho) que tendrá que tener la siguiente eliminación a realizar
} ArbolBinarioDeBusqueda;


// Construye un árbol binario de búsqueda vacío
// Retorno: puntero al struct del nuevo árbol binario de búsqueda creado
// Complejidad temporal: O(1)
ArbolBinarioDeBusqueda* construirArbolBinarioDeBusqueda();


// Busca recursivamente un elemento en un subárbol binario de busqueda
// Parámetros:
// - raizSubarbol: puntero al nodo raíz del subárbol en donde buscar
// - elementoABuscar: elemento que queremos encontrar
// Retorno: puntero al nodo que contiene el elementoABuscar si lo encuentra, o, 
//          si no lo encuentra, puntero al nodo que sería su padre si lo quisiéramos insertar
// Precondiciones: 
// - raizSubarbol != NULL
// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor (n es número de nodos del subárbol)
Nodo* buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar);


// Busca un elemento en un arbol binario de busqueda
// Parámetros:
// - arbol: puntero al struct que representa al árbol binario de búsqueda
// - elementoABuscar: elemento que queremos encontrar
// Retorno: 1 (verdadero) si se encuentra en el árbol, 0 (falso) si no
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
int buscar(ArbolBinarioDeBusqueda* arbol, int elementoABuscar);


// Inserta un elemento en un arbol binario de búsqueda (siempre se insertará como hoja)
// Parámetros: 
// - arbol: puntero al struct que representa al árbol binario de búsqueda
// - nuevoElemento: nuevo elemento a insertar. Lo coloca en su sitio adecuado
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// - nuevoElemento no existía previamente en el árbol (no se permiten duplicados)
// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
void insertar(ArbolBinarioDeBusqueda* arbol, int nuevoElemento);


// Imprime un subarbol binario de búsqueda por consola en forma de esquema tabulado, 
// sangrando los hijos con una tabulación más. Esta pensado para ser recursivo
// Parámetros:
// - raizSubarbol: nodo raíz del subarbol que queremos imprimir
// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendrán una tabulación más
// - orientacion indica si el nodo raíz del subarbol es un hijo izquierdo de su padre (-1) o es derecho (+1) o no tiene padre (0)
// Precondiciones: 
// - subarbol != NULL
// - numeroTabulaciones>=0
// - orientacion == 1 || orientacion == -1 || orientacion == 0
// Complejidad temporal: O(n), tanto con la mejor topología (T(n)=c+2T(n/2)) como con la peor (T(n)=c+T(n-1))
//                       (n es número de nodos del subárbol)
void imprimirRecursivo(Nodo* raizSubarbol, int numeroTabulaciones, int orientacion);


// Imprime el árbol en forma de esquema tabulado, indicando si cada nodo es hijo izquiero o derecho de su padre
// Parámetros: 
// - arbol: puntero al struct que representa al árbol binario de búsqueda
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// Complejidad temporal: O(n), tanto con la mejor topología como con la peor
void imprimir(ArbolBinarioDeBusqueda* arbol);


// Elimina recursivamente los nodos de un subarbol binario de búsqueda
// Parámetros: 
// - arbol: puntero al struct que representa al árbol binario de búsqueda completo
// - raizSubarbol: puntero al nodo raíz del subarbol a eliminar
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// - raizSubarbol != NULL
// Complejidad temporal: O(n), siendo n el número de nodos del subárbol, tanto con la mejor topología como con la peor
void eliminarSubarbol(ArbolBinarioDeBusqueda* arbol, Nodo* raizSubarbol);


// Destruye el árbol, liberando la memoria de todos los nodos
// Parámetros: 
// - arbol: puntero al struct que representa al árbol binario de búsqueda
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// Complejidad temporal: O(n), tanto con la mejor topología como con la peor
void destruirArbolBinarioDeBusqueda(ArbolBinarioDeBusqueda* arbol);


// Buscar recursivamente el maximo de un subarbol
// Parámetro: puntero a la raiz del subarbol en donde buscar
// Retorno: puntero al nodo que contiene el máximo
// Precondicion: raizSubarbol != NULL
// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor (n número de nodos del subárbol)
Nodo* buscarMaximo(Nodo* raizSubarbol);


// Buscar recursivamente el minimo de un subarbol
// Parámetro: puntero a la raiz del subarbol en donde buscar
// Retorno: puntero al nodo que contiene el minimo
// Precondicion: raizSubarbol != NULL
// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor (n número de nodos del subárbol)
Nodo* buscarMinimo(Nodo* raizSubarbol);


// Elimina el nodo pasado como parametro. Lo sustituye por un descendiente suyo (recursivamente)
// Parámetros: 
// - arbol: puntero al struct que representa al árbol binario de búsqueda
// - nodoParaEliminar: puntero al nodo que queremos eliminar
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// - nodoParaEliminar != NULL
// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
//                       (siendo n número de nodos del subarbol que empieza en nodoParaEliminar)
void eliminarNodo(ArbolBinarioDeBusqueda *arbol, Nodo* nodoParaEliminar);


// Elimina el primer nodo que se encuentre con un elemento dado
// Parámetros: 
// - arbol: puntero al struct que representa al árbol binario de búsqueda
// - elementoAEliminar: elemento a eliminar
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// - elementoAEliminar existe en el árbol
// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
void eliminar(ArbolBinarioDeBusqueda *arbol, int elementoAEliminar);
