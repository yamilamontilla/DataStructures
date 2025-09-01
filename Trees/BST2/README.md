# Binary Search Tree with Deletion (BST2)

## Problem Statement
Extend the previously implemented ADT **ArbolBinarioDeBusqueda** to support **deletion of nodes** in a binary search tree (BST) that does not allow duplicates.  
The BST maintains proper ordering and supports multiple deletion scenarios while alternating orientation (left/right) for removing nodes with two children.

## Objective
Develop a binary search tree that supports efficient insertion, search, and deletion operations while maintaining the BST property.  
The program demonstrates recursive node deletion, handling different child cases, and maintaining tree consistency after removal.

## Program Files

- **`ArbolBinarioDeBusqueda.c`** – Implements all BST functions including insertion, search, printing, and deletion.  
- **`ArbolBinarioDeBusqueda.h`** – Header file containing the `Nodo` and BST structure definitions, including the orientation attribute for deletion, and function prototypes.  
- **`main.c`** – Test program that inserts elements into the BST, prints the tree, and performs deletions while printing the tree after each removal.

These files are interconnected: `main.c` uses the interface defined in `ArbolBinarioDeBusqueda.h`, which is implemented in `ArbolBinarioDeBusqueda.c`.

## Output

- Displays the BST structure after each insertion and deletion, indicating for each node whether it is a left or right child of its parent.  
- Handles deletion of nodes with zero, one, or two children, following the alternating orientation rule for two-child deletions.  
- Ensures memory-safe node removal using recursive procedures for deletion, maximum, and minimum node determination.  

## Potential Applications

- Managing ordered datasets with dynamic insertion and removal.  
- Demonstrates key BST concepts including **node deletion**, **recursive search**, and **tree consistency maintenance**.  
- Foundation for more advanced balanced trees such as AVL or Red-Black trees.
