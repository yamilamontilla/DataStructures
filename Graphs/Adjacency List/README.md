# EspacioAereo (Airspace) – Adjacency List

## Problem Statement  
Implement the Abstract Data Type (ADT) **EspacioAereo** (Airspace) in C using an adjacency list representation.  
The ADT models a directed graph of **aeropuertos** (airports) interconnected by **rutas aéreas** (flight routes). Each airport stores lists of **rutas salientes** (outgoing routes) and **rutas entrantes** (incoming routes). Routes are labeled with **kilómetros** (distance in kilometers) and the **compañía aérea** (airline company) operating them.  

## Objective  
Create a modular and dynamic graph structure that allows:  
- Insertion and deletion of **aeropuertos** (airports) and **rutas** (routes).  
- Visualization of the complete **espacio aéreo** (airspace).  
- Checking the existence of airports and specific routes.  

## Program Files  

- **`Aeropuerto.h`** – Defines the `Aeropuerto` (Airport) structure with **nombre del aeropuerto** (airport name), list of outgoing routes, and list of incoming routes.  
- **`Ruta.h`** – Defines the `Ruta` (Route) structure with **aeropuerto destino/origen** (destination/origin airport), distance, and airline company.  
- **`ListaContigua.c`** – Adapted module to store airports in a contiguous list.  
- **`ListaEnlazada.c`** – Adapted module to store routes in a circular doubly linked list.  
- **`impresionListasEnlazadas.c`** – Functions to print linked lists of routes.  
- **`EspacioAereo.c`** – Implements ADT operations: insert/delete airports, insert/delete routes, print the graph, check existence of airports and routes.  
- **`main.c`** – Test program demonstrating creation, modification, and printing of the **espacio aéreo** (airspace).  

All files are interconnected: `main.c` uses the interface in `EspacioAereo.h`, which relies on the **Aeropuerto**, **Ruta**, and list modules.  

## Output  
- Prints the complete **espacio aéreo** (airspace) graph, showing each airport and its outgoing and incoming routes with distances and airlines.  
- Demonstrates graph changes after insertion and deletion of airports and routes.  
- Displays intermediate states of the network, reflecting modifications in real time.  

## Potential Applications  
- Modeling and managing airline networks (**red de aeropuertos y rutas aéreas** / (**network of airports and air routes**).  
- Teaching example of adjacency list representation for directed, labeled graphs.  
- Useful for transportation network simulations and connectivity analysis.
