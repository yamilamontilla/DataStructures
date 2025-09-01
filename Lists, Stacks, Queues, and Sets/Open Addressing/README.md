# Open Addressing Hash Table with Linked Lists (Dispersión Abierta con Listas Enlazadas)

## Problem Statement  
Implement the Abstract Data Type (ADT) **StudentHashTable** in C using **open addressing** with **linked lists** to resolve collisions.  
Each student is represented by a **name** (char array) and a **student ID** (integer ≥ 0).  
Unlike closed addressing, each position in the hash table points to a linked list of students.  

## Objective  
Develop a hash table that:  
- Resolves collisions dynamically using linked lists.  
- Eliminates limitations on table occupancy.  
- Supports insertion, deletion, lookup, and retrieval of students efficiently.  
- Demonstrates modular design by combining linked lists and hash tables.  

## Program Files  

- **`TablaHashDeEstudiantes.c`** – Implements the hash table ADT:  
  - Constructor initializes a vector of linked lists  
  - Hashing function supporting two ideal positions per key  
  - Methods to insert, delete, check existence, and retrieve students  
  - Method `obtenerPosicionReal()` returns the actual list index and position in the list  
  - Print method shows all linked lists in the table  
- **`ListaEnlazada.c`** – Implements a **doubly circular linked list** of students, adapted from previous exercises:  
  - Nodes store `Estudiante` structs  
  - Modified `buscar()` to search by student ID  
  - Modified `imprimirListaEnlazada()` to print `(ID, Name)` pairs  
- **`impresionListasEnlazadas.c`** – Functions for printing linked lists  
- **`main.c`** – Test program with menu to insert, delete, check existence, retrieve, and print the table  

## Output  
- Prints the table as a series of linked lists, showing all students and their IDs.  
- Confirms insertion, deletion, and existence checks.  
- Retrieves student names given their ID.  

## Potential Applications  
- Database systems with high collision probability  
- Dynamic hashing for large datasets  
- Demonstrates advanced memory management, dynamic structures, and modular C programming.
