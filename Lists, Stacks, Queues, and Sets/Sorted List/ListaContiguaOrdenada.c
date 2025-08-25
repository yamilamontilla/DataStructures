#include "ListaContiguaOrdenada.h"
#include "assert.h" // Para assert
#include "stdio.h"


int isOrdenada(ListaContigua* lista) {
	int n = lista->n; // Tama�o de la lista entera, representada por el objeto actual en donde est� este m�todo
	assert(lista != NULL); // La lista existe

	// Vamos comparando un elemento con su anterior, a ver si est�n bien ordenados.
	// Si encontramos algun par desordenado, salimos y devolvemos falso
	for (int i = 1; i < lista->n; i++)
		if (lista->vector[i - 1] > lista->vector[i]) return(0); // La lista est� desordenada

	// Si hemos llegado hasta aqu�, est� ordenada
	return(1); 
}


int ejecutarBusquedaBinaria(ListaContigua* lista, int valorABuscar, int posicionInicioSublista, int nSublista) {

	// Precondiciones sobre la lista
	assert(lista != NULL); // La lista existe
	int n = lista->n; // Tama�o de la lista entera
	assert(n >= 0 && lista->capacidad >= n); // n y capacidad tienen sentido
	assert(isOrdenada(lista)); // La lista est� ordenada de menor a mayor
	
	// Precondiciones b�sicas sobre la sublista y su posici�n de inicio
	assert(nSublista >= 0); 
	assert(posicionInicioSublista >= 0);

	// Si el tama�o del subvector es 0, est� claro que el elemento no est�. Por lo tanto se devolver�a
	// el lugar en donde podr�a ser insertado. Dicho lugar siempre ser� posicionInicioSublista, por lo que este
	// valor podr�a llegar a ser n si hubiera que insertar el elemento buscado al final de la lista completa
	if (nSublista == 0) assert(posicionInicioSublista <= n); 

	// Si el tama�o del subvector es estrictamente mayor que cero, entonces exigimos algunas cosas l�gicas
	else {
		assert(posicionInicioSublista < n); // No puede salirse de rango
		assert(nSublista <= (n - 1) - posicionInicioSublista + 1); // El tama�o m�ximo de la sublista tiene que ser l�gico
	}

	// Si la sublista est� vac�a, est� claro que no est� el elemento que buscamos (sea cual sea)
	// y que, en caso de querer meterlo, tendr�amos que meterlo en la posici�n de inicio de 
	// la sublista (porque no hay otra opci�n)
	if (nSublista == 0) return(posicionInicioSublista);

	// Posici�n del medio de la sublista en donde estamos buscando.
	int posicionFinSublista = posicionInicioSublista + nSublista - 1;
	int posicionMedioSublista = (posicionInicioSublista + posicionFinSublista) / 2;

	// Si encontramos el elemento, entonces esa es obviamente la posici�n en que deber�a estar
	if (getValor(lista, posicionMedioSublista) == valorABuscar) return (posicionMedioSublista);

	// Si no encontramos el elemento y este es mayor que el valor del medio, seguimos buscando por arriba
	else if (valorABuscar > getValor(lista, posicionMedioSublista)) {

		// Calculamos el tama�o del nuevo subvector que representa la mitad superior del subvector actual
		// Recordemos que para contar los elementos que hay desde inicio hasta fin, ambos inclusive, es fin-inicio+1
		// Es el numero de posiciones desde la posicionMedio+1 hasta posicionFinSublista (ambas inclusive)
		int nNuevoSubvector = posicionFinSublista - (posicionMedioSublista + 1) + 1;

		// Seguimos buscando recursivamente en la mitad superior del subvector actual
		return (ejecutarBusquedaBinaria(lista, valorABuscar, posicionMedioSublista + 1, nNuevoSubvector));
	}

	// Si no encontramos el elemento y este es menor que el valor del medio, seguimos buscando por abajo
	else {

		// Calculamos el tama�o del nuevo subvector que representa la mitad inferior del subvector actual
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
	assert(isOrdenada(lista)); // La lista est� ordenada de menor a mayor

	// Si la posicion devuelta es "n", quiere decir que lo buscado no est�, y adem�s habr�a que insertarlo al final
	int posicion = ejecutarBusquedaBinaria(lista, elementoABuscar, 0, lista->n);
	if (posicion == lista->n) return(-1);

	// Si en la posicion devuelta esta el elemento a buscar, entonces lo hemos encontrado
	// Si no, entonces es porque no est� (y se podr�a insertar ah� llegado el caso)
	if (getValor(lista, posicion) == elementoABuscar) return (posicion);
	else return (-1);
}


void insertarEnOrdenada(ListaContigua* lista, int nuevoValor) {
	assert(lista != NULL); // La lista existe
	assert(lista->n >= 0 && lista->capacidad >= lista->n); // n y capacidad tienen sentido
	assert(isOrdenada(lista)); // La lista est� ordenada de menor a mayor

	// Buscamos la posicion del nuevo valor. Si est�, lo insertamos justo en esa posicion
	// Si no est�, pues lo insertamos en la posici�n que nos devuelve tambi�n
	int posicion; // Posicion en donde insertar el nuevo valor
	posicion = ejecutarBusquedaBinaria(lista, nuevoValor, 0, lista->n); 
	insertar(lista, posicion, nuevoValor); // Insertamos en la posicion devuelta
}


void eliminarEnOrdenada(ListaContigua* lista, int elementoAEliminar) {
	assert(lista != NULL);
	assert(lista->n > 0);
	assert(lista->capacidad >= lista->n);
	assert(isOrdenada(lista)); // La lista est� ordenada de menor a mayor
	assert(buscar(lista, elementoAEliminar) != -1); // El elemento existe

	int posicion = ejecutarBusquedaBinaria(lista, elementoAEliminar, 0, lista->n);
	eliminar(lista, posicion);
}
