# Trees

## Overview  
This folder contains a series of C projects focused on the design and implementation of **tree-based data structures** including binary search trees, AVL trees, genealogical trees, and heaps.  
Each project emphasizes modular design through separate `.c` and `.h` files and structured testing in `main.c`.  

The main objective is to develop problem-solving skills by implementing hierarchical data structures, ensuring balanced operations, maintaining heap properties, and supporting efficient insertion, deletion, and search operations.

---

## Projects  

### 1. AVL Tree  
Implements an **AVL tree** (self-balancing binary search tree) that does not allow duplicates.  
Features:  
- Automatic height and balance factor calculation  
- Four types of rotations (single and double) to maintain balance  
- Private and public methods for insertion, searching, printing, and destruction  
- Demonstrates rebalancing after insertions  

### 2. BST1  
Implements a **basic binary search tree** without duplicates.  
Features:  
- Nodes have pointers to parent, left, and right children  
- Public and private methods for insertion, searching, printing, and destruction  
- Tracks number of nodes and prints node relationship (left/right child)  
- Includes time complexity annotations for best and worst topologies  

### 3. BST2  
Extends BST1 with **deletion capabilities**.  
Features:  
- Tracks orientation for deletion (left or right)  
- Methods for deleting nodes considering four possible cases  
- Uses private recursive methods to find maximum/minimum and remove nodes  
- Maintains BST properties after deletions  
- Tested with insertion and deletion sequences  

### 4. Genealogical Tree  
Implements a **general tree** representing genealogical relationships.  
Features:  
- Nodes contain a name, pointer to parent, first child, and next sibling  
- Methods to count children, access children, search by name, insert, print, and destroy  
- Maintains hierarchical structure with dynamic memory allocation  
- Menu-driven main program allows inserting and printing nodes  

### 5. Heap1  
Implements a **min-heap** using a contiguous list (`ListaContigua`) as underlying storage.  
Features:  
- Elements stored in a contiguous array, maintaining the heap property  
- Methods for insertion and printing  
- Recursive validation method to check heap property  
- Demonstrates building a heap step by step with example insertions  

### 6. Heap2  
Extends Heap1 with **deletion and heap sort**.  
Features:  
- Methods to remove the root and restructure the heap  
- Method to get a copy of the root without removing it  
- Heap-based sorting (`ordenarPorMonticulo`) for arbitrary arrays  
- Demonstrates insertion, deletion, and sorting with structured output  
- Handles duplicates correctly in both heap and sorting  

---

## Learning Goals  
- Understand **tree structures**: binary search trees, AVL trees, general trees, and heaps  
- Implement **self-balancing mechanisms** in AVL trees to ensure O(log n) operations  
- Practice **node insertion, deletion, and search** in hierarchical structures  
- Explore **heap properties** and array-based tree representations  
- Implement recursive algorithms for printing, destruction, and validation  
- Strengthen understanding of **dynamic memory allocation, pointers, and modular programming**  
- Apply **sorting algorithms using heaps** and verify correctness with structured tests
