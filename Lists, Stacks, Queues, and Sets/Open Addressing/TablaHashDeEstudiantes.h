#pragma once
// Tabla hash que guarda los nombres de los estudiantes de una universidad

#include "ListaEnlazada.h"


// Struct que representa a la tabla hash en s� misma
typedef struct {
	ListaEnlazada** vector; // La tabla hash ser� un vector de punteros a listas enlazadas
	int capacidad; // Capacidad de la tabla. Se establece en el constructor y permanece invariante desde ese momento
	int n; // Tama�o actual de la tabla (numero actual de estudiantes que contiene). Puede ser mayor que la capacidad
} TablaHashDeEstudiantes;

// Struct que contiene la posicion real de un elemento en la tabla hash
typedef struct {
	int numeroDeLista; // N�mero de lista enlazada en donde est� el elemento (de 0 a capacidad-1)
	int posicionEnLista; // Posici�n del elemento en dicha lista enlazada (de 0 a n-1 en el peor caso)
} PosicionReal;


// Constructor. Construye una nueva tabla hash de estudiantes vac�a
// Par�metros: 
// - capacidad: n�mero m�ximo de estudiantes que podr� contener la tabla
// Retorno: puntero a la tabla hash reci�n creada
// Precondiciones:
// - capacidad >= 1 
// Complejidad temporal: O(capacidad) en todos los casos (porque hay que crear "capacidad" listas)
TablaHashDeEstudiantes* construirTablaHashDeEstudiantes(int capacidad);


// M�todo de hashing (nos devuelve dos posibles posiciones)
// Par�metros: 
// - tabla: puntero a la tabla hash para la cual estamos haciendo hashing
// - clave: la clave del estudiante (es su n�mero de matr�cula)
// - version: 0 � 1 seg�n el m�todo de hashing que queramos ejecutar. 
//   Si es 0, devuelve el resto de dividir la clave entre capacidad. Si es 1, devuelve su sim�trico en la tabla.
// Retorno: la posici�n donde el estudiante deber�a estar o ponerse en la tabla hash
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 (tabla es coherente)
// - clave >= 0 (la clave es un n�mero natural)
// - version es 0 � 1
// Complejidad temporal en todos los casos: O(1)
int obtenerPosicionIdeal(TablaHashDeEstudiantes* tabla, int clave, int version);


// M�todo que obtiene el puntero al nodo que contiene un estudiante en la tabla, o NULL si no est�
// - tabla: puntero a la tabla hash 
// - clave: matr�cula del estudiante
// Retorno: estructura "PosicionReal" con dos campos que nos dicen la posici�n real de un elemento: 
//          - numeroDeLista: n�mero de lista enlazada en donde est� el elemento (de 0 a capacidad-1)
//          - posicionEnLista: Posici�n del elemento en dicha lista enlazada (de 0 a n-1 en el peor caso)
//          Si el elemento no est� en la tabla hash, se devuelve un -1 en ambos campos
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 (tabla es coherente)
// - clave >= 0 (la clave es un n�mero natural)
// Complejidad temporal: O(1) mejor caso, y O(n) peor caso
PosicionReal obtenerPosicionReal(TablaHashDeEstudiantes* tabla, int clave);

// Comprueba si un estudiante est� o no en la tabla hash
// Par�metros: 
// - tabla: puntero a la tabla hash 
// - clave: matr�cula del estudiante que queremos comprobar si est� o no
// Retorno: 1 si est�, 0 si no
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 (tabla es coherente)
// - clave >= 0 (la clave es un n�mero natural)
// Complejidad temporal: O(1) en mejor caso, O(n) en peor caso
int existeEstudiante(TablaHashDeEstudiantes* tabla, int clave);


// Obtiene un estudiante (su nombre) a partir de su clave (su matr�cula)
// Par�metros: 
// - tabla: puntero a la tabla hash 
// - clave: matr�cula del estudiante 
// Retorno: puntero a la zona de memoria en donde se guarda el nombre del estudiante
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 (tabla es coherente)
// - clave >= 0 (la clave es un n�mero natural)
// - el estudiante debe estar en la tabla hash
// Complejidad temporal: O(1) mejor caso, y O(n) peor caso
char* getEstudiante(TablaHashDeEstudiantes* tabla, int clave);


// Inserta un estudiante en la tabla
// Par�metros: 
// - tabla: puntero a la tabla hash 
// - clave: el n�mero de matr�cula del nuevo estudiante
// - estudiante: el nombre del nuevo estudiante
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 (tabla es coherente)
// - clave >= 0 (la clave es un n�mero natural)
// - La clave del estudiante a introducir no exist�a previamente en la tabla
// Complejidad temporal: O(1) en todos los casos
void introducirEstudiante(TablaHashDeEstudiantes* tabla, int clave, char* nombreEstudiante);


// Elimina un estudiante de la tabla
// Par�metros: 
// - tabla: puntero a la tabla hash 
// - clave: el n�mero de matr�cula del estudiante a eliminar
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 (tabla es coherente)
// - clave >= 0 (la clave es un n�mero natural)
// - el estudiante debe estar previamente en la tabla hash
// Complejidad temporal: O(1) en mejor caso, O(n) en peor caso
void eliminarEstudiante(TablaHashDeEstudiantes* tabla, int clave);


// Imprime toda la tabla hash, incluyendo las casillas vac�as. 
// OJO: Viola el principio de separaci�n entre interfaz y modelo
// Par�metros: 
// - tabla: puntero a la tabla hash 
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 (tabla es coherente)
// Complejidad temporal:
// - O(capacidad) en el mejor caso (tabla vacia)
// - O(n+capacidad) en el peor (los n elementos en una �nica posici�n de la tabla)
void imprimir(TablaHashDeEstudiantes* tabla);


// Destructor. Destruye toda la memoria ocupada por la tabla hash
// Par�metros: 
// - tabla: puntero a la tabla hash 
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 (tabla es coherente)
// Complejidad temporal:
// - O(capacidad) en el mejor caso (tabla vacia)
// - O(n+capacidad) en el peor (los n elementos en una �nica posici�n de la tabla)
void destruirTablaHashDeEstudiantes(TablaHashDeEstudiantes* tabla);



