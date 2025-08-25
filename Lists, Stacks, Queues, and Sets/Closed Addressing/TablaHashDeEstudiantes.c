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
	for (int i = 0; i < capacidad; i++) {
		tabla->vector[i].ocupada = 0;
		tabla->vector[i].borrada = 0;
	}

	// Devolvemos la tabla
	return(tabla);
}


int obtenerPosicionIdeal(TablaHashDeEstudiantes* tabla, int clave) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); // Atributos tienen sentido
	assert(clave >= 0); // La clave es un número natural
	return (clave % tabla->capacidad);
}


int obtenerPosicionReal(TablaHashDeEstudiantes* tabla, int clave) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); // Atributos tienen sentido
	assert(clave >= 0); // La clave es un número natural

	// Posicion en donde buscamos inicialmente. Empezamos por donde idealmente debería estar
	int posicion = obtenerPosicionIdeal(tabla, clave); 	
	
	// Vamos mirando la tabla en orden secuencial hasta que: o lo encontremos, o lleguemos a una casilla virgen
	// (vacía y nunca borrada) o hayamos examinado toda la tabla
	for (int i = 0; i < tabla->capacidad; i++) {
		Estudiante estudiante = tabla->vector[posicion]; // Estudiante a examinar en esa posición
		if (estudiante.ocupada && estudiante.clave == clave) return(posicion); // Encontrado 
		if (!estudiante.ocupada && !estudiante.borrada) return (-1); // Encontrada casilla virgen, así que seguro que no está
		posicion = (posicion + 1) % tabla->capacidad; // Incrementamos posicion (la siguiente a la ultima es la primera)
		}

	// Si llegamos hasta aquí es porque hemos recorrido toda la tabla y el estudiante no está (peor caso)	
	return (-1);
}


int existeEstudiante(TablaHashDeEstudiantes* tabla, int clave) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); // Atributos tienen sentido
	assert(clave >= 0); // La clave es un número natural
	int posicion = obtenerPosicionReal(tabla, clave);
	if (posicion == -1) return (0);
	else return (1);
}


char* getEstudiante(TablaHashDeEstudiantes* tabla, int clave) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); // Atributos tienen sentido
	assert(clave >= 0); // La clave es un número natural
	assert(existeEstudiante(tabla, clave)); // El estudiante debe existir
	int posicion = obtenerPosicionReal(tabla, clave);
	return (tabla->vector[posicion].nombre); // Ojo, NO devolvemos una copia del nombre
}


void introducirEstudiante(TablaHashDeEstudiantes* tabla, int clave, char* nombreEstudiante) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); // Atributos tienen sentido
	assert(clave >= 0); // La clave es un número natural
	assert(tabla->n < tabla->capacidad); // La tabla no está llena
	assert(!existeEstudiante(tabla, clave)); // El estudiante no existía previamente en la tabla

	// Vamos buscando secuencialmente en la tabla, a partir de la posición ideal, hasta encontrar un hueco,
	// es decir, una casilla vacia (nos da igual si esta borrada o no)
	int posicion = obtenerPosicionIdeal(tabla, clave); // Posicion inicial para buscar
	while (tabla->vector[posicion].ocupada) posicion = (posicion + 1) % tabla->capacidad; // Incrementamos posicion circularmente

	// Metemos los datos del estudiante
	strcpy(tabla->vector[posicion].nombre, nombreEstudiante); // Copiamos el nombre
	tabla->vector[posicion].clave = clave;
	tabla->vector[posicion].ocupada = 1; // Indicamos que esa posición está ocupada ahora. El flag de borrado no lo tocamos

	tabla->n++; // Incrementamos n
}


void eliminarEstudiante(TablaHashDeEstudiantes* tabla, int clave) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); // Atributos tienen sentido
	assert(clave >= 0); // La clave es un número natural
	assert(existeEstudiante(tabla, clave));
	int posicion = obtenerPosicionReal(tabla, clave);
	tabla->vector[posicion].ocupada = 0; // Simplemente marcamos esa posición como basura
	tabla->vector[posicion].borrada = 1; // Marcamos que esta posición ha sido alguna vez borrada
	tabla->n--;
}


void imprimir(TablaHashDeEstudiantes* tabla) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); // Atributos tienen sentido
	for (int i = 0; i < tabla->capacidad; i++) {
		Estudiante estudiante = tabla->vector[i];
		printf("Posicion %d | Ocupada: %d | Borrada: %d | Clave: %d | Valor: %s\n", i, estudiante.ocupada, estudiante.borrada, estudiante.clave, estudiante.nombre);
	}
}


void destruirTablaHashDeEstudiantes(TablaHashDeEstudiantes* tabla) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); // Atributos tienen sentido
	free(tabla->vector);
	free(tabla);
}
