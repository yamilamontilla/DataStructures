#pragma once // Esta directiva evita que se incluya por error este archivo m�s de una vez en el main

// Struct que representa a una lista contigua en memoria y cuya capacidad se redimensiona autom�ticamente
// de modo que el usuario no tiene que preocuparse por su capacidad
typedef struct {

	// Puntero que apuntar� a la zona de memoria en donde empieza la ListaContigua
	int* vector;

	// Numero actual de elementos que tiene la ListaContigua
	// Precondici�n: n>=0
	int n;

	// Capacidad actual de la ListaContigua
	// Precondici�n: capacidad >= n
	int capacidad;

} ListaContigua;

// Constructor. Crea una ListaContigua de tama�o y capacidad 0
// Retorno: puntero al nuevo struct creado
// Complejidad temporal: O(1)
ListaContigua* crearListaContigua();

// Destructor. Libera memoria
// Par�metro: puntero al struct que representa la lista
// Precondiciones: 
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// Complejidad temporal: O(1)
void destruirListaContigua(ListaContigua* lista);

// Nos dice si la ListaContigua est� llena o no.
// Par�metro: puntero al struct que representa la lista
// Retorno: n�mero distinto de cero si est� llena, 0 si no est� llena
// Precondiciones: 
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// Complejidad temporal: O(1)
int isLlena(ListaContigua* lista);

// Devuelve un elemento de la ListaContigua
// Par�metros: 
// - lista: puntero al struct que representa la lista
// - posicion: la posici�n del elemento
// Retorno: el elemento encontrado en esa posici�n
// Precondiciones:
// - posicion en [0, n-1]
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// Complejidad temporal: O(1)
int getValor(ListaContigua* lista, int posicion);

// Modifica un elemento de la ListaContigua
// Par�metros:
// - lista: puntero al struct que representa la lista
// - posicion: la posici�n del elemento que queremos modificar
// - nuevoValor: el nuevo valor del elemento
// Precondiciones:
// - posicion en [0, n-1]
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// Complejidad temporal: O(1)
void setValor(ListaContigua* lista, int posicion, int nuevoValor);

// Ampl�a o disminuye la capacidad en un valor
// Par�metros: 
// - lista: puntero al struct que representa la lista
// - incremento: cantidad a aumentar (si es positivo) o disminuir (si es negativo) la capacidad actual de la lista
// Precondiciones:
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// Complejidad temporal: O(n)
void ampliarCapacidad(ListaContigua* lista, int incremento);

// Inserta un nuevo elemento en la �ltima posici�n de la ListaContigua, 
// ampliando previamente la capacidad si es necesario
// Par�metros:
// - lista: puntero al struct que representa la lista
// - nuevoValor: el nuevo elemento que queremos poner
// Precondiciones:
// - lista != NULL
// - n >= 0 && capacidad >= n (valores de "n" y "capacidad" tienen sentido)
// Complejidad temporal: O(n)
void insertarAlFinal (ListaContigua* lista, int nuevoValor);

// Elimina el elemento de la �ltima posici�n de la ListaContigua,
// disminuyendo posteriormente la capacidad si es necesario
// Par�metro: puntero al struct que representa la lista
// Precondiciones:
// - lista != NULL
// - lista-> n > 0 (la lista no est� vac�a)
// - capacidad >= n (valor de "capacidad" tiene sentido)
// Complejidad temporal: O(1)
void eliminarAlFinal(ListaContigua* lista);










