#pragma once

// Devuelve la posici�n del menor elemento encontrado entre la posicion "inicio" y la posicion "fin" de un vector, ambos l�mites inclusive
// Par�metros:
// - vector: puntero al inicio del vector
// - n: n�mero de componentes del vector
// - inicio: posici�n (inclusive) desde la que buscar el m�nimo
// - fin: posici�n (inclusive) hasta la cual buscar el m�nimo
// Retorno: posici�n del m�nimo encontrado en el rango [inicio,fin]
// Precondiciones: n>=0 && inicio >= 0 && fin < n && inicio <= fin && vector != NULL
int buscarMinimo(int *vector, int n, int inicio, int fin);

// Ordena un vector de menor a mayor usando el m�todo de selecci�n
// (https://es.wikipedia.org/wiki/Ordenamiento_por_selecci%C3%B3n)
// Par�metros:
// - vector: puntero al inicio del vector
// - n: numero de componentes del vector
// Precondiciones: n>=0 && vector != NULL
void ordenarPorSeleccion(int *vector, int n);
