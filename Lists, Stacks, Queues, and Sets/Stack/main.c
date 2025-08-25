#include "stdio.h"
#include "Pila.h"
#include "impresionListasEnlazadas.h"

void main () {

	ListaEnlazada *pila = construirListaEnlazada(); // Creación de la pila que utilizaremos
	
	// Imprimimos el menú
	printf("MENU:\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Cima\n");
	printf("4. Salir\n");

	int teclaPulsada; // Contendrá la tecla que pulsamos (de 1 a 4)
	do {

		// Pedimos la opción
		printf("Por favor, introduce una opcion del 1 al 4: ");
		scanf("%d", &teclaPulsada);

		switch (teclaPulsada) {
		case (1):
			int numeroIntroducido; // Numero que introduciremos por teclado cuando hagamos push
			printf("Introduce un numero: ");
			scanf("%d", &numeroIntroducido);
			push(pila, numeroIntroducido);
			printf("Pila completa: ");
			imprimirListaEnlazada(pila);
			break;
		
		case (2):
			if (isVacia(pila)) printf("La pila esta vacia, por lo tanto no se puede hacer pop\n");
			else printf("La cima de la pila es %d\n", pop(pila));
			printf("Pila completa: ");
			imprimirListaEnlazada(pila);
			break;
		
		case (3):
			if (isVacia(pila)) printf("La pila esta vacia, por lo tanto no se puede ver la cima\n");
			else printf("La cima de la pila es %d\n", verCima(pila));
			printf("Pila completa: ");
			imprimirListaEnlazada(pila);
			break;
		} // Fin switch

	} while (teclaPulsada != 4);

	destruirListaEnlazada(pila); // Que no se nos olvide destruir la pila
}


