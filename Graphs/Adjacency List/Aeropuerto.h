#pragma once

#include "ListaEnlazada.h"

typedef struct {
	char nombre[20]; // Nombre del aeropuerto. Es su clave
	ListaEnlazada* rutasSalientes; // Lista de rutas salientes del aeropuerto
	ListaEnlazada* rutasEntrantes; // Lista de rutas entrantes al aeropuerto
} Aeropuerto;
