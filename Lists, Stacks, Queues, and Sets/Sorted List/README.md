# Sorted List (Lista Contigua Ordenada)

## Problem Statement  
Extend the previous **Resizable Contiguous List (ListaContigua)** to maintain its elements in **sorted order** at all times.  
The ADT **ListaContiguaOrdenada** uses the same struct as **ListaContigua**, but adds methods to ensure order and efficient search.

## Objective  
Develop a contiguous list that:  
- Automatically finds the correct insertion position using binary search  
- Maintains sorted order after insertions and deletions  
- Allows efficient searching and removal of elements by value  

This activity emphasizes recursive algorithms, binary search, and maintaining invariants in a data structure.

## Program Files  

- **`ListaContigua.c`** – Base implementation of the resizable contiguous list.  
- **`ListaContiguaOrdenada.c`** – Implements the ordered list ADT:  
  - `comprobarOrden()` checks that the list is sorted  
  - `ejecutarBusquedaBinaria()` performs a recursive binary search, returning the element’s position or the insertion index if not found  
  - `buscarEnOrdenada()` calls the binary search and returns -1 if the element does not exist  
  - `insertarEnOrden()` inserts a new element at the correct sorted position  
  - `eliminarElemento()` removes an element by value, locating it first via binary search  
- **`impresionListasContiguas.c`** – Prints the list with its size and capacity  
- **`main.c`** – Provides a menu to:  
  1. Exit  
  2. Insert a random number (50–100)  
  3. Search for a user-provided number  
  4. Delete a user-provided number  
  5. Print the list  

## Output  
- Displays the sorted list after insertions and deletions  
- Shows positions of found elements or informs if they are absent  
- Provides feedback after each operation from the menu  

## Potential Applications  
- Maintaining ordered datasets for fast search and insertion  
- Foundation for binary search trees, priority queues, or more complex data structures  
- Useful in situations where elements must remain sorted without requiring full re-sorting after every change
