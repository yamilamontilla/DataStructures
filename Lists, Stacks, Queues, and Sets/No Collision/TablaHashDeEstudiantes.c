#include "TablaHashDeEstudiantes.h"
#include "assert.h"
#include "stdlib.h"
#include "stdio.h"


TablaHashDeEstudiantes* construirTablaHashDeEstudiantes(int capacidad) {
	assert(capacidad >= 1);

	// Creamos la tabla
	TablaHashDeEstudiantes* tabla = (TablaHashDeEstudiantes*)malloc(sizeof(TablaHashDeEstudiantes));

	// Inicializamos los atributos
	tabla->n = 0;
	tabla->capacidad = capacidad;

	// Creamos la zona de memoria para los elementos e inicializamos sus booleanos a falso
	tabla->vector = (Estudiante*)malloc(sizeof(Estudiante) * capacidad);
	for (int i = 0; i < capacidad; i++) tabla->vector[i].ocupada = 0;

	// Devolvemos la tabla
	return(tabla);
}


int obtenerPosicionIdeal(TablaHashDeEstudiantes* tabla, int clave) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); // Atributos tienen sentido
	assert(clave >= 0); // La clave es un número natural
	return (clave % tabla->capacidad);
}


int existeEstudiante(TablaHashDeEstudiantes* tabla, int clave) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); // Atributos tienen sentido
	assert(clave >= 0); // La clave es un número natural
	int posicion = obtenerPosicionIdeal(tabla, clave);
	if (tabla->vector[posicion].ocupada && tabla->vector[posicion].clave==clave) return (1);
	else return (0);
}


char* getEstudiante(TablaHashDeEstudiantes* tabla, int clave) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); // Atributos tienen sentido
	assert(clave >= 0); // La clave es un número natural
	assert(existeEstudiante(tabla, clave)); // El estudiante debe existir
	int posicion = obtenerPosicionIdeal(tabla, clave);
	return (tabla->vector[posicion].nombre); // Ojo, NO devolvemos una copia del nombre
}


void introducirEstudiante(TablaHashDeEstudiantes* tabla, int clave, char* nombreEstudiante) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); // Atributos tienen sentido
	assert(clave >= 0); // La clave es un número natural
	assert(tabla->n < tabla->capacidad); // La tabla no está llena

	int posicion = obtenerPosicionIdeal(tabla, clave);
	assert(!tabla->vector[posicion].ocupada); // En donde queremos meter el estudiante no hay nada aún (no hay colisión)

	// Metemos los datos del estudiante
	strcpy(tabla->vector[posicion].nombre, nombreEstudiante); // Copiamos el nombre
	tabla->vector[posicion].clave = clave;
	tabla->vector[posicion].ocupada = 1; // Indicamos que esa posición está ocupada ahora

	tabla->n++; // Incrementamos n
}


void eliminarEstudiante(TablaHashDeEstudiantes* tabla, int clave) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); // Atributos tienen sentido
	assert(clave >= 0); // La clave es un número natural
	assert(existeEstudiante(tabla, clave));
	int posicion = obtenerPosicionIdeal(tabla, clave);
	tabla->vector[posicion].ocupada=0; // Simplemente marcamos esa posición como basura
	tabla->n--;
}


void imprimir(TablaHashDeEstudiantes* tabla) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); // Atributos tienen sentido
	for (int i = 0; i < tabla->capacidad; i++) {
		Estudiante estudiante = tabla->vector[i];
		printf("Posicion %d | Ocupada: %d | Clave: %d | Valor: %s\n", i, estudiante.ocupada, estudiante.clave, estudiante.nombre);
	}
}


void destruirTablaHashDeEstudiantes(TablaHashDeEstudiantes* tabla) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); // Atributos tienen sentido
	free (tabla->vector);
	free (tabla);
}
