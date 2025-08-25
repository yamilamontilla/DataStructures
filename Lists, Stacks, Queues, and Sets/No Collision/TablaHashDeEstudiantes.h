#pragma once
// Tabla hash que guarda los nombres de los estudiantes de una universidad


// Cada posición de la tabla hash será este struct
typedef struct {
	int clave; // Clave del elemento. Número de matrícula del estudiante (un número natural)
	char nombre[10]; // Valor del elemento
	int ocupada; // Booleano para indicar si está ocupado (1) o vacío (0)
} Estudiante;


// Struct que representa a la tabla hash en sí misma
typedef struct {
	Estudiante* vector; // Puntero a la zona de memoria en donde se guardan los elementos
	int capacidad; // Capacidad de la tabla. Se establece en el constructor y permanece invariante desde ese momento
	int n; // Tamaño actual de la tabla (numero actual de estudiantes que contiene)
} TablaHashDeEstudiantes;


// Constructor. Construye una nueva tabla hash de estudiantes vacía
// Parámetros: 
// - capacidad: número máximo de estudiantes que podrá contener la tabla
// Retorno: puntero a la tabla hash recién creada
// Precondiciones:
// - capacidad >= 1 
// Complejidad temporal: O(capacidad)
TablaHashDeEstudiantes* construirTablaHashDeEstudiantes(int capacidad);


// Método de hashing
// Parámetros: 
// - tabla: puntero a la tabla hash para la cual estamos haciendo hashing
// - clave: la clave del estudiante (es su número de matrícula)
// Retorno: la posición donde el estudiante debería estar o ponerse en la tabla hash
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 && n <= capacidad (tabla es coherente)
// - clave >= 0 (la clave es un número natural)
// Complejidad temporal: O(1)
int obtenerPosicionIdeal (TablaHashDeEstudiantes *tabla, int clave);


// Comprueba si un estudiante está o no en la tabla hash
// Parámetros: 
// - tabla: puntero a la tabla hash 
// - clave: matrícula del estudiante que queremos comprobar si está o no
// Retorno: 1 si está, 0 si no
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 && n <= capacidad (tabla es coherente)
// - clave >= 0 (la clave es un número natural)
// Complejidad temporal: O(1)
int existeEstudiante (TablaHashDeEstudiantes* tabla, int clave);

// Obtiene un estudiante (su nombre) a partir de su clave (su matrícula)
// Parámetros: 
// - tabla: puntero a la tabla hash 
// - clave: matrícula del estudiante que queremos comprobar si está o no
// Retorno: puntero a la zona de memoria en donde se guarda el nombre del estudiante
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 && n <= capacidad (tabla es coherente)
// - clave >= 0 (la clave es un número natural)
// - el estudiante debe estar en la tabla hash
// Complejidad temporal: O(1)
char* getEstudiante(TablaHashDeEstudiantes* tabla, int clave);

// Inserta un estudiante en la tabla
// Parámetros: 
// - tabla: puntero a la tabla hash 
// - clave: el número de matrícula del nuevo estudiante
// - estudiante: el nombre del nuevo estudiante
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 && n <= capacidad (tabla es coherente)
// - clave >= 0 (la clave es un número natural)
// - La tabla no está llena
// - La posicion en donde internamente meteremos el estudiante no está ocupada (no hay colisión)
// Complejidad temporal: O(1)
void introducirEstudiante (TablaHashDeEstudiantes* tabla, int clave, char *nombreEstudiante);

// Elimina un estudiante de la tabla
// Parámetros: 
// - tabla: puntero a la tabla hash 
// - clave: el número de matrícula del estudiante a eliminar
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 && n <= capacidad (tabla es coherente)
// - clave >= 0 (la clave es un número natural)
// - el estudiante debe estar previamente en la tabla hash
// Complejidad temporal: O(1)
void eliminarEstudiante (TablaHashDeEstudiantes* tabla, int clave);

// Imprime toda la tabla hash, incluyendo las casillas vacías. 
// OJO: Viola el principio de separación entre interfaz y modelo
// Parámetros: 
// - tabla: puntero a la tabla hash 
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 && n <= capacidad (tabla es coherente)
// Complejidad temporal: O(capacidad)
void imprimir(TablaHashDeEstudiantes* tabla);

// Destructor. Destruye toda la memoria ocupada por la tabla hash
// // Parámetros: 
// - tabla: puntero a la tabla hash 
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 && n <= capacidad (tabla es coherente)
// Complejidad temporal: O(1)
void destruirTablaHashDeEstudiantes(TablaHashDeEstudiantes* tabla);



