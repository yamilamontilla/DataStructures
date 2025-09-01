# Closed Addressing (Tablas Hash con Colisiones)

## Problem Statement  
Implement the Abstract Data Type (ADT) **TablaHashDeEstudiantes** in C and test all its methods with a `main` program.  
The ADT represents a **hash table of students** that handles collisions using **closed addressing** (linear probing).  
It supports insertion, deletion, and search operations while maintaining internal flags for empty, occupied, or deleted slots.  

## Objective  
Develop a reusable hash table structure capable of handling key collisions efficiently.  
The program demonstrates proper collision resolution, deletion with flags, and retrieval of elements based on unique keys.  

## Program Files  

- **`TablaHashDeEstudiantes.c`** – Implements all hash table functions: insertion, deletion, search, collision handling, and printing.  
- **`TablaHashDeEstudiantes.h`** – Header file containing the `Estudiante` and hash table structure definitions and function prototypes.  
- **`main.c`** – Test program that creates a hash table of students, executes insertion, deletion, and search operations, and prints the table contents.  

These files are interconnected: `main.c` uses the interface defined in `TablaHashDeEstudiantes.h`, which is implemented in `TablaHashDeEstudiantes.c`.  

## Output  
- Displays the contents of the hash table, including the **Borrado / Deleted** flag for each slot.  
- Performs insertion and search operations, showing collision resolution in action.  
- Handles deletion correctly without disrupting the search of remaining elements.  

## Potential Applications  
- Managing student records or other datasets with unique keys.  
- Illustrates key **hash table concepts**: collisions, linear probing, and deletion handling.  
- Foundation for more advanced data structures like dynamic hash tables or open addressing schemes.  
