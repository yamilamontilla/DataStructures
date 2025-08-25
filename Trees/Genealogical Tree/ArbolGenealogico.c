#include "ArbolGenealogico.h"
#include "assert.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h" // Para strcmp, strcpy


int getNumeroHijos(Nodo * padre) {
	assert(padre != NULL);

	Nodo *hijoActual = padre->primerHijo; // Hijo actual en el que estamos (inicialmente es el primero)
	int numeroHijosDirectos; // Resultado de la funci�n

	// Si no tiene ni siquiera un primer hijo, no tiene ning�n hijo
	if (hijoActual == NULL) numeroHijosDirectos = 0;

	// Si tiene hijos, vamos iterando por ellos (de hermano a hermano) para contar cu�ntos hay
	else {
		numeroHijosDirectos = 1; // Al menos tiene uno (el primer hijo)		
		// Vamos desplaz�ndonos al hermano derecho hasta que ya no podamos m�s
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

	// Si el sub�rbol est� vac�o, es obvio que el contenido buscado no est�
	if (raizSubarbol == NULL) return(NULL);

	// Primero buscamos en la propia raiz. Si encontramos el contenido ah�, hemos terminado
	if (strcmp(raizSubarbol->contenido, contenido) == 0) return (raizSubarbol);

	// Si no, buscamos en sus subarboles hijos. 
	// Retornamos directamente si lo encontramos en alguno de sus subarboles hijos
	else {
		int numeroSubarboles = getNumeroHijos(raizSubarbol); // N�mero de hijos de la raizSubarbol
		for (int i=0; i<numeroSubarboles; i++) {

			// Buscamos recursivamente en uno de los sub�rboles que cuelgan de la ra�z
			Nodo *resultado = buscarNodo(getHijo(raizSubarbol, i), contenido);
			
			// Si lo hemos encontrado en el sub�rbol, terminamos
			if (resultado != NULL) return (resultado);
		}
	}

	// Si hemos llegado hasta aqu�, no lo hemos encontrado en el sub�rbol actual
	return (NULL);
}


void imprimirRecursivo(Nodo *raizSubarbol, int numeroTabulaciones) {
	assert (raizSubarbol != NULL);
	assert(numeroTabulaciones >= 0);

	// Imprimimos el nodo raiz con el nivel pasado como parametro
	for (int i=0; i<numeroTabulaciones; i++) printf("\t");
	printf("%s\n", raizSubarbol->contenido);

	// Imprimimos cada uno de sus sub�rboles con una tabulacion mas
	int numeroSubarboles = getNumeroHijos(raizSubarbol); // N�mero de hijos de la raizSubarbol
	for (int i = 0; i < numeroSubarboles; i++) imprimirRecursivo(getHijo(raizSubarbol, i), numeroTabulaciones + 1);
}


void eliminarSubarbol (Nodo *raizSubarbol) {
	assert(raizSubarbol != NULL);

	// Primero eliminamos los hijos, si los hay. Lo hacemos desde el �ltimo hasta el primero
	int numeroSubarboles = getNumeroHijos(raizSubarbol); // N�mero de hijos de la raizSubarbol
	for (int i = numeroSubarboles-1; i >=0; i--) {

		// Obtenemos el hijo que queremos borrar. Es O(hijos)
		Nodo *hijoActual = getHijo(raizSubarbol, i);

		// Si el hijoActual es primog�nito (e hijo �nico), hacemos que su padre ya no apunte a �l
		// Si no, hacemos que su hermano izquierdo ya no apunte a �l.
		if (i == 0) hijoActual->padre->primerHijo=NULL;
		else getHijo(raizSubarbol, i - 1)->hermanoDerecho = NULL;

		// Finalmente, borramos al hijoActual
		eliminarSubarbol(hijoActual);		
	}
		
	// Finalmente eliminamos la raiz (caso trivial)
	// Los punteros hasta este nodo (de su padre y de su hijo izquierdo) no los tocamos
	// (asumimos que quien llame a eliminarSubarbol los pondr� a NULL antes o despu�s de llamar a la funcion)
	free(raizSubarbol);
}


ArbolGenealogico *construirArbolGenealogico(char *nombre) {

	// Creamos el struct del �rbol
	ArbolGenealogico* arbol = (ArbolGenealogico*)malloc(sizeof(ArbolGenealogico));
	arbol->n = 1;

	// Creamos el nodo raiz
	Nodo *raiz = (Nodo*)malloc(sizeof(Nodo)); // Creamos el nodo
	strcpy(raiz->contenido, nombre);
	raiz->padre = NULL;
	raiz->hermanoDerecho = NULL;
	raiz->primerHijo = NULL;

	// Ponemos el nodo en el �rbol
	arbol->raiz = raiz;

	// Devolvemos el �rbol
	return(arbol);
}


void insertarNombre (ArbolGenealogico *arbol, char* nuevoNombre, char* nombrePadre) {
	assert(arbol != NULL && arbol->n >= 0); // El arbol tiene sentido
	assert(arbol->n > 0 && arbol->raiz != NULL); // Arbol no vac�o
	assert(nuevoNombre != NULL && nombrePadre != NULL);

	Nodo *padre = buscarNodo(arbol->raiz, nombrePadre); // Buscamos el padre del nodo que vamos a insertar
	assert(padre != NULL); // El padre debe existir en el arbol
	

	// Creamos el nuevo nodo que contendr� lo que queremos insertar en el �rbol
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	strcpy(nuevoNodo->contenido, nuevoNombre);
	nuevoNodo->padre=padre;
	nuevoNodo->primerHijo = NULL;
	nuevoNodo->hermanoDerecho = NULL; // Lo insertaremos como �ltimo hijo de su padre

	// Hacemos que el nodo reci�n insertado sea el �ltimo hijo de su padre	
	int numeroHijos = getNumeroHijos(padre); // Numero de hijos que tiene el padre, antes de insertar el nuevo nodo
	if (numeroHijos == 0) padre->primerHijo = nuevoNodo; // Si el padre no tiene hijos, somos su primer hijo
	else {
		Nodo *ultimoHijo = getHijo(padre, numeroHijos-1); // Ultimo hijo del padre, antes de insertar el nuevo nodo
		ultimoHijo->hermanoDerecho = nuevoNodo; // Hacemos que el �ltimo hijo nos apunte, para que ahora lo seamos nosotros
	}

	arbol->n++;
}


void imprimir(ArbolGenealogico *arbol) {
	assert(arbol != NULL && arbol->n >= 0); // El arbol tiene sentido
	assert(arbol->n>0 && arbol->raiz != NULL); // Arbol no vac�o
	imprimirRecursivo (arbol->raiz, 0);
} 


void destruirArbolGenealogico(ArbolGenealogico* arbol) {
	assert(arbol != NULL && arbol->n >= 0); // El arbol tiene sentido
	assert(arbol->n > 0 && arbol->raiz != NULL); // Arbol no vac�o
	eliminarSubarbol(arbol->raiz);
	free(arbol);
}

