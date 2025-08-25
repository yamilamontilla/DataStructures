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
	Nodo* raiz; // Raiz del �rbol, o NULL si el arbol est� vac�o
	int n; // Numero de nodos del arbol
} AVL;


// Construye un �rbol AVL vac�o
// Retorno: puntero al struct del nuevo �rbol AVL creado
// Complejidad temporal: O(1)
AVL* construirAVL();


// Busca recursivamente un elemento en un sub�rbol AVL
// Par�metros:
// - raizSubarbol: puntero al nodo ra�z del sub�rbol en donde buscar
// - elementoABuscar: elemento que queremos encontrar
// Retorno: puntero al nodo que contiene el elementoABuscar si lo encuentra, o, 
//          si no lo encuentra, puntero al nodo que ser�a su padre si lo quisi�ramos insertar
// Precondiciones: 
// - raizSubarbol != NULL
// Complejidad temporal: O(lgn), siendo n el n�mero de nodos del sub�rbol
Nodo* buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar);


// Busca un elemento en un arbol AVL
// Par�metros:
// - arbol: puntero al struct que representa al �rbol AVL
// - elementoABuscar: elemento que queremos encontrar
// Retorno: 1 (verdadero) si se encuentra en el �rbol, 0 (falso) si no
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// Complejidad temporal: O(lgn)
int buscar(AVL* arbol, int elementoABuscar);


// Imprime un subarbol AVL por consola en forma de esquema tabulado, 
// sangrando los hijos con una tabulaci�n m�s. Esta pensado para ser recursivo
// Par�metros:
// - raizSubarbol: nodo ra�z del subarbol que queremos imprimir
// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendr�n una tabulaci�n m�s
// - orientacion indica si el nodo ra�z del subarbol es un hijo izquierdo de su padre (-1) o es derecho (+1) o no tiene padre (0)
// Precondiciones: 
// - subarbol != NULL
// - numeroTabulaciones>=0
// - orientacion == 1 || orientacion == -1 || orientacion == 0
// Complejidad temporal: O(n), siendo n el n�mero de nodos del sub�rbol
void imprimirRecursivo(Nodo* raizSubarbol, int numeroTabulaciones, int orientacion);


// Imprime un AVL en forma de esquema tabulado, indicando si cada nodo es hijo izquiero o derecho de su padre
// Par�metros: 
// - arbol: puntero al struct que representa al �rbol AVL
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// Complejidad temporal: O(n)
void imprimir(AVL* arbol);


// Elimina recursivamente los nodos de un subarbol AVL
// Par�metros: 
// - arbol: puntero al struct que representa al �rbol AVL completo
// - raizSubarbol: puntero al nodo ra�z del subarbol a eliminar
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// - raizSubarbol != NULL
// Complejidad temporal: O(n), siendo n el n�mero de nodos del sub�rbol
void eliminarSubarbol(AVL* arbol, Nodo* raizSubarbol);


// Destruye el �rbol AVL, liberando la memoria de todos los nodos
// Par�metros: 
// - arbol: puntero al struct que representa al �rbol AVL
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// Complejidad temporal: O(n)
void destruirAVL(AVL* arbol);


// Actualiza la altura y el factor de equilibrio de un nodo de un �rbol AVL
// Par�metro: puntero al nodo cuya altura y factor de equilibrio queremos actualizar
// Precondici�n: nodo != NULL
// Complejidad temporal: O(1)
void actualizarAlturaYFactorDeEquilibrio(Nodo* nodo);


// Establece un nuevo nodo como hijo derecho o izquierdo de otro (el padre)
// Par�metros:
// - padre: puntero al nodo padre cuyo hijo estableceremos
// - nuevoHijo: puntero al nodo que ser� el nuevo hijo del padre
// - lado: 0 si queremos que el nuevoHijo sea hijo derecho del padre, � 1 si queremos que sea izquierdo
// Precondiciones:
// - padre != NULL
// - lado es 0 � 1
// Complejidad temporal: O(1)
void setHijo(Nodo* padre, Nodo* nuevoHijo, int lado);


// Hace que el padre de antiguoHijo apunte en su lugar a nuevoHijo
// Par�metros:
// - arbol: puntero al struct que representa al �rbol AVL
// - antiguoHijo: nodo cuyo padre dejar� de apuntarle
// - nuevoHijo: queremos que el padre de antiguoHijo pase a apuntar a nuevoHijo
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// - antiguoHijo != NULL
// - nuevoHijo != NULL
// Complejidad temporal: O(1)
void cambiarHijo(AVL* arbol, Nodo* antiguoHijo, Nodo* nuevoHijo);


// Implementa, en un subarbol AVL, una rotaci�n simple a la izquierda
// Par�metros:
// - arbol: puntero al struct que representa al �rbol AVL
// - raizSubarbol: ra�z del subarbol en donde se har� la rotaci�n
// Retorno: puntero a la nueva raiz del subarbol
// Precondiciones:
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// - El nodo ra�z existe y tiene un factor de equilibrio de 2
// - Su hijo derecho existe y tiene un factor de equilibrio de 1
// Complejidad temporal: O(1)
Nodo* rotarSimpleIzquierda(AVL *arbol, Nodo* raizSubarbol);


// Implementa, en un subarbol AVL, una rotaci�n simple a la derecha
// Par�metros:
// - arbol: puntero al struct que representa al �rbol AVL
// - raizSubarbol: ra�z del subarbol en donde se har� la rotaci�n
// Retorno: puntero a la nueva raiz del subarbol
// Precondiciones:
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// - El nodo ra�z existe y tiene un factor de equilibrio de -2
// - Su hijo izquierdo existe y tiene un factor de equilibrio de -1
// Complejidad temporal: O(1)
Nodo* rotarSimpleDerecha(AVL *arbol, Nodo* raizSubarbol);


// Implementa, en un subarbol AVL, una rotaci�n compuesta derecha-izquierda
// Par�metros:
// - arbol: puntero al struct que representa al �rbol AVL
// - raizSubarbol: ra�z del subarbol en donde se har� la rotaci�n
// Retorno: puntero a la nueva raiz del subarbol
// Precondiciones:
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// - El nodo ra�z existe y tiene un factor de equilibrio de 2
// - Su hijo derecho existe y tiene un factor de equilibrio de -1
// Complejidad temporal: O(1)
Nodo* rotarCompuestaDerechaIzquierda(AVL *arbol, Nodo* raizSubarbol);


// Implementa, en un subarbol AVL, una rotaci�n compuesta izquierda-derecha
// Par�metros:
// - arbol: puntero al struct que representa al �rbol AVL
// - raizSubarbol: ra�z del subarbol en donde se har� la rotaci�n
// Retorno: puntero a la nueva raiz del subarbol
// Precondiciones:
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// - El nodo ra�z existe y tiene un factor de equilibrio de -2
// - Su hijo izquierdo existe y tiene un factor de equilibrio de 1
// Complejidad temporal: O(1)
Nodo* rotarCompuestaIzquierdaDerecha(AVL *arbol, Nodo* raizSubarbol);


// Inserta un elemento como una hoja, como si fuera un arbol binario de busqueda no AVL
// Por lo tanto, una vez ejecutado este m�todo, el �rbol puede que ya no sea AVL
// Par�metros:
// - arbol: puntero al struct que representa al �rbol AVL
// - nuevoElemento: nuevo elemento a insertar. Lo coloca como una hoja
// Retorno: puntero al nodo insertado
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// - nuevoElemento no exist�a previamente en el �rbol (no se permiten duplicados)
// Complejidad temporal: O(lgn)
Nodo* insertarHoja(AVL* arbol, int nuevoElemento);


// Reequilibra el arbol AVL despues de insertar una hoja, empezando por dicha hoja y ascendiendo hasta la raiz
// Par�metros:
// - arbol: puntero al struct que representa al �rbol AVL
// - hoja: puntero al nodo hoja desde el que empezamos a subir
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// - hoja != NULL
// Complejidad temporal: O(logn)
void reequilibrar(AVL *arbol, Nodo* hoja);


// Inserta un elemento en un arbol AVL
// Par�metros: 
// - arbol: puntero al struct que representa al �rbol AVL
// - nuevoElemento: nuevo elemento a insertar. Lo coloca en su sitio adecuado
// Precondiciones: 
// - arbol != NULL && arbol->n >= 0 (�rbol tiene sentido)
// - nuevoElemento no exist�a previamente en el �rbol (no se permiten duplicados)
// Complejidad temporal: O(lgn)
void insertar(AVL* arbol, int nuevoElemento);
