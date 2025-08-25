#pragma once


// Nodo del AVL
struct _Nodo {
	int contenido; // Contenido del nodo (el elemento)
	struct _Nodo* padre; // Apunta al padre, o NULL si no tiene
	struct _Nodo* hijoIzquierdo; // Apunta al hijo izquierdo, o NULL si no tiene hijo izquierdo
	struct _Nodo* hijoDerecho; // Apunta al hijo derecho, o NULL si no tiene hijo derecho
	int altura; // Altura actual del nodo
	int factorEquilibrio; // Factor de equilibrio actual del nodo
};

typedef struct _Nodo Nodo;


// Estructura que representa al AVL. No se permiten duplicados
typedef struct {
	Nodo* raiz; // Raiz del árbol, o NULL si el arbol está vacío
	int n; // Numero de nodos del arbol
} AVL;


// Construye un árbol AVL vacío
// Retorno: puntero al struct del nuevo árbol AVL creado
// Complejidad temporal: O(1)
AVL* construirAVL();


// Busca recursivamente un elemento en un subárbol AVL
// Parámetros:
// - raizSubarbol: puntero al nodo raíz del subárbol en donde buscar
// - elementoABuscar: elemento que queremos encontrar
// Retorno: puntero al nodo que contiene el elementoABuscar si lo encuentra, o, 
//          si no lo encuentra, puntero al nodo que sería su padre si lo quisiéramos insertar
// Precondiciones: 
// - raizSubarbol != NULL
// Complejidad temporal: O(lgn), siendo n el número de nodos del subárbol
Nodo* buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar);


// Busca un elemento en un arbol AVL
// Parámetros:
// - arbol: puntero al struct que representa al árbol AVL
// - elementoABuscar: elemento que queremos encontrar
// Retorno: 1 (verdadero) si se encuentra en el árbol, 0 (falso) si no
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// Complejidad temporal: O(lgn)
int buscar(AVL* arbol, int elementoABuscar);


// Imprime un subarbol AVL por consola en forma de esquema tabulado, 
// sangrando los hijos con una tabulación más. Esta pensado para ser recursivo
// Parámetros:
// - raizSubarbol: nodo raíz del subarbol que queremos imprimir
// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendrán una tabulación más
// - orientacion indica si el nodo raíz del subarbol es un hijo izquierdo de su padre (-1) o es derecho (+1) o no tiene padre (0)
// Precondiciones: 
// - subarbol != NULL
// - numeroTabulaciones>=0
// - orientacion == 1 || orientacion == -1 || orientacion == 0
// Complejidad temporal: O(n), siendo n el número de nodos del subárbol
void imprimirRecursivo(Nodo* raizSubarbol, int numeroTabulaciones, int orientacion);


// Imprime un AVL en forma de esquema tabulado, indicando si cada nodo es hijo izquiero o derecho de su padre
// Parámetros: 
// - arbol: puntero al struct que representa al árbol AVL
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// Complejidad temporal: O(n)
void imprimir(AVL* arbol);


// Elimina recursivamente los nodos de un subarbol AVL
// Parámetros: 
// - arbol: puntero al struct que representa al árbol AVL completo
// - raizSubarbol: puntero al nodo raíz del subarbol a eliminar
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// - raizSubarbol != NULL
// Complejidad temporal: O(n), siendo n el número de nodos del subárbol
void eliminarSubarbol(AVL* arbol, Nodo* raizSubarbol);


// Destruye el árbol AVL, liberando la memoria de todos los nodos
// Parámetros: 
// - arbol: puntero al struct que representa al árbol AVL
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// Complejidad temporal: O(n)
void destruirAVL(AVL* arbol);


// Actualiza la altura y el factor de equilibrio de un nodo de un árbol AVL
// Parámetro: puntero al nodo cuya altura y factor de equilibrio queremos actualizar
// Precondición: nodo != NULL
// Complejidad temporal: O(1)
void actualizarAlturaYFactorDeEquilibrio(Nodo* nodo);


// Establece un nuevo nodo como hijo derecho o izquierdo de otro (el padre)
// Parámetros:
// - padre: puntero al nodo padre cuyo hijo estableceremos
// - nuevoHijo: puntero al nodo que será el nuevo hijo del padre
// - lado: 0 si queremos que el nuevoHijo sea hijo derecho del padre, ó 1 si queremos que sea izquierdo
// Precondiciones:
// - padre != NULL
// - lado es 0 ó 1
// Complejidad temporal: O(1)
void setHijo(Nodo* padre, Nodo* nuevoHijo, int lado);


// Hace que el padre de antiguoHijo apunte en su lugar a nuevoHijo
// Parámetros:
// - arbol: puntero al struct que representa al árbol AVL
// - antiguoHijo: nodo cuyo padre dejará de apuntarle
// - nuevoHijo: queremos que el padre de antiguoHijo pase a apuntar a nuevoHijo
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// - antiguoHijo != NULL
// - nuevoHijo != NULL
// Complejidad temporal: O(1)
void cambiarHijo(AVL* arbol, Nodo* antiguoHijo, Nodo* nuevoHijo);


// Implementa, en un subarbol AVL, una rotación simple a la izquierda
// Parámetros:
// - arbol: puntero al struct que representa al árbol AVL
// - raizSubarbol: raíz del subarbol en donde se hará la rotación
// Retorno: puntero a la nueva raiz del subarbol
// Precondiciones:
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// - El nodo raíz existe y tiene un factor de equilibrio de 2
// - Su hijo derecho existe y tiene un factor de equilibrio de 1
// Complejidad temporal: O(1)
Nodo* rotarSimpleIzquierda(AVL *arbol, Nodo* raizSubarbol);


// Implementa, en un subarbol AVL, una rotación simple a la derecha
// Parámetros:
// - arbol: puntero al struct que representa al árbol AVL
// - raizSubarbol: raíz del subarbol en donde se hará la rotación
// Retorno: puntero a la nueva raiz del subarbol
// Precondiciones:
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// - El nodo raíz existe y tiene un factor de equilibrio de -2
// - Su hijo izquierdo existe y tiene un factor de equilibrio de -1
// Complejidad temporal: O(1)
Nodo* rotarSimpleDerecha(AVL *arbol, Nodo* raizSubarbol);


// Implementa, en un subarbol AVL, una rotación compuesta derecha-izquierda
// Parámetros:
// - arbol: puntero al struct que representa al árbol AVL
// - raizSubarbol: raíz del subarbol en donde se hará la rotación
// Retorno: puntero a la nueva raiz del subarbol
// Precondiciones:
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// - El nodo raíz existe y tiene un factor de equilibrio de 2
// - Su hijo derecho existe y tiene un factor de equilibrio de -1
// Complejidad temporal: O(1)
Nodo* rotarCompuestaDerechaIzquierda(AVL *arbol, Nodo* raizSubarbol);


// Implementa, en un subarbol AVL, una rotación compuesta izquierda-derecha
// Parámetros:
// - arbol: puntero al struct que representa al árbol AVL
// - raizSubarbol: raíz del subarbol en donde se hará la rotación
// Retorno: puntero a la nueva raiz del subarbol
// Precondiciones:
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// - El nodo raíz existe y tiene un factor de equilibrio de -2
// - Su hijo izquierdo existe y tiene un factor de equilibrio de 1
// Complejidad temporal: O(1)
Nodo* rotarCompuestaIzquierdaDerecha(AVL *arbol, Nodo* raizSubarbol);


// Inserta un elemento como una hoja, como si fuera un arbol binario de busqueda no AVL
// Por lo tanto, una vez ejecutado este método, el árbol puede que ya no sea AVL
// Parámetros:
// - arbol: puntero al struct que representa al árbol AVL
// - nuevoElemento: nuevo elemento a insertar. Lo coloca como una hoja
// Retorno: puntero al nodo insertado
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// - nuevoElemento no existía previamente en el árbol (no se permiten duplicados)
// Complejidad temporal: O(lgn)
Nodo* insertarHoja(AVL* arbol, int nuevoElemento);


// Reequilibra el arbol AVL despues de insertar una hoja, empezando por dicha hoja y ascendiendo hasta la raiz
// Parámetros:
// - arbol: puntero al struct que representa al árbol AVL
// - hoja: puntero al nodo hoja desde el que empezamos a subir
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// - hoja != NULL
// Complejidad temporal: O(logn)
void reequilibrar(AVL *arbol, Nodo* hoja);


// Inserta un elemento en un arbol AVL
// Parámetros: 
// - arbol: puntero al struct que representa al árbol AVL
// - nuevoElemento: nuevo elemento a insertar. Lo coloca en su sitio adecuado
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (Árbol tiene sentido)
// - nuevoElemento no existía previamente en el árbol (no se permiten duplicados)
// Complejidad temporal: O(lgn)
void insertar(AVL* arbol, int nuevoElemento);
