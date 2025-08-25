#pragma once
// Tabla hash que guarda los nombres de los estudiantes de una universidad


// Cada posici�n de la tabla hash ser� este struct
typedef struct {
	int clave; // Clave del elemento. N�mero de matr�cula del estudiante (un n�mero natural)
	char nombre[10]; // Valor del elemento
	int ocupada; // Booleano para indicar si est� ocupado (1) o vac�o (0)
	int borrada; // Booleano para indicar si esta casilla alguna vez ha sido borrada
} Estudiante;


// Struct que representa a la tabla hash en s� misma
typedef struct {
	Estudiante* vector; // Puntero a la zona de memoria en donde se guardan los elementos
	int capacidad; // Capacidad de la tabla. Se establece en el constructor y permanece invariante desde ese momento
	int n; // Tama�o actual de la tabla (numero actual de estudiantes que contiene)
} TablaHashDeEstudiantes;


// Constructor. Construye una nueva tabla hash de estudiantes vac�a
// Par�metros: 
// - capacidad: n�mero m�ximo de estudiantes que podr� contener la tabla
// Retorno: puntero a la tabla hash reci�n creada
// Precondiciones:
// - capacidad >= 1 
// Complejidad temporal: O(capacidad) en todos los casos (porque hay que inicializar los flags)
TablaHashDeEstudiantes* construirTablaHashDeEstudiantes(int capacidad);


// M�todo de hashing
// Par�metros: 
// - tabla: puntero a la tabla hash para la cual estamos haciendo hashing
// - clave: la clave del estudiante (es su n�mero de matr�cula)
// Retorno: la posici�n donde el estudiante deber�a estar o ponerse en la tabla hash
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 && n <= capacidad (tabla es coherente)
// - clave >= 0 (la clave es un n�mero natural)
// Complejidad temporal en todos los casos: O(1)
int obtenerPosicionIdeal(TablaHashDeEstudiantes* tabla, int clave);


// M�todo que obtiene la posicion interna real de un estudiante en la tabla, o -1 si no est�
// - tabla: puntero a la tabla hash 
// - clave: matr�cula del estudiante
// Retorno: posicion real en la tabla en donde el estudiante est�, o -1 si no se encuentra
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 && n <= capacidad (tabla es coherente)
// - clave >= 0 (la clave es un n�mero natural)
// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
int obtenerPosicionReal(TablaHashDeEstudiantes* tabla, int clave);


// Comprueba si un estudiante est� o no en la tabla hash
// Par�metros: 
// - tabla: puntero a la tabla hash 
// - clave: matr�cula del estudiante que queremos comprobar si est� o no
// Retorno: 1 si est�, 0 si no
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 && n <= capacidad (tabla es coherente)
// - clave >= 0 (la clave es un n�mero natural)
// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
int existeEstudiante(TablaHashDeEstudiantes* tabla, int clave);


// Obtiene un estudiante (su nombre) a partir de su clave (su matr�cula)
// Par�metros: 
// - tabla: puntero a la tabla hash 
// - clave: matr�cula del estudiante 
// Retorno: puntero a la zona de memoria en donde se guarda el nombre del estudiante
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 && n <= capacidad (tabla es coherente)
// - clave >= 0 (la clave es un n�mero natural)
// - el estudiante debe estar en la tabla hash
// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
char* getEstudiante(TablaHashDeEstudiantes* tabla, int clave);


// Inserta un estudiante en la tabla
// Par�metros: 
// - tabla: puntero a la tabla hash 
// - clave: el n�mero de matr�cula del nuevo estudiante
// - estudiante: el nombre del nuevo estudiante
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 && n <= capacidad (tabla es coherente)
// - clave >= 0 (la clave es un n�mero natural)
// - La tabla no est� llena
// - La clave del estudiante a introducir no exist�a previamente en la tabla
// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
void introducirEstudiante(TablaHashDeEstudiantes* tabla, int clave, char* nombreEstudiante);


// Elimina un estudiante de la tabla
// Par�metros: 
// - tabla: puntero a la tabla hash 
// - clave: el n�mero de matr�cula del estudiante a eliminar
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 && n <= capacidad (tabla es coherente)
// - clave >= 0 (la clave es un n�mero natural)
// - el estudiante debe estar previamente en la tabla hash
// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
void eliminarEstudiante(TablaHashDeEstudiantes* tabla, int clave);


// Imprime toda la tabla hash, incluyendo las casillas vac�as. 
// OJO: Viola el principio de separaci�n entre interfaz y modelo
// Par�metros: 
// - tabla: puntero a la tabla hash 
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 && n <= capacidad (tabla es coherente)
// Complejidad temporal: O(capacidad) en todos los casos
void imprimir(TablaHashDeEstudiantes* tabla);


// Destructor. Destruye toda la memoria ocupada por la tabla hash
// Par�metros: 
// - tabla: puntero a la tabla hash 
// Precondiciones:
// - tabla != NULL && tabla->vector != NULL && capacidad >= 1 && n >= 0 && n <= capacidad (tabla es coherente)
// Complejidad temporal: O(1) en todos los casos
void destruirTablaHashDeEstudiantes(TablaHashDeEstudiantes* tabla);

















