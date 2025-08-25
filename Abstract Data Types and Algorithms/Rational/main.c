// Las líneas que empiezan por "//" son comentarios. 
// EjemploRacional: programa que hace algunas operaciones con fracciones

#include "stdio.h"
#include "Racional.h" // Incluyo el TAD "Racional" que me he creado

void main()
{
	// Variables para guardar numerador y denominador que capturamos por teclado
	int numerador, denominador;

	// Pedimos y creamos el primer racional
	do {
		printf("Introduzca numerador y denominador (separado por espacios) del racional a.\nEl denominador debe ser distinto de cero: ");
		scanf("%d", &numerador);
		scanf("%d", &denominador);
	} while (denominador == 0);
	
	// Creamos una variable de tipo "Racional" y la iniciamos
	Racional a = crearRacional(numerador, denominador);

	// Sobre el objeto "a", vamos a ejecutar uno de los algoritmos del TAD, en este caso el método "escribir()"
	printf("Racional a: ");
	escribir(a);
	printf("\n");

	// Pedimos y creamos el segundo racional
	do {
		printf("Introduzca numerador y denominador (separado por espacios) del racional b.\nEl denominador debe ser distinto de cero: ");
		scanf("%d", &numerador);
		scanf("%d", &denominador);
	} while (denominador == 0);

	// Creamos otro objeto de tipo "Racional" y lo guardamos en la variable "b". 
	Racional b = crearRacional(numerador, denominador);

	// Ejecutamos "escribir" sobre la fracción "b"
	printf("Racional b: ");
	escribir(b);
	printf("\n");
	
	// Realizamos la suma y lo imprimimos
	Racional resultado = sumar(a, b); // Resultado de las operaciones
	printf("Racional a+b: ");
	escribir(resultado);
	printf("\n");

	// Simplificamos y lo escribimos
	simplificar(&resultado);
	printf("Racional a+b simplificado: ");
	escribir(resultado);
	printf("\n");

	// Realizamos la multiplicación y lo escribimos
	Racional resultadoMultiplicacion = multiplicar(a, b); 
	printf("Racional a*b: ");
	escribir(resultadoMultiplicacion);
	printf("\n");

	// Simplificamos y lo escribimos
	simplificar(&resultadoMultiplicacion);
	printf("Racional a*b simplificado: ");
	escribir(resultadoMultiplicacion);
	printf("\n");

}
