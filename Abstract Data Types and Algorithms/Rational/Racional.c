// Archivo que representa la implementación de los algoritmos para manipular el TAD "Racional"

#include "Racional.h" // Para saber la definición del TAD y sus algoritmos
#include "stdio.h" // Para poder usar printf y scanf
#include "stdlib.h" // Para malloc
#include "math.h" // Para usar "abs()"
#include "assert.h" // Para utilizar la macro "assert()"


int calcularMaximoComunDivisor(int operando1, int operando2) {
	// assert sirve para comprobar que la precondición se cumple. Se pone como único parámetro
	// una expresión booleana. Si se evalúa como verdadero, no ocurre nada. Si se evalúa como falso,
	// se interrumpe el programa y se indica la precondición violada
	// Una precondición es una condición que el diseñador asume que siempre se va a cumplir con un buen uso de la función
	// Ejemplo: el diseñador de un móvil asume que éste no se va a utilizar a más de 50 grados
	// En este caso, la precondición es que ambos parámetros de la función sean números naturales
	assert(operando1 >= 0 && operando2 >= 0);

	// Calculamos el máximo común divisor de dos naturales usando el algoritmo de Euclides
	while (operando2 != 0) {
		int resto = operando1 % operando2; // Resto de la división entera entre los dos operandos
		operando1 = operando2;
		operando2 = resto;
	}
	return(operando1);
}

Racional crearRacional(int nuevoNumerador, int nuevoDenominador) {
	assert(nuevoDenominador != 0);

	// Calculamos el signo de la fracción y lo ponemos en el numerador
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
	int nuevoNumerador;   // Nuevo numerador de la fracción resultante

	// El nuevo denominador común del resultado idealmente seria el mínimo comun múltiplo, pero
	// para simplificar hacemos que sea la multiplicación de ambos denominadores
	nuevoDenominador = denominador1 * denominador2;

	// A partir del nuevo denominador común, calculamos los nuevos numeradores de los sumandos
	numerador1 = numerador1 * denominador2;
	numerador2 = numerador2 * denominador1;

	// Calculamos el numerador del resultado
	nuevoNumerador = numerador1 + numerador2;

	// Creamos la fracción resultado y lo devolvemos
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
	int maximoComunDivisor; // máximo común divisor del valor absoluto del denominador y del valor absoluto del denominador
	maximoComunDivisor = calcularMaximoComunDivisor(abs(racional->numerador), abs(racional->denominador));
	racional->numerador = racional->numerador / maximoComunDivisor;
	racional->denominador = racional->denominador / maximoComunDivisor;
}

void escribir(Racional racional) {
	if (racional.numerador == 0 || racional.denominador == 1) printf("%d", racional.numerador);
	else printf("%d/%d", racional.numerador, racional.denominador); // Se imprimen tres cosas seguidas por la pantalla
}
