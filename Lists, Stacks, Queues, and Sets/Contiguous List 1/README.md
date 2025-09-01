# Contiguous List 1 (Lista Contigua de Enteros)

## Problem Statement  
Implement the Abstract Data Type (ADT) **ListaContigua** in C and test all its methods with a `main` program.  
The ADT represents a **contiguous list of integers**, which automatically resizes when elements are added or removed.  

## Objective  
Develop a dynamic, resizable list structure that efficiently stores integers in contiguous memory.  
The project emphasizes memory management, dynamic resizing, and separation of **model** (core list operations) from **interface** (printing and visualization).  

## Program Files  

- **`ListaContigua.c`** – Implements the `ListaContigua` ADT, including constructor, destructor, insertion, deletion, access, modification, and resizing operations.  
- **`impresionListasContiguas.c`** – Provides functions to print the contents of a `ListaContigua`, including size and capacity, respecting separation of model and interface.  
- **`main.c`** – Test program that demonstrates all `ListaContigua` operations: creating the list, inserting elements, deleting elements, resizing, and printing.  

These files are interconnected: `main.c` uses the interface defined in the header files, which are implemented in the respective `.c` files.  

## Output  
- Prints the list size, capacity, and elements after each insertion or deletion.  
- Demonstrates automatic resizing: growing when full and shrinking when underutilized.  
- Shows direct access and modification of specific elements in the list.  

## Potential Applications  
- Dynamic arrays for storing integers or other data types (with minor modifications).  
- Foundation for more advanced data structures such as stacks, queues, or hash tables.  
- Illustrates memory management, dynamic allocation (`malloc`, `realloc`, `free`), and safe manipulation of contiguous memory in C.  
