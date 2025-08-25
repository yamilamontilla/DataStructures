#include "stdio.h"
#include "ArbolGenealogico.h"

void main () {

	// Pedimos nuestro antepasado más lejano y creamos el árbol con él
	char antepasadoMasLejano[20]; // Contendra la raiz del arbol
	printf("Introduce tu antepasado mas lejano: ");
	scanf("%s", antepasadoMasLejano);
	ArbolGenealogico *arbol = construirArbolGenealogico(antepasadoMasLejano);

	int opcion;
	do {
				
		char nuevoNombre[20]; // Nuevo nombre que pedimos al usuario para insertar un nuevo nombre
		char nombrePadre[20]; // Nuevo padre que pedimos al usuario para insertar un nuevo nombre
		
		printf("0. Salir\n");
		printf("1. Insertar nuevo nombre\n");
		printf("2. Mostrar arbol genealogico\n");
		printf("Introduce opcion: ");
		scanf("%d", &opcion);

		switch (opcion) {
		case (0): // Terminar programa
			break;
		case (1):
			printf("Escriba el nuevo nombre: ");
			scanf("%s", nuevoNombre);
			printf("Escriba el nombre de su padre: ");
			scanf("%s", nombrePadre);
			insertarNombre(arbol, nuevoNombre, nombrePadre);
			break;
		case (2):
			imprimir(arbol);
			break;
		default:
			printf("Opcion incorrecta\n");
			break;
		}
	} while (opcion != 0);
	
	destruirArbolGenealogico(arbol);
}
