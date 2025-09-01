# Heap1 (Montículo 1)

## Problem Statement
Implement the Abstract Data Type (ADT) **Heap1** in C, where each element is less than or equal to all its descendants (duplicates are allowed).  
Unlike previous tree exercises, the internal representation uses a **contiguous array** (`ListaContigua`) instead of linked nodes, interpreting the array as a complete binary tree.

## Objective
Develop a reusable heap structure to maintain the **min-heap property**.  
The program demonstrates recursive validation of the heap property, insertion with automatic reordering, and array-based tree traversal.

## Program Files

- **`Monticulo.c`** – Implements all heap operations, including insertion, printing, and recursive heap verification.  
- **`Monticulo.h`** – Header file containing function prototypes for heap operations; no new struct is defined, as it reuses `ListaContigua`.  
- **`ListaContigua.c``** – Reused contiguous list ADT for underlying storage.  
- **`main.c`** – Test program that builds a heap from a static array (3, 4, 6, 7, 5, 2), inserting elements sequentially and printing the heap after each insertion.

These files are interconnected: `main.c` uses the interface defined in `Monticulo.h`, which internally uses `ListaContigua` functions implemented in `ListaContigua.c`.

## Output

- Displays the heap as a **structured tree**, representing the array as a binary tree.  
- After each insertion, prints the current heap state.  
- Validates the min-heap property recursively to ensure correctness after each operation.

## Potential Applications

- Priority queues or task scheduling where the minimum element needs to be efficiently accessible.  
- Illustrates **array-based tree representation**, recursive heap validation, and dynamic insertion.  
- Foundation for implementing more advanced heap operations, such as deletion or heap sort.
