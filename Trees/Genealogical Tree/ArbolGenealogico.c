#include "ArbolGenealogico.h"
#include "assert.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h" // Para strcmp, strcpy


int getNumeroHijos(Nodo * padre) {
	assert(padre != NULL);

	Nodo *hijoActual = padre->primerHijo; // Hijo actual en el que estamos (inicialmente es el primero)
	int numeroHijosDirectos; // Resultado de la función

	// Si no tiene ni siquiera un primer hijo, no tiene ningún hijo
	if (hijoActual == NULL) numeroHijosDirectos = 0;

	// Si tiene hijos, vamos iterando por ellos (de hermano a hermano) para contar cuántos hay
	else {
		numeroHijosDirectos = 1; // Al menos tiene uno (el primer hijo)		
		// Vamos desplazándonos al hermano derecho hasta que ya no podamos más
		while (hijoActual->hermanoDerecho != NULL) {
			hijoActual = hijoActual->hermanoDerecho;
			numeroHijosDirectos++;
		}
	}
	return(numeroHijosDirectos);
}


Nodo *getHijo(Nodo *padre, int posicionHijo) {
	assert(padre != NULL);
	int numeroHijos = getNumeroHijos(padre); // Numero de hijos del padre
	assert(numeroHijos > 0);
	assert(posicionHijo >= 0 && posicionHijo<numeroHijos);

	// Llegamos hasta el hijo adecuado, iterando a lo largo de los hermanos
	Nodo *resultado = padre->primerHijo; // Puntero al nodo hijo al que queremos acceder. Inicializado con el primero
	for (int i = 0; i < posicionHijo; i++) resultado = resultado->hermanoDerecho; // Llegamos hasta el hijo adecuado

	// Devolvemos el puntero al nodo hijo
	return(resultado);
}


Nodo* buscarNodo (Nodo *raizSubarbol, char* contenido) {
	assert(contenido != NULL);

	// Si el subárbol está vacío, es obvio que el contenido buscado no está
	if (raizSubarbol == NULL) return(NULL);

	// Primero buscamos en la propia raiz. Si encontramos el contenido ahí, hemos terminado
	if (strcmp(raizSubarbol->contenido, contenido) == 0) return (raizSubarbol);

	// Si no, buscamos en sus subarboles hijos. 
	// Retornamos directamente si lo encontramos en alguno de sus subarboles hijos
	else {
		int numeroSubarboles = getNumeroHijos(raizSubarbol); // Número de hijos de la raizSubarbol
		for (int i=0; i<numeroSubarboles; i++) {

			// Buscamos recursivamente en uno de los subárboles que cuelgan de la raíz
			Nodo *resultado = buscarNodo(getHijo(raizSubarbol, i), contenido);
			
			// Si lo hemos encontrado en el subárbol, terminamos
			if (resultado != NULL) return (resultado);
		}
	}

	// Si hemos llegado hasta aquí, no lo hemos encontrado en el subárbol actual
	return (NULL);
}


void imprimirRecursivo(Nodo *raizSubarbol, int numeroTabulaciones) {
	assert (raizSubarbol != NULL);
	assert(numeroTabulaciones >= 0);

	// Imprimimos el nodo raiz con el nivel pasado como parametro
	for (int i=0; i<numeroTabulaciones; i++) printf("\t");
	printf("%s\n", raizSubarbol->contenido);

	// Imprimimos cada uno de sus subárboles con una tabulacion mas
	int numeroSubarboles = getNumeroHijos(raizSubarbol); // Número de hijos de la raizSubarbol
	for (int i = 0; i < numeroSubarboles; i++) imprimirRecursivo(getHijo(raizSubarbol, i), numeroTabulaciones + 1);
}


void eliminarSubarbol (Nodo *raizSubarbol) {
	assert(raizSubarbol != NULL);

	// Primero eliminamos los hijos, si los hay. Lo hacemos desde el último hasta el primero
	int numeroSubarboles = getNumeroHijos(raizSubarbol); // Número de hijos de la raizSubarbol
	for (int i = numeroSubarboles-1; i >=0; i--) {

		// Obtenemos el hijo que queremos borrar. Es O(hijos)
		Nodo *hijoActual = getHijo(raizSubarbol, i);

		// Si el hijoActual es primogénito (e hijo único), hacemos que su padre ya no apunte a él
		// Si no, hacemos que su hermano izquierdo ya no apunte a él.
		if (i == 0) hijoActual->padre->primerHijo=NULL;
		else getHijo(raizSubarbol, i - 1)->hermanoDerecho = NULL;

		// Finalmente, borramos al hijoActual
		eliminarSubarbol(hijoActual);		
	}
		
	// Finalmente eliminamos la raiz (caso trivial)
	// Los punteros hasta este nodo (de su padre y de su hijo izquierdo) no los tocamos
	// (asumimos que quien llame a eliminarSubarbol los pondrá a NULL antes o después de llamar a la funcion)
	free(raizSubarbol);
}


ArbolGenealogico *construirArbolGenealogico(char *nombre) {

	// Creamos el struct del árbol
	ArbolGenealogico* arbol = (ArbolGenealogico*)malloc(sizeof(ArbolGenealogico));
	arbol->n = 1;

	// Creamos el nodo raiz
	Nodo *raiz = (Nodo*)malloc(sizeof(Nodo)); // Creamos el nodo
	strcpy(raiz->contenido, nombre);
	raiz->padre = NULL;
	raiz->hermanoDerecho = NULL;
	raiz->primerHijo = NULL;

	// Ponemos el nodo en el árbol
	arbol->raiz = raiz;

	// Devolvemos el árbol
	return(arbol);
}


void insertarNombre (ArbolGenealogico *arbol, char* nuevoNombre, char* nombrePadre) {
	assert(arbol != NULL && arbol->n >= 0); // El arbol tiene sentido
	assert(arbol->n > 0 && arbol->raiz != NULL); // Arbol no vacío
	assert(nuevoNombre != NULL && nombrePadre != NULL);

	Nodo *padre = buscarNodo(arbol->raiz, nombrePadre); // Buscamos el padre del nodo que vamos a insertar
	assert(padre != NULL); // El padre debe existir en el arbol
	

	// Creamos el nuevo nodo que contendrá lo que queremos insertar en el árbol
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	strcpy(nuevoNodo->contenido, nuevoNombre);
	nuevoNodo->padre=padre;
	nuevoNodo->primerHijo = NULL;
	nuevoNodo->hermanoDerecho = NULL; // Lo insertaremos como último hijo de su padre

	// Hacemos que el nodo recién insertado sea el último hijo de su padre	
	int numeroHijos = getNumeroHijos(padre); // Numero de hijos que tiene el padre, antes de insertar el nuevo nodo
	if (numeroHijos == 0) padre->primerHijo = nuevoNodo; // Si el padre no tiene hijos, somos su primer hijo
	else {
		Nodo *ultimoHijo = getHijo(padre, numeroHijos-1); // Ultimo hijo del padre, antes de insertar el nuevo nodo
		ultimoHijo->hermanoDerecho = nuevoNodo; // Hacemos que el último hijo nos apunte, para que ahora lo seamos nosotros
	}

	arbol->n++;
}


void imprimir(ArbolGenealogico *arbol) {
	assert(arbol != NULL && arbol->n >= 0); // El arbol tiene sentido
	assert(arbol->n>0 && arbol->raiz != NULL); // Arbol no vacío
	imprimirRecursivo (arbol->raiz, 0);
} 


void destruirArbolGenealogico(ArbolGenealogico* arbol) {
	assert(arbol != NULL && arbol->n >= 0); // El arbol tiene sentido
	assert(arbol->n > 0 && arbol->raiz != NULL); // Arbol no vacío
	eliminarSubarbol(arbol->raiz);
	free(arbol);
}

