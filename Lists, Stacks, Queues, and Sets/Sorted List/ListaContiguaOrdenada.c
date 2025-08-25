#include "ListaContiguaOrdenada.h"
#include "assert.h" // Para assert
#include "stdio.h"


int isOrdenada(ListaContigua* lista) {
	int n = lista->n; // Tamaño de la lista entera, representada por el objeto actual en donde está este método
	assert(lista != NULL); // La lista existe

	// Vamos comparando un elemento con su anterior, a ver si están bien ordenados.
	// Si encontramos algun par desordenado, salimos y devolvemos falso
	for (int i = 1; i < lista->n; i++)
		if (lista->vector[i - 1] > lista->vector[i]) return(0); // La lista está desordenada

	// Si hemos llegado hasta aquí, está ordenada
	return(1); 
}


int ejecutarBusquedaBinaria(ListaContigua* lista, int valorABuscar, int posicionInicioSublista, int nSublista) {

	// Precondiciones sobre la lista
	assert(lista != NULL); // La lista existe
	int n = lista->n; // Tamaño de la lista entera
	assert(n >= 0 && lista->capacidad >= n); // n y capacidad tienen sentido
	assert(isOrdenada(lista)); // La lista está ordenada de menor a mayor
	
	// Precondiciones básicas sobre la sublista y su posición de inicio
	assert(nSublista >= 0); 
	assert(posicionInicioSublista >= 0);

	// Si el tamaño del subvector es 0, está claro que el elemento no está. Por lo tanto se devolvería
	// el lugar en donde podría ser insertado. Dicho lugar siempre será posicionInicioSublista, por lo que este
	// valor podría llegar a ser n si hubiera que insertar el elemento buscado al final de la lista completa
	if (nSublista == 0) assert(posicionInicioSublista <= n); 

	// Si el tamaño del subvector es estrictamente mayor que cero, entonces exigimos algunas cosas lógicas
	else {
		assert(posicionInicioSublista < n); // No puede salirse de rango
		assert(nSublista <= (n - 1) - posicionInicioSublista + 1); // El tamaño máximo de la sublista tiene que ser lógico
	}

	// Si la sublista está vacía, está claro que no está el elemento que buscamos (sea cual sea)
	// y que, en caso de querer meterlo, tendríamos que meterlo en la posición de inicio de 
	// la sublista (porque no hay otra opción)
	if (nSublista == 0) return(posicionInicioSublista);

	// Posición del medio de la sublista en donde estamos buscando.
	int posicionFinSublista = posicionInicioSublista + nSublista - 1;
	int posicionMedioSublista = (posicionInicioSublista + posicionFinSublista) / 2;

	// Si encontramos el elemento, entonces esa es obviamente la posición en que debería estar
	if (getValor(lista, posicionMedioSublista) == valorABuscar) return (posicionMedioSublista);

	// Si no encontramos el elemento y este es mayor que el valor del medio, seguimos buscando por arriba
	else if (valorABuscar > getValor(lista, posicionMedioSublista)) {

		// Calculamos el tamaño del nuevo subvector que representa la mitad superior del subvector actual
		// Recordemos que para contar los elementos que hay desde inicio hasta fin, ambos inclusive, es fin-inicio+1
		// Es el numero de posiciones desde la posicionMedio+1 hasta posicionFinSublista (ambas inclusive)
		int nNuevoSubvector = posicionFinSublista - (posicionMedioSublista + 1) + 1;

		// Seguimos buscando recursivamente en la mitad superior del subvector actual
		return (ejecutarBusquedaBinaria(lista, valorABuscar, posicionMedioSublista + 1, nNuevoSubvector));
	}

	// Si no encontramos el elemento y este es menor que el valor del medio, seguimos buscando por abajo
	else {

		// Calculamos el tamaño del nuevo subvector que representa la mitad inferior del subvector actual
		// Recordemos que para contar los elementos que hay desde inicio hasta fin, ambos inclusive, es fin-inicio+1
		// Es el numero de posiciones desde la posicionInicioSublista hasta posicionMedioSublista-1 (ambas inclusive)
		int nNuevoSubvector = (posicionMedioSublista - 1) - posicionInicioSublista + 1;

		// Seguimos buscando recursivamente en la mitad inferior del subvector actual
		return (ejecutarBusquedaBinaria(lista, valorABuscar, posicionInicioSublista, nNuevoSubvector));
	}
}


int buscarEnOrdenada(ListaContigua* lista, int elementoABuscar) {
	assert(lista != NULL); // La lista existe
	assert(lista->n >= 0 && lista->capacidad >= lista->n); // n y capacidad tienen sentido
	assert(isOrdenada(lista)); // La lista está ordenada de menor a mayor

	// Si la posicion devuelta es "n", quiere decir que lo buscado no está, y además habría que insertarlo al final
	int posicion = ejecutarBusquedaBinaria(lista, elementoABuscar, 0, lista->n);
	if (posicion == lista->n) return(-1);

	// Si en la posicion devuelta esta el elemento a buscar, entonces lo hemos encontrado
	// Si no, entonces es porque no está (y se podría insertar ahí llegado el caso)
	if (getValor(lista, posicion) == elementoABuscar) return (posicion);
	else return (-1);
}


void insertarEnOrdenada(ListaContigua* lista, int nuevoValor) {
	assert(lista != NULL); // La lista existe
	assert(lista->n >= 0 && lista->capacidad >= lista->n); // n y capacidad tienen sentido
	assert(isOrdenada(lista)); // La lista está ordenada de menor a mayor

	// Buscamos la posicion del nuevo valor. Si está, lo insertamos justo en esa posicion
	// Si no está, pues lo insertamos en la posición que nos devuelve también
	int posicion; // Posicion en donde insertar el nuevo valor
	posicion = ejecutarBusquedaBinaria(lista, nuevoValor, 0, lista->n); 
	insertar(lista, posicion, nuevoValor); // Insertamos en la posicion devuelta
}


void eliminarEnOrdenada(ListaContigua* lista, int elementoAEliminar) {
	assert(lista != NULL);
	assert(lista->n > 0);
	assert(lista->capacidad >= lista->n);
	assert(isOrdenada(lista)); // La lista está ordenada de menor a mayor
	assert(buscar(lista, elementoAEliminar) != -1); // El elemento existe

	int posicion = ejecutarBusquedaBinaria(lista, elementoAEliminar, 0, lista->n);
	eliminar(lista, posicion);
}
