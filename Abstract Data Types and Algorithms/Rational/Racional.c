// Archivo que representa la implementaci�n de los algoritmos para manipular el TAD "Racional"

#include "Racional.h" // Para saber la definici�n del TAD y sus algoritmos
#include "stdio.h" // Para poder usar printf y scanf
#include "stdlib.h" // Para malloc
#include "math.h" // Para usar "abs()"
#include "assert.h" // Para utilizar la macro "assert()"


int calcularMaximoComunDivisor(int operando1, int operando2) {
	// assert sirve para comprobar que la precondici�n se cumple. Se pone como �nico par�metro
	// una expresi�n booleana. Si se eval�a como verdadero, no ocurre nada. Si se eval�a como falso,
	// se interrumpe el programa y se indica la precondici�n violada
	// Una precondici�n es una condici�n que el dise�ador asume que siempre se va a cumplir con un buen uso de la funci�n
	// Ejemplo: el dise�ador de un m�vil asume que �ste no se va a utilizar a m�s de 50 grados
	// En este caso, la precondici�n es que ambos par�metros de la funci�n sean n�meros naturales
	assert(operando1 >= 0 && operando2 >= 0);

	// Calculamos el m�ximo com�n divisor de dos naturales usando el algoritmo de Euclides
	while (operando2 != 0) {
		int resto = operando1 % operando2; // Resto de la divisi�n entera entre los dos operandos
		operando1 = operando2;
		operando2 = resto;
	}
	return(operando1);
}

Racional crearRacional(int nuevoNumerador, int nuevoDenominador) {
	assert(nuevoDenominador != 0);

	// Calculamos el signo de la fracci�n y lo ponemos en el numerador
	// Por lo tanto hacemos que el denominador siempre sea positivo
	if (nuevoDenominador < 0) {
		nuevoDenominador = -nuevoDenominador;
		nuevoNumerador = -nuevoNumerador;
	}

	// Creamos el numero Racional y lo inicializamos
	Racional r;
	r.numerador = nuevoNumerador;
	r.denominador = nuevoDenominador;

	// Devolvemos una copia
	return (r);
}

Racional sumar(Racional sumando1, Racional sumando2) {
	// Sacamos los numeradores y denominadores de los dos sumandos
	int numerador1 = sumando1.numerador;
	int denominador1 = sumando1.denominador;
	int numerador2 = sumando2.numerador;
	int denominador2 = sumando2.denominador;

	int nuevoDenominador; // Nuevo denominador de la fraccion resultante
	int nuevoNumerador;   // Nuevo numerador de la fracci�n resultante

	// El nuevo denominador com�n del resultado idealmente seria el m�nimo comun m�ltiplo, pero
	// para simplificar hacemos que sea la multiplicaci�n de ambos denominadores
	nuevoDenominador = denominador1 * denominador2;

	// A partir del nuevo denominador com�n, calculamos los nuevos numeradores de los sumandos
	numerador1 = numerador1 * denominador2;
	numerador2 = numerador2 * denominador1;

	// Calculamos el numerador del resultado
	nuevoNumerador = numerador1 + numerador2;

	// Creamos la fracci�n resultado y lo devolvemos
	Racional r;
	r.numerador = nuevoNumerador;
	r.denominador = nuevoDenominador;
	return (r);
}

Racional multiplicar(Racional multiplicador1, Racional multiplicador2) {
	// Calculamos el nuevo numerador y denominador del resultado
	int nuevoNumerador = multiplicador1.numerador * multiplicador2.numerador;
	int nuevoDenominador = multiplicador1.denominador * multiplicador2.denominador;

	// Creamos el resultado y lo devolvemos
	Racional r;
	r.numerador = nuevoNumerador;
	r.denominador = nuevoDenominador;
	return (r);
}

void simplificar(Racional* racional) {
	assert(racional != NULL);
	int maximoComunDivisor; // m�ximo com�n divisor del valor absoluto del denominador y del valor absoluto del denominador
	maximoComunDivisor = calcularMaximoComunDivisor(abs(racional->numerador), abs(racional->denominador));
	racional->numerador = racional->numerador / maximoComunDivisor;
	racional->denominador = racional->denominador / maximoComunDivisor;
}

void escribir(Racional racional) {
	if (racional.numerador == 0 || racional.denominador == 1) printf("%d", racional.numerador);
	else printf("%d/%d", racional.numerador, racional.denominador); // Se imprimen tres cosas seguidas por la pantalla
}
