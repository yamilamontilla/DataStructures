// Archivo que representa la declaraci�n del TAD "Racional" (una fracci�n)

// Datos del TAD: numerador y denominador
// Nomenclatura Java: 
// - El nombre de la estructura empieza con may�sculas. El resto de elementos (variables, funciones) empieza con min�scula
// - Los nombres formados por varias palabras se ponen todas juntas, pero empezando cada una (excepto la primera) con may�scula
// - Los nombres de estructuras tienen que ser nombres, los nombres de funciones son verbos, los nombres de variables son nombres/verbos
typedef struct { 
	int numerador; // Numerador
	int denominador; // Denominador. Precondici�n: denominador > 0
} Racional;

// Calcula el m�ximo com�n divisor de dos operandos naturales, usando el algoritmo de Euclides
// Par�metros:
// - operando1: primer operando
// - operando2: segundo operando
// Retorno: m�ximo com�n divisor de los dos operandos pasados como argumento
// Precondiciones: operando1 >= 0 && operando2 >= 0 (ambos n�meros naturales)
int calcularMaximoComunDivisor(int operando1, int operando2);

/* Constructor que construye un numero racional a partir de dos enteros (que ser�n el numerador y denominador)
Par�metros:
- nuevoNumerador: el numerador inicial de la fracci�n
- nuevoDenominador: el denominador inicial de la fracci�n 
Retorno: el racional reci�n creado
Precondici�n: nuevoDenominador != 0 */
Racional crearRacional(int nuevoNumerador, int nuevoDenominador);

/* Suma dos racionales y devuelve un nuevo racional con el resultado de la suma
Par�metros: 
- sumando1: primer sumando
- sumando2: segundo sumando
Retorno: un nuevo racional, fruto de sumar "sumando1" y "sumando2" */
Racional sumar(Racional sumando1, Racional sumando2);

/* Multiplica dos racionales y devuelve un nuevo racional con el resultado de la multiplicaci�n
Par�metros: 
- multiplicador1: primer multiplicador
- multiplicador2: segundo multiplicador
Retorno: un nuevo racional, fruto de multiplicar "multiplicador1" y "multiplicador2" */
Racional multiplicar(Racional multiplicador1, Racional multiplicador2);

/* Simplifica al maximo una fracci�n dada. La fracci�n queda modificada por dentro
Par�metro: puntero al n�mero racional que se quiere simplificar 
Precondici�n: racional != NULL */
void simplificar(Racional *racional);

/* Imprime por pantalla la fracci�n que representa al numero racional actual. Formato n/d.
Si el numerador es 0 � el denominador es 1 s�lo se escribe el numerador.
OJO: esto es un m�todo de interfaz, puramente inform�tico. El resto de funciones de este archivo son "de modelo".
     El TAD en s� mismo es modelo tambi�n
     Lo ideal es no menclar funciones de interfaz y de "modelo" en el mismo archivo
Par�metro:n�mero racional que se quiere imprimir por pantalla */
void escribir(Racional racional);

