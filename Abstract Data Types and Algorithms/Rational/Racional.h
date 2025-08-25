// Archivo que representa la declaración del TAD "Racional" (una fracción)

// Datos del TAD: numerador y denominador
// Nomenclatura Java: 
// - El nombre de la estructura empieza con mayúsculas. El resto de elementos (variables, funciones) empieza con minúscula
// - Los nombres formados por varias palabras se ponen todas juntas, pero empezando cada una (excepto la primera) con mayúscula
// - Los nombres de estructuras tienen que ser nombres, los nombres de funciones son verbos, los nombres de variables son nombres/verbos
typedef struct { 
	int numerador; // Numerador
	int denominador; // Denominador. Precondición: denominador > 0
} Racional;

// Calcula el máximo común divisor de dos operandos naturales, usando el algoritmo de Euclides
// Parámetros:
// - operando1: primer operando
// - operando2: segundo operando
// Retorno: máximo común divisor de los dos operandos pasados como argumento
// Precondiciones: operando1 >= 0 && operando2 >= 0 (ambos números naturales)
int calcularMaximoComunDivisor(int operando1, int operando2);

/* Constructor que construye un numero racional a partir de dos enteros (que serán el numerador y denominador)
Parámetros:
- nuevoNumerador: el numerador inicial de la fracción
- nuevoDenominador: el denominador inicial de la fracción 
Retorno: el racional recién creado
Precondición: nuevoDenominador != 0 */
Racional crearRacional(int nuevoNumerador, int nuevoDenominador);

/* Suma dos racionales y devuelve un nuevo racional con el resultado de la suma
Parámetros: 
- sumando1: primer sumando
- sumando2: segundo sumando
Retorno: un nuevo racional, fruto de sumar "sumando1" y "sumando2" */
Racional sumar(Racional sumando1, Racional sumando2);

/* Multiplica dos racionales y devuelve un nuevo racional con el resultado de la multiplicación
Parámetros: 
- multiplicador1: primer multiplicador
- multiplicador2: segundo multiplicador
Retorno: un nuevo racional, fruto de multiplicar "multiplicador1" y "multiplicador2" */
Racional multiplicar(Racional multiplicador1, Racional multiplicador2);

/* Simplifica al maximo una fracción dada. La fracción queda modificada por dentro
Parámetro: puntero al número racional que se quiere simplificar 
Precondición: racional != NULL */
void simplificar(Racional *racional);

/* Imprime por pantalla la fracción que representa al numero racional actual. Formato n/d.
Si el numerador es 0 ó el denominador es 1 sólo se escribe el numerador.
OJO: esto es un método de interfaz, puramente informático. El resto de funciones de este archivo son "de modelo".
     El TAD en sí mismo es modelo también
     Lo ideal es no menclar funciones de interfaz y de "modelo" en el mismo archivo
Parámetro:número racional que se quiere imprimir por pantalla */
void escribir(Racional racional);

