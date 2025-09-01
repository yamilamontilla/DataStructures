# Binary Search Tree (BST1)

## Problem Statement
Implement the Abstract Data Type (ADT) **ArbolBinarioDeBusqueda** in C, which represents a **binary search tree (BST)** that does not allow duplicate elements.  
The BST supports insertion, search, and traversal operations, maintaining the binary search property: for each node, all elements in the left subtree are smaller, and all elements in the right subtree are larger.

## Objective
Develop a basic binary search tree structure capable of maintaining ordered data efficiently.  
The program demonstrates proper BST insertion, recursive search, and memory-safe destruction of tree nodes.

## Program Files

- **`ArbolBinarioDeBusqueda.c`** – Implements all BST functions: insertion, private recursive search, printing (with left/right child labeling), and node destruction.  
- **`ArbolBinarioDeBusqueda.h`** – Header file containing the `Nodo` and BST structure definitions and function prototypes for public and private methods.  
- **`main.c`** – Test program that inserts elements to form a sample BST, prints the tree after each insertion, and searches for all inserted elements in both insertion and reverse order.

These files are interconnected: `main.c` uses the interface defined in `ArbolBinarioDeBusqueda.h`, which is implemented in `ArbolBinarioDeBusqueda.c`.

## Output

- Displays the BST structure after each insertion, indicating for each node whether it is a left or right child of its parent.  
- Performs search operations for all inserted elements in both insertion and reverse order, displaying `true` or `false` for each search.  
- Handles memory management properly via a destructor that frees all nodes.

## Potential Applications

- Managing ordered datasets with efficient search and insertion.  
- Foundation for more advanced tree structures, such as AVL trees or Red-Black trees.  
- Demonstrates key **tree traversal**, **recursive search**, and **dynamic memory management** concepts.
