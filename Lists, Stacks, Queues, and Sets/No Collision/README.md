# No Collision Hash Table (Tabla Hash sin Colisiones)

## Problem Statement  
Implement the Abstract Data Type (ADT) **StudentHashTable** in C without handling collisions.  
Each student is represented by a **name** (fixed-size char array) and a **student ID** (integer ≥ 0).  
The table maps each student ID to a unique position in the hash table, assuming no collisions occur.  

## Objective  
Create a simple hash table that allows:  
- Fast insertion, deletion, and retrieval of students by ID.  
- Direct access using a simple hash function (modulus with table capacity).  
- Visualization of table contents including empty positions.  

## Program Files  

- **`TablaHashDeEstudiantes.c`** – Implements the hash table ADT, including:  
  - Constructor and destructor  
  - Hash function (`obtenerPosicionIdeal`)  
  - Insert, delete, check existence, and get student  
  - Print table contents, including empty positions  
- **`main.c`** – Test program demonstrating all operations via a menu-driven interface.  

The files are interconnected: `main.c` uses the interface defined in the header, which is implemented in `TablaHashDeEstudiantes.c`.  

## Output  
- Prints the table showing each position, occupied flag, student ID, and student name.  
- Confirms insertion, deletion, and existence checks for students.  
- Retrieves student names given their ID.  

## Potential Applications  
- Basic database for student records with unique keys.  
- Foundation for more advanced hash tables with collision handling.  
- Demonstrates memory management, string handling, and modular C programming.
