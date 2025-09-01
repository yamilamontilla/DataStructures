# Singly Linked List (Lista Enlazada Simple)

## Problem Statement  
Implement the Abstract Data Type (ADT) **SinglyLinkedList** in C.  
Each node contains an integer element and a pointer to the next node.  
Unlike contiguous lists, memory is dynamically allocated for each node, so the list has no fixed capacity.  

## Objective  
Develop a reusable linked list data structure that supports:  
- Element access and modification  
- Insertion at any position  
- Deletion from any position  
- Efficient traversal and printing (through a helper library)  

This activity emphasizes dynamic memory management, pointer manipulation, and modular design.  

## Program Files  

- **`ListaEnlazada.c`** – Implements the singly linked list ADT:  
  - `getNodo()` returns the pointer to a node at a given position  
  - Constructor creates an empty list  
  - `setValor()` and `getValor()` to modify and access elements  
  - `insertar()` and `eliminar()` for adding/removing elements at any position  
  - Destructor frees all nodes  
- **`impresionListasEnlazadas.c`** – Provides `imprimirListaEnlazada()` to print the list  
  - Accesses elements via `getValor()`  
  - Complexity is higher than contiguous list printing due to sequential access  
- **`main.c`** – Test program demonstrating:  
  - Creating an empty list  
  - Inserting and deleting elements in various positions  
  - Accessing and modifying elements  
  - Printing the list after each operation  

## Output  
- Prints the list after insertions and deletions  
- Displays individual elements retrieved or modified  
- Confirms the correct behavior of all operations  

## Potential Applications  
- Dynamic sequences of data where size is unknown or changes frequently  
- Foundation for stacks, queues, and more advanced linked structures  
- Useful for learning pointers, dynamic memory, and list traversal in C
