#include "ListaEnlazada.h"
#include "impresionListasEnlazadas.h" // Para el método imprimir de la tabla hash
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
	tabla->vector = NULL;

	// Creamos el vector de punteros a listas enlazadas y dichas listas vacías
	tabla->vector = (ListaEnlazada**)malloc(sizeof(ListaEnlazada*) * capacidad);
	for (int i = 0; i < capacidad; i++) tabla->vector[i] = construirListaEnlazada();

	// Devolvemos la tabla
	return(tabla);
}


int obtenerPosicionIdeal(TablaHashDeEstudiantes* tabla, int clave, int version) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0); // Atributos tienen sentido
	assert(clave >= 0); // La clave es un número natural
	assert(version == 0 || version == 1); // Versión es 0 ó 1
	
	int posicion = clave % tabla->capacidad; // Posicion original (resto de dividir la clave entre capacidad)
	switch (version) {
	case (0): // Devolvemos la posicion original
		break;
	case (1): // Devolvemos la posición opuesta en la tabla a la original
		posicion += tabla->capacidad / 2; // La posición opuesta de la tabla estará a capacidad/2 posiciones de distancia
		posicion = posicion % tabla->capacidad; // Al sumar capacidad/2 posiciones, puede haberse salido de rango y hay que corregirlo
		break;
	}
	return (posicion);
}


PosicionReal obtenerPosicionReal(TablaHashDeEstudiantes* tabla, int clave) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0); // Atributos tienen sentido
	assert(clave >= 0); // La clave es un número natural

	// Resultado
	PosicionReal resultado;
	resultado.numeroDeLista = -1;
	resultado.posicionEnLista = -1;	

	// Datos del estudiante a buscar. Sólo nos importa la clave, por lo tanto no rellenamos el nombre
	Estudiante datosEstudiante;
	datosEstudiante.clave = clave;

	// Buscamos el estudiante en ambas posiciones. En cuanto lo encontremos, retornamos con true
	for (int version = 0; version < 2; version++) {
		int numeroDeLista = obtenerPosicionIdeal(tabla, clave, version);
		int posicionEnLista = buscar(tabla->vector[numeroDeLista], datosEstudiante);
		if (posicionEnLista != -1) {
			resultado.numeroDeLista = numeroDeLista;
			resultado.posicionEnLista = posicionEnLista;
			return (resultado);
		}
	}

	// Si llegamos hasta aquí, es que no lo hemos encontrado
	// Por tanto devolvemos "resultado" con -1 en ambos campos (tal como fue inicializado)
	return (resultado);
}


int existeEstudiante(TablaHashDeEstudiantes* tabla, int clave) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0); // Atributos tienen sentido
	assert(clave >= 0); // La clave es un número natural

	if (obtenerPosicionReal(tabla, clave).numeroDeLista == -1) return(0);
	else return(1);
}


char* getEstudiante(TablaHashDeEstudiantes* tabla, int clave) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0); // Atributos tienen sentido
	assert(clave >= 0); // La clave es un número natural
	assert(existeEstudiante(tabla, clave)); // El estudiante debe existir

	// Obtenemos el estudiante
	PosicionReal posicionReal = obtenerPosicionReal(tabla, clave);
	Estudiante estudiante = getValor(tabla->vector[posicionReal.numeroDeLista], posicionReal.posicionEnLista);
	
	// Devolvemos su nombre
	char* nombre = (char*)malloc(sizeof(char) * 10); // El usuario de esta función tendrá que liberar esta memoria
	strcpy(nombre, estudiante.nombre); 
	return(nombre);
}


void introducirEstudiante(TablaHashDeEstudiantes* tabla, int clave, char* nombreEstudiante) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0); // Atributos tienen sentido
	assert(clave >= 0); // La clave es un número natural
	assert(!existeEstudiante(tabla, clave)); // El estudiante no existía previamente en la tabla

	// Datos del estudiante a introducir.
	Estudiante datosEstudiante;
	datosEstudiante.clave = clave;
	strcpy(datosEstudiante.nombre, nombreEstudiante);

	// Obtenemos las dos posiciones
	int posicion1 = obtenerPosicionIdeal(tabla, clave, 0);
	int posicion2 = obtenerPosicionIdeal(tabla, clave, 1);

	// Metemos en la lista enlazada (de las dos posibles) cuyo tamaño sea menor
	// En dicha lista enlazada, insertamos por el principio porque es lo más rápido (O(1))
	if (tabla->vector[posicion1]->n <= tabla->vector[posicion2]->n) insertar(tabla->vector[posicion1], 0, datosEstudiante);
	else insertar(tabla->vector[posicion2], 0, datosEstudiante);

	tabla->n++; // Incrementamos n
}


void eliminarEstudiante(TablaHashDeEstudiantes* tabla, int clave) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0); // Atributos tienen sentido
	assert(clave >= 0); // La clave es un número natural
	assert(existeEstudiante(tabla, clave));

	// Localizamos y eliminamos
	PosicionReal posicionReal = obtenerPosicionReal(tabla, clave);
	eliminar(tabla->vector[posicionReal.numeroDeLista], posicionReal.posicionEnLista);
}


void imprimir(TablaHashDeEstudiantes* tabla) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0); // Atributos tienen sentido
	for (int i = 0; i < tabla->capacidad; i++) {
		printf("Posicion %d: ", i);
		imprimirListaEnlazada(tabla->vector[i]);
	}
}


void destruirTablaHashDeEstudiantes(TablaHashDeEstudiantes* tabla) {
	assert(tabla != NULL); // Tabla tiene sentido
	assert(tabla->vector != NULL && tabla->capacidad >= 1 && tabla->n >= 0); // Atributos tienen sentido
	
	// Destruimos cada una de las listas enlazadas y la zona en donde se guardan sus punteros
	for (int i = 0; i < tabla->capacidad; i++) destruirListaEnlazada(tabla->vector[i]);
	free(tabla->vector);

	// Destruimos la tabla en sí misma
	free(tabla);
}

