#pragma once

typedef struct {
	char aeropuerto[20]; // Nombre del aeropuerto destino u origen, dependiendo de si la ruta es saliente o entrante.
	int kilometros;
	char empresa[20];
} Ruta;
