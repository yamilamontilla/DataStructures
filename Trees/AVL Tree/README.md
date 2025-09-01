# AVL Tree

## Problem Statement
Implement the Abstract Data Type (ADT) **AVL** in C, which represents a **self-balancing binary search tree** that does not allow duplicate elements.  
The tree automatically maintains balance after each insertion by performing appropriate rotations (single or double) and updating node heights and balance factors.

## Objective
Develop a robust AVL tree structure capable of maintaining O(log n) search, insertion, and deletion operations.  
The program demonstrates tree balancing techniques, node rotations, and proper updating of heights and balance factors to ensure the tree remains AVL-compliant after each insertion.

## Program Files

- **`AVL.c`** – Implements all AVL tree functions: insertion, private helper methods (`insertarHoja()`, `reequilibrar()`, rotations), height and balance updates, and printing.  
- **`AVL.h`** – Header file containing the `Nodo` and `AVL` structure definitions and function prototypes for public and private methods.  
- **`main.c`** – Test program that incrementally inserts elements to trigger all four types of rotations (single left/right and double left-right/right-left) and prints the tree after each insertion.

These files are interconnected: `main.c` uses the interface defined in `AVL.h`, which is implemented in `AVL.c`.

## Output

- Displays the AVL tree structure after each insertion.  
- Automatically performs rotations to maintain balance.  
- Updates and prints node heights and balance factors.  
- Demonstrates the four possible rotations:  
  1. Single Left Rotation  
  2. Single Right Rotation  
  3. Double Left-Right Rotation  
  4. Double Right-Left Rotation  

## Potential Applications

- Efficiently maintaining sorted datasets with frequent insertions.  
- Foundation for balanced search trees in databases, dictionaries, and priority-based structures.  
- Demonstrates the principles of **tree rotations**, **height management**, and **balance factor calculation**.  
- Useful for understanding advanced recursive data structures and modular programming in C.
