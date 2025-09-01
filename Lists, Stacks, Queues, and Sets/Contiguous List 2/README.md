# Contiguous List 2 (Lista Contigua de Enteros – Extensión)

## Problem Statement  
Extend the Abstract Data Type (ADT) **ListaContigua** from Contiguous List 1 with additional operations:  
- Insert at a specific position.  
- Delete from a specific position.  
- Concatenate two lists.  
- Search for an element.  

This ADT represents a **dynamic contiguous list of integers**, now with more flexible insertion, deletion, and search capabilities.  

## Objective  
Enhance the `ListaContigua` ADT to support advanced operations, including positional manipulation and concatenation, while maintaining automatic resizing and memory safety.  
The project emphasizes **modular design**, **memory management**, and **algorithmic thinking** (sequential search, copying arrays, shifting elements with `memmove`).  

## Program Files  

- **`ListaContigua.c`** – Implements the extended `ListaContigua` ADT with new methods for insertion at position, deletion at position, concatenation, and search.  
- **`impresionListasContiguas.c`** – Provides functions to print the list contents, including size and capacity.  
- **`main.c`** – Test program demonstrating all operations: insertion at any position, deletion, sequential search, concatenation, and automatic resizing.  

These files are interconnected: `main.c` uses the interface defined in the headers, which is implemented in the respective `.c` files.  

## Output  
- Prints the list size, capacity, and elements after each operation.  
- Shows insertion at the beginning, middle, and end of the list.  
- Demonstrates deletion from specific positions and automatic resizing.  
- Displays search results for existing and non-existing elements.  
- Prints the final result after concatenating two lists.  

## Potential Applications  
- Dynamic arrays that allow flexible insertions and deletions.  
- Foundation for more complex data structures (stacks, queues, or custom collections).  
- Demonstrates memory-safe array manipulations using `memmove` and sequential search.  
- Teaches efficient handling of contiguous memory in C with dynamic allocation and resizing.  
