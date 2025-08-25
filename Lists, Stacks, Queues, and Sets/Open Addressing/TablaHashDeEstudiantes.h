#pragma once
// Tabla hash que guarda los nombres de los estudiantes de una universidad

#include "ListaEnlazada.h"


// Struct que representa a la tabla hash en sí misma
typedef struct {
	ListaEnlazada** vector; // La tabla hash será un vector de punteros a listas enlazadas
	int capacidad; // Capacidad de la tabla. Se establece en el constructor y permanece invariante desde ese momento
	int n; // Tamaño actual de la tabla (numero actual de estudiantes que contiene). Puede ser mayor que la capacidad
} TablaHashDeEstudiantes;

// Struct que contiene la posicion real de un elemento en la tabla hash
typedef struct {
	int numeroDeLista; // Número de lista enlazada en donde está el elemento (de 0 a capacidad-1)
	int posicionEnLista; // Posición del elemento en dicha lista enlazada (de 0 a n-1 en el peor caso)
} PosicionReal;


// Constructor. Construye una nueva tabla hash de estudiantes vacía
// Parámetros: 
// - capacidad: número máximo de estudiantes que podrá contener la tabla
// Retorno: puntero a la tabla hash recién creada
// Precondiciones:
// - capacidad >= 1 
// Complejidad temporal: O(capacidad) en todos los casos (porque hay que crear "capacidad" listas)
TablaHashDeEstudiantes* construirTablaHashDeEstudiantes(int capacidad);


// Método de hashing (nos devuelve dos posibles posiciones)
// Parámetros: 
// - tabla: puntero a la tabla hash para la cual estamos haciendo hashing
// - clave: la clave del estudiante (es su número de matrícula)
// - version: 0 ó 1 según el método de hashing que queramos ejecutar. 
//   Si es 0, devuelve el resto de dividir la clave entre capacidad. Si es 1, devuelve su simétrico en la tabla.
// Retorno: la posición donde el estudiante debería estar o ponerse en la tabla hash
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 (tabla es coherente)
// - clave >= 0 (la clave es un número natural)
// - version es 0 ó 1
// Complejidad temporal en todos los casos: O(1)
int obtenerPosicionIdeal(TablaHashDeEstudiantes* tabla, int clave, int version);


// Método que obtiene el puntero al nodo que contiene un estudiante en la tabla, o NULL si no está
// - tabla: puntero a la tabla hash 
// - clave: matrícula del estudiante
// Retorno: estructura "PosicionReal" con dos campos que nos dicen la posición real de un elemento: 
//          - numeroDeLista: número de lista enlazada en donde está el elemento (de 0 a capacidad-1)
//          - posicionEnLista: Posición del elemento en dicha lista enlazada (de 0 a n-1 en el peor caso)
//          Si el elemento no está en la tabla hash, se devuelve un -1 en ambos campos
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 (tabla es coherente)
// - clave >= 0 (la clave es un número natural)
// Complejidad temporal: O(1) mejor caso, y O(n) peor caso
PosicionReal obtenerPosicionReal(TablaHashDeEstudiantes* tabla, int clave);

// Comprueba si un estudiante está o no en la tabla hash
// Parámetros: 
// - tabla: puntero a la tabla hash 
// - clave: matrícula del estudiante que queremos comprobar si está o no
// Retorno: 1 si está, 0 si no
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 (tabla es coherente)
// - clave >= 0 (la clave es un número natural)
// Complejidad temporal: O(1) en mejor caso, O(n) en peor caso
int existeEstudiante(TablaHashDeEstudiantes* tabla, int clave);


// Obtiene un estudiante (su nombre) a partir de su clave (su matrícula)
// Parámetros: 
// - tabla: puntero a la tabla hash 
// - clave: matrícula del estudiante 
// Retorno: puntero a la zona de memoria en donde se guarda el nombre del estudiante
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 (tabla es coherente)
// - clave >= 0 (la clave es un número natural)
// - el estudiante debe estar en la tabla hash
// Complejidad temporal: O(1) mejor caso, y O(n) peor caso
char* getEstudiante(TablaHashDeEstudiantes* tabla, int clave);


// Inserta un estudiante en la tabla
// Parámetros: 
// - tabla: puntero a la tabla hash 
// - clave: el número de matrícula del nuevo estudiante
// - estudiante: el nombre del nuevo estudiante
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 (tabla es coherente)
// - clave >= 0 (la clave es un número natural)
// - La clave del estudiante a introducir no existía previamente en la tabla
// Complejidad temporal: O(1) en todos los casos
void introducirEstudiante(TablaHashDeEstudiantes* tabla, int clave, char* nombreEstudiante);


// Elimina un estudiante de la tabla
// Parámetros: 
// - tabla: puntero a la tabla hash 
// - clave: el número de matrícula del estudiante a eliminar
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 (tabla es coherente)
// - clave >= 0 (la clave es un número natural)
// - el estudiante debe estar previamente en la tabla hash
// Complejidad temporal: O(1) en mejor caso, O(n) en peor caso
void eliminarEstudiante(TablaHashDeEstudiantes* tabla, int clave);


// Imprime toda la tabla hash, incluyendo las casillas vacías. 
// OJO: Viola el principio de separación entre interfaz y modelo
// Parámetros: 
// - tabla: puntero a la tabla hash 
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 (tabla es coherente)
// Complejidad temporal:
// - O(capacidad) en el mejor caso (tabla vacia)
// - O(n+capacidad) en el peor (los n elementos en una única posición de la tabla)
void imprimir(TablaHashDeEstudiantes* tabla);


// Destructor. Destruye toda la memoria ocupada por la tabla hash
// Parámetros: 
// - tabla: puntero a la tabla hash 
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 (tabla es coherente)
// Complejidad temporal:
// - O(capacidad) en el mejor caso (tabla vacia)
// - O(n+capacidad) en el peor (los n elementos en una única posición de la tabla)
void destruirTablaHashDeEstudiantes(TablaHashDeEstudiantes* tabla);



