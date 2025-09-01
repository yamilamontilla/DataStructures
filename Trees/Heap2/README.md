# Heap2 (Montículo con Borrar y Heap Sort)

## Problem Statement
Extend the **Heap2** ADT from Heap1 in C to support **deletion of the root** and **retrieval of the root** without removing it.  
Additionally, implement a **heap-based sorting algorithm** (`ordenarPorMonticulo`) that sorts an array of integers using a temporary heap.

## Objective
Enhance the heap implementation to allow:

- Efficient removal of the minimum element (root) while maintaining the heap property.  
- Access to the root element without deletion.  
- Sorting an arbitrary list of integers using a heap (heap sort).

The program demonstrates array-based heap manipulation, restructuring after deletions, and heap-based sorting.

## Program Files

- **`Monticulo.c`** – Implements heap operations including `insertar`, `borrar`, `getRaiz`, `reestructurar`, and `ordenarPorMonticulo`.  
- **`Monticulo.h`** – Header file with function prototypes for all heap operations; no new struct is defined, as it reuses `ListaContigua`.  
- **`ListaContigua.c``** – Reused contiguous list ADT for underlying storage.  
- **`impresionListasContiguas.c``** – Utility functions for printing contiguous lists in tree format.  
- **`main.c`** – Test program that:

  1. Inserts elements sequentially to form a heap, printing after each insertion.  
  2. Deletes the root twice, printing the heap after each deletion.  
  3. Creates a contiguous list of 20 random integers (50–100), prints it, sorts it using `ordenarPorMonticulo`, and prints the sorted list.

These files are interconnected: `main.c` uses the interface defined in `Monticulo.h`, which internally uses `ListaContigua` and printing utilities.

## Output

- Displays the heap as a structured tree after each insertion and deletion.  
- Correctly removes the root while maintaining the min-heap property.  
- Prints the root element without deleting it using `getRaiz`.  
- Shows the initial and sorted random array using heap sort.

## Potential Applications

- Priority queues with dynamic insertion and deletion.  
- Efficient sorting of arrays using heap-based algorithms.  
- Illustrates array-based heap operations, recursive restructuring, and temporary memory usage for sorting.
