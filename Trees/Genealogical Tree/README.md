# Genealogical Tree (ArbolGenealogico)

## Problem Statement
Implement the Abstract Data Type (ADT) **ArbolGenealogico** in C to model a **family tree**.  
Each node stores a person's name and links to its parent, first child, and next sibling, allowing hierarchical relationships rather than a sequential list.

## Objective
Develop a reusable tree structure to represent genealogical relationships.  
The program demonstrates recursive traversal, insertion, printing, and memory-safe deletion of hierarchical nodes.

## Program Files

- **`ArbolGenealogico.c`** – Implements all genealogical tree functions including insertion, search, printing, and deletion.  
- **`ArbolGenealogico.h`** – Header file containing the `Nodo` and `ArbolGenealogico` structure definitions and function prototypes.  
- **`main.c`** – Test program that constructs a family tree, allows insertion of new members under a specified parent, and prints the tree structure.

These files are interconnected: `main.c` uses the interface defined in `ArbolGenealogico.h`, which is implemented in `ArbolGenealogico.c`.

## Output

- Displays the tree in a **hierarchical, indented format**, showing parent-child relationships.  
- Allows insertion of new members under an existing parent.  
- Handles memory-safe deletion of the entire tree using recursive post-order traversal.  
- Supports recursive search for nodes by name.

## Potential Applications

- Modeling family trees or hierarchical datasets.  
- Demonstrates **tree traversal**, recursive search, and dynamic memory management.  
- Can be extended to support additional genealogical operations, such as ancestor or descendant queries.
