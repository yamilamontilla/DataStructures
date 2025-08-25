#include "Grafo.h"
#include "assert.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"


int obtenerIndice(Grafo* grafo, char nombreNodo) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido

	// Si strchr() no encuentra el caracter, devuelve NULL.
	// Si lo encuentra, devuelve el puntero a su posición
	if (grafo->n == 0) return (-1); // Si el grafo está vacío, no está el nodo
	char* punteroNodo = strchr(grafo->nombresNodos, nombreNodo);
	if (punteroNodo == NULL) return -1; // No está el nodo
	else return (punteroNodo - grafo->nombresNodos); // Está. Devolvemos su índice.
}


int existeNodo(Grafo* grafo, char nombreNodo) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	int posicionNodo = obtenerIndice(grafo, nombreNodo);
	if (posicionNodo == -1) return (0);
	else return (1);
}


int existeArco(Grafo* grafo, char nombreNodoOrigen, char nombreNodoDestino) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	assert(existeNodo(grafo, nombreNodoOrigen));
	assert(existeNodo(grafo, nombreNodoDestino));

	int indiceNodoOrigen = obtenerIndice(grafo, nombreNodoOrigen);
	int indiceNodoDestino = obtenerIndice(grafo, nombreNodoDestino);
	ListaContigua* filaMatrizAdyacencia = grafo->matriz[indiceNodoOrigen];
	if (getValor(filaMatrizAdyacencia, indiceNodoDestino) > 0) return 1;
	else return 0;
}


Grafo* construirGrafo() {
	Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
	grafo->matriz = NULL;
	grafo->n = 0;
	grafo->nombresNodos = (char*)malloc(sizeof(char));
	grafo->nombresNodos[0] = '\0';
	return(grafo);
}


void destruirGrafo(Grafo* grafo) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	for (int i = 0; i < grafo->n; i++) destruirListaContigua(grafo->matriz[i]); // Destruimos cada fila
	free(grafo->matriz); // Destruimos los punteros a las filas
	free(grafo->nombresNodos); // Destruimos los nombres de los nodos
	free(grafo);
}


void insertarNodo(Grafo* grafo, char nombreNodo) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	assert(!existeNodo(grafo, nombreNodo));

	// Insertamos el nuevo nombre en la lista de nombres
	char nombreNodoEnString[2];
	nombreNodoEnString[0] = nombreNodo;
	nombreNodoEnString[1] = '\0';
	grafo->nombresNodos = (char*)realloc(grafo->nombresNodos, sizeof(char) * (grafo->n + 2)); // No olvidar espacio para '\0'
	strcat(grafo->nombresNodos, nombreNodoEnString);

	// Añadimos una columna mas a todas las filas que ya hay. Para ello, añadimos un 0 al final de cada fila
	// Complejidad temporal: O(n^2), porque cada insercion al final es O(n) pues puede que haya que incrementar capacidad
	for (int i = 0; i < grafo->n; i++) insertarAlFinal(grafo->matriz[i], 0);

	// Creamos la nueva fila y la rellenamos con ceros. Fijémonos en que ponemos n+1 elementos
	// Complejidad temporal: O(n^2), porque cada insercion al final es O(n) pues puede que haya que incrementar capacidad
	ListaContigua* nuevaFila = crearListaContigua();
	for (int i = 0; i < grafo->n + 1; i++) insertarAlFinal(nuevaFila, 0);

	// Añadimos la nueva fila al resto de filas. Para ello primero tenemos que ampliar el espacio de matriz
	// Complejidad temporal O(n), para ampliar el espacio
	grafo->matriz = (ListaContigua**)realloc(grafo->matriz, (grafo->n + 1) * sizeof(ListaContigua*));
	grafo->matriz[grafo->n] = nuevaFila;

	// Incrementamos n
	grafo->n++;
}


void insertarArco(Grafo* grafo, char nodoOrigen, char nodoDestino) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	assert(existeNodo(grafo, nodoOrigen));
	assert(existeNodo(grafo, nodoDestino));
	assert(!existeArco(grafo, nodoOrigen, nodoDestino));

	int posicionNodoOrigen = obtenerIndice(grafo, nodoOrigen);
	int posicionNodoDestino = obtenerIndice(grafo, nodoDestino);
	ListaContigua* fila = grafo->matriz[posicionNodoOrigen];
	setValor(fila, posicionNodoDestino, 1);
}


void borrarNodo(Grafo* grafo, char nombreNodo) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	assert(existeNodo(grafo, nombreNodo));

	// Borrar el nodo de la lista de nodos. Al usar memmove, recordar que también se tiene que copiar el carácter nulo del final
	int posicionNodo = obtenerIndice(grafo, nombreNodo); // Indice del nodo
	memmove(&grafo->nombresNodos[posicionNodo], &grafo->nombresNodos[posicionNodo + 1], sizeof(char) * (grafo->n - posicionNodo));

	// Borramos la fila del nodo
	destruirListaContigua(grafo->matriz[posicionNodo]);
	memmove(&grafo->matriz[posicionNodo], &grafo->matriz[posicionNodo + 1], sizeof(ListaContigua*) * (grafo->n - posicionNodo - 1));
	grafo->matriz = (ListaContigua**)realloc(grafo->matriz, sizeof(ListaContigua*) * grafo->n); // Antes era n+1, no olvidar espacio para '\0'

	// Borramos la columna (borramos la misma posición en todas las filas). O(n^2)
	for (int i = 0; i < grafo->n - 1; i++) eliminar(grafo->matriz[i], posicionNodo);

	// Actualizamos n
	grafo->n--;
}


void borrarArco(Grafo* grafo, char nodoOrigen, char nodoDestino) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	assert(existeNodo(grafo, nodoOrigen));
	assert(existeNodo(grafo, nodoDestino));
	assert(existeArco(grafo, nodoOrigen, nodoDestino));

	int posicionNodoOrigen = obtenerIndice(grafo, nodoOrigen);
	int posicionNodoDestino = obtenerIndice(grafo, nodoDestino);
	ListaContigua* fila = grafo->matriz[posicionNodoOrigen];
	setValor(fila, posicionNodoDestino, 0);
}


void imprimir(Grafo* grafo) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido

	// Si el grafo está vacio, imprimimos mensaje informativo
	if (grafo->n == 0) printf("La matriz esta vacia\n");

	// En caso contrario, imprimimos la matriz de adyacencia bien alineada
	else {

		// Imprimimos la primera línea de la matriz, con los nombres de los nodos
		printf("  "); // Imprimimos espacio de la esquina superior izquierda de la matriz	
		for (int i = 0; i < grafo->n; i++) printf("%c ", grafo->nombresNodos[i]); // Imprimimos el nombre de los nodos en las columnas
		printf("\n");

		// Imprimimos las filas
		for (int i = 0; i < grafo->n; i++) {
			char nombreNodoOrigen = grafo->nombresNodos[i];
			printf("%c ", nombreNodoOrigen); // Imprimimos el nombre del nodo de la fila
			for (int j = 0; j < grafo->n; j++) {
				char nombreNodoDestino = grafo->nombresNodos[j];
				printf("%d ", existeArco(grafo, nombreNodoOrigen, nombreNodoDestino));
			}
			printf("\n");
		}
		printf("\n");
	}
}


char* recorrerEnProfundidadRecursivo(Grafo* grafo, int indiceNodoInicial, int* vistos) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	assert(indiceNodoInicial >= 0 && indiceNodoInicial <= grafo->n - 1);
	assert(vistos != NULL);

	// Creamos el array resultado y metemos en él el nombre del nodo inicial
	char *resultado = (char*)malloc(sizeof(char)*(grafo->n+1)); // Resultado que contendrá el recorrido
	char nombreNodoInicial = grafo->nombresNodos[indiceNodoInicial];
	resultado[0] = nombreNodoInicial;
	resultado[1] = '\0';

	// Marcamos el nodo inicial como visto
	vistos[indiceNodoInicial] = 1; 

	// Vemos los nodos inmediatamente consecutivos al inicial y nos llamamos recursivamente
	// con cualquiera de ellos que aún no hayamos visto
	for (int indiceNodoDestino = 0; indiceNodoDestino < grafo->n; indiceNodoDestino++) {

		// Si el posible nodo consecutivo no está aún visto
		if (vistos[indiceNodoDestino] == 0) {

			// Si existe un arco del nodo origen al nodo destino "no visto", nos llamamos recursivamente
			// con el nodo destino como nuevo origen
			char nombreNodoDestino = grafo->nombresNodos[indiceNodoDestino];
			if (existeArco(grafo, nombreNodoInicial, nombreNodoDestino)) {
				char* recorridoRestante = recorrerEnProfundidadRecursivo(grafo, indiceNodoDestino, vistos);
				strcat(resultado, recorridoRestante);
				free(recorridoRestante);
			}
		}
	}
	return (resultado);
}


char* recorrerEnProfundidad(Grafo *grafo, char nodoInicial) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	assert(existeNodo(grafo, nodoInicial));

	// Indice del nodo inicial
	int indiceNodoInicial = obtenerIndice(grafo, nodoInicial);

	// Creamos el array que nos dice si un nodo ha sido visto o no, y lo inicializamos a falso
	int* vistos = (int*)malloc(sizeof(int) * grafo->n); // Array que nos dice si un nodo ha sido visto o no
	for (int i = 0; i < grafo->n; i++) vistos[i] = 0;

	// Recorremos en profundidad el grafo y guardamos el tamaño del recorrido
	char *resultado = recorrerEnProfundidadRecursivo(grafo, indiceNodoInicial, vistos);
	int longitudRecorrido = strlen(resultado); // Numero de nodos que tiene el recorrido

	// Liberamos el array de vistos
	free(vistos);

	// Devolvemos el recorrido
	return (resultado); // Devolvemos el array de caracteres resultado del recorrido en profundidad
}



int getGradoEntrada(Grafo *grafo, int posicionNodo) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	assert(posicionNodo >= 0 && posicionNodo <= grafo->n - 1);

	int resultado = 0; // Contador resultado
	char nombreNodoDestino = grafo->nombresNodos[posicionNodo];
	for (int i = 0; i < grafo->n; i++) {
		char nombreNodoOrigen = grafo->nombresNodos[i];
		if (existeArco(grafo, nombreNodoOrigen, nombreNodoDestino)) resultado++;
	}
	return(resultado);
}


char* recorrerTopologicoRecursivo(Grafo* grafo) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido

	char* resultado = (char*)malloc(sizeof(char)*(grafo->n + 1)); // Recorrido resultado
	resultado[0] = '\0'; // Lo inicializamos a texto vacío

	// Encontramos un nodo cuyo grado de entrada sea 0
	int posicionNodo = -1;
	for (int i = 0; i < grafo->n && posicionNodo == -1; i++) {
		if (getGradoEntrada(grafo, i) == 0) posicionNodo = i;
	}

	// Caso trivial si no hay nodo con grado de entrada 0 (o si ya no quedan nodos)
	if (posicionNodo != -1) {

		// Lo ponemos en el resultado
		char nombreNodo = grafo->nombresNodos[posicionNodo];
		resultado[0] = nombreNodo;
		resultado[1] = '\0';

		// Eliminamos el nodo (y automaticamente sus arcos de salida)
		borrarNodo(grafo, nombreNodo);

		// Volvemos a empezar y añadimos el resultado
		char* recorridoRestante = recorrerTopologicoRecursivo(grafo);
		strcat(resultado, recorridoRestante);
		free(recorridoRestante);
	}

	// Devolvemos el resultado
	return(resultado);
}


char* recorrerTopologico(Grafo* grafo) {
	assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido

	// Copiamos el grafo actual para restaurarlo al acabar el método
	// OJO: No es tan sencillo como copiar una estructura en otra, ya que entonces sólo copiaríamos punteros
	// Creamos el grafo, insertamos los nodos, e insertamos los arcos
	Grafo *grafoTemp = construirGrafo();
	int n = grafo->n;
	for (int i = 0; i < n; i++) insertarNodo(grafoTemp, grafo->nombresNodos[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char nombreNodoOrigen = grafo->nombresNodos[i];
			char nombreNodoDestino = grafo->nombresNodos[j];
			if (existeArco(grafo, nombreNodoOrigen, nombreNodoDestino))
				insertarArco(grafoTemp, nombreNodoOrigen, nombreNodoDestino);
		}
	}
			 
	// Obtenemos el recorrido topológico, destruyendo el grafo temporal en el proceso
	char* resultado = recorrerTopologicoRecursivo(grafoTemp); // Recorrido resultado

	// Destruimos el grafo temporal y devolvemos el resultado
	destruirGrafo(grafoTemp);
	return(resultado);
}
