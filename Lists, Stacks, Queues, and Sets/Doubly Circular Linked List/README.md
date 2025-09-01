# Doubly Circular Linked List (Lista Doblemente Enlazada Circular)

## Problem Statement  
Modify the simple linked list ADT to create a **doubly circular linked list**.  
The ADT now allows bidirectional traversal and maintains a reference to the last accessed node to optimize sequential operations.  

## Objective  
Enhance the original singly linked list to:  
- Allow O(1) access to consecutive nodes via caching the last accessed node.  
- Optimize operations such as printing, concatenation, and search.  
- Preserve the public interface of the original singly linked list for backward compatibility.  

## Program Files  

- **`ListaEnlazada.c`** – Implements the doubly circular linked list ADT with optimized `getNodo()` for bidirectional traversal, concatenation, and search.  
- **`impresionListasEnlazadas.c`** – Provides functions to print the list, showing elements in order.  
- **`main.c`** – Test program demonstrating all operations: insertion, deletion, sequential access, concatenation, and search.  

These files are interconnected: `main.c` uses the interface defined in the headers, which is implemented in the respective `.c` files.  

## Output  
- Prints the list contents after insertions and deletions.  
- Demonstrates O(1) access for consecutive nodes via caching.  
- Shows the result of concatenating two lists.  
- Displays search results for existing and non-existing elements.  

## Potential Applications  
- Efficient dynamic data structures for scenarios requiring bidirectional traversal.  
- Foundation for more complex linked structures such as deques, adjacency lists in graphs, or undo-redo systems.  
- Demonstrates memory-safe pointer manipulation and optimized node access in C.  
