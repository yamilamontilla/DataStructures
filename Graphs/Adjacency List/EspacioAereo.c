#include "EspacioAereo.h"
#include "impresionListasEnlazadas.h"
#include "stdlib.h"
#include "assert.h"
#include "string.h"
#include "stdio.h"


int existeAeropuerto(ListaContigua* grafo, char* nombre) {
	assert(grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n); // la lista que representa al grafo tiene sentido
	assert(nombre != NULL);
	Aeropuerto aeropuerto;
	strcpy(aeropuerto.nombre, nombre);
	if (buscarEnContigua(grafo, aeropuerto) == -1) return(0);
	else return(1);
}

ListaEnlazada* getDestinos(ListaContigua* grafo, char* origen) {
	assert(grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n); // la lista que representa al grafo tiene sentido
	assert(origen != NULL);
	assert(existeAeropuerto(grafo, origen));
	Aeropuerto aeropuerto;
	strcpy(aeropuerto.nombre, origen);
	int posicionOrigen = buscarEnContigua(grafo, aeropuerto); // Posición del aeropuerto origen en la lista de grafo
	ListaEnlazada* rutas = getValorEnContigua(grafo, posicionOrigen).rutasSalientes; // Lista de destinos desde ese nodo
	return(rutas);
}


ListaEnlazada* getOrigenes(ListaContigua* grafo, char* destino) {
	assert(grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n); // la lista que representa al grafo tiene sentido
	assert(destino != NULL);
	assert(existeAeropuerto(grafo, destino));
	Aeropuerto aeropuerto;
	strcpy(aeropuerto.nombre, destino);
	int posicionDestino = buscarEnContigua(grafo, aeropuerto); // Posición del aeropuerto destino en la lista de grafo
	ListaEnlazada* rutas = getValorEnContigua(grafo, posicionDestino).rutasEntrantes; // Lista de orígenes hasta el nodo destino
	return(rutas);
}


int existeRuta(ListaContigua* grafo, char* origen, char* destino) {
	assert(grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n); // la lista que representa al grafo tiene sentido
	assert(origen != NULL);
	assert(destino != NULL);
	assert(existeAeropuerto(grafo, origen));
	assert(existeAeropuerto(grafo, destino));

	Ruta ruta;
	strcpy(ruta.aeropuerto, destino);
	if (buscar(getDestinos(grafo, origen), ruta) == -1) return(0);
	else return (1);
}


void imprimirGrafo(ListaContigua* grafo) {
	assert(grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n); // la lista que representa al grafo tiene sentido
	if (grafo->n == 0) printf("Grafo vacio\n");
	else {
		// Por cada nodo, imprimimos sus destinos y sus orígenes
		for (int i = 0; i < grafo->n; i++) {
			Aeropuerto aeropuerto = getValorEnContigua(grafo, i);
			printf("Nodo %s:\n", aeropuerto.nombre);
			printf("\tRutas de salida: ");
			imprimirListaEnlazada(getValorEnContigua(grafo, i).rutasSalientes);
			printf("\tRutas de entrada: ");
			imprimirListaEnlazada(getValorEnContigua(grafo, i).rutasEntrantes);
		}
	}
}


void insertarAeropuerto(ListaContigua* grafo, char* nombre) {
	assert(grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n); // la lista que representa al grafo tiene sentido
	assert(nombre != NULL);
	assert(!existeAeropuerto(grafo, nombre)); // Ese aeropuerto no existe previamente
	Aeropuerto nuevoAeropuerto;
	strcpy(nuevoAeropuerto.nombre, nombre);
	nuevoAeropuerto.rutasEntrantes = construirListaEnlazada();
	nuevoAeropuerto.rutasSalientes = construirListaEnlazada();
	insertarAlFinal(grafo, nuevoAeropuerto);
}


void insertarRuta(ListaContigua* grafo, char* origen, char* destino, int distancia, char* empresa) {
	assert(grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n); // la lista que representa al grafo tiene sentido
	assert(origen != NULL);
	assert(destino != NULL);
	assert(empresa != NULL);
	assert(existeAeropuerto(grafo, origen));
	assert(existeAeropuerto(grafo, destino));
	assert(!existeRuta(grafo, origen, destino));
	assert(distancia > 0);

	// Tenemos que añadir la ruta de forma redundante en dos listas: 
	// - La lista de destinos en el origen
	// - La lista de orígenes en el destino

	// Creamos la nueva ruta para añadir a la lista de destinos en el origen
	Ruta nuevaRuta1;
	strcpy(nuevaRuta1.aeropuerto, destino);
	nuevaRuta1.kilometros = distancia;
	strcpy(nuevaRuta1.empresa, empresa);

	// Añadimos la ruta al principio de la lista de destinos en el origen, para que sea O(1)
	ListaEnlazada* destinos = getDestinos(grafo, origen);
	insertar(destinos, 0, nuevaRuta1);

	// Creamos la nueva ruta para añadir a la lista de orígenes en el destino
	Ruta nuevaRuta2;
	strcpy(nuevaRuta2.aeropuerto, origen);
	nuevaRuta2.kilometros = distancia;
	strcpy(nuevaRuta2.empresa, empresa);

	// Añadimos la ruta al principio de la lista de orígenes en el destino, para que sea O(1)
	ListaEnlazada* origenes = getOrigenes(grafo, destino);
	insertar(origenes, 0, nuevaRuta2);
}


void eliminarRuta(ListaContigua* grafo, char* origen, char* destino) {
	assert(grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n); // la lista que representa al grafo tiene sentido
	assert(origen != NULL);
	assert(destino != NULL);
	assert(existeAeropuerto(grafo, origen));
	assert(existeAeropuerto(grafo, destino));
	assert(existeRuta(grafo, origen, destino));

	// Primero vamos a la lista del aeropuerto origen y la eliminamos de allí
	ListaEnlazada* destinos = getDestinos(grafo, origen);
	Ruta ruta; strcpy(ruta.aeropuerto, destino);
	int posicion = buscar(destinos, ruta); // O(n) porque no es multigrafo
	eliminar(destinos, posicion); // O(n) porque no es multigrafo

	// Ahora vamos a la lista del aeropuerto destino y la eliminamos de alli
	ListaEnlazada* origenes = getOrigenes(grafo, destino);
	strcpy(ruta.aeropuerto, origen);
	posicion = buscar(origenes, ruta);
	eliminar(origenes, posicion);
}


void eliminarAeropuerto(ListaContigua* grafo, char* nombre) {
	assert(grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n); // la lista que representa al grafo tiene sentido
	assert(nombre != NULL);
	assert(existeAeropuerto(grafo, nombre));

	// Eliminamos todas las rutas que parten desde el aeropuerto
	// Recordemos que cada una está duplicada dos veces
	ListaEnlazada *destinos = getDestinos(grafo, nombre);
	while (destinos->n > 0) {
		char *origen = nombre;
		char *destino = getValor(destinos, 0).aeropuerto;
		eliminarRuta(grafo, origen, destino);
	}

	// Eliminamos todas las rutas que llegan a ese aeropuerto
	// Recordemos que cada una está duplicada dos veces
	ListaEnlazada* origenes = getOrigenes(grafo, nombre);
	while (origenes->n > 0) {
		char *origen = getValor(origenes, 0).aeropuerto;
		char *destino = nombre;
		eliminarRuta(grafo, origen, destino);
	}

	// Eliminamos finalmente el aeropuerto
	Aeropuerto aeropuerto;
	strcpy(aeropuerto.nombre, nombre);
	int posicion = buscarEnContigua(grafo, aeropuerto);
	eliminarEnContigua(grafo, posicion);
}


