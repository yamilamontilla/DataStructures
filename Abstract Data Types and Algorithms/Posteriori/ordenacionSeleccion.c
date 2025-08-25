#include "assert.h"
#include "ordenacionSeleccion.h"

int buscarMinimo(int *vector, int n, int inicio, int fin) {
	// Precondiciones
	assert(n >= 0);
	assert(inicio >= 0);
	assert(inicio <= fin);
	assert(fin<n);
	assert(vector != NULL);

	// Inicializamos el m�nimo con el primer elemento
	int minimo = vector[inicio];
	int indiceMinimo = inicio;

	// Cada vez que encontremos un numero menor que el minimo que tenemos, actualizamos el m�nimo que tenemos con ese n�mero
	for (int i = inicio + 1; i <= fin; i++) {
		if (vector[i] < minimo) {
			minimo = vector[i];
			indiceMinimo = i;
		}
	}

	// Devolvemos la posici�n del m�nimo
	return (indiceMinimo);
}

void ordenarPorSeleccion(int *vector, int n) {
	assert(vector != NULL);
	assert(n >= 0);
	for (int i = 0; i<n; i++) {
		// Buscamos el minimo en lo que queda de vector hasta el final
		int posicionMinimo = buscarMinimo(vector, n, i, n - 1);

		// Ponemos el m�nimo en la posici�n adecuada del vector, y lo que hab�a all� lo ponemos en donde encontramos el m�nimo
		int temp = vector[i];
		vector[i] = vector[posicionMinimo];
		vector[posicionMinimo] = temp;
	}
}