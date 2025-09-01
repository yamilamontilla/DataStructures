# Lists, Stacks, Queues, and Sets

## Overview  
This folder contains a series of C projects focused on the design and implementation of **lists, stacks, queues, and sets** using various underlying data structures such as arrays, linked lists, and hash tables.  
Each project emphasizes modular design through separate `.c` and `.h` files and structured testing in `main.c`.  

The main objective is to develop problem-solving skills by implementing standard data structures, handling collisions, maintaining order, and ensuring efficient access and modification operations.

---

## Projects  

### 1. Closed Addressing  
Implements a **hash table with closed addressing** (linear probing) to handle student records, including collision resolution.  
Features:  
- Insert, delete, and retrieve students by key (student ID)  
- Handles collisions with flags for deleted entries  
- Printing function shows occupied, empty, and deleted slots  

### 2. Contiguous List 1  
Implements a **dynamic contiguous list of integers** (`ListaContigua`) that resizes automatically.  
Features:  
- Constructor and destructor  
- Insert at the end, delete last element  
- Access and modify elements by index  
- Dynamic resizing with `realloc()`  
- Separate interface for printing  

### 3. Contiguous List 2  
Extends **Contiguous List 1** with more flexible operations.  
Features:  
- Insert and delete at any position using `memmove`  
- Concatenate two lists  
- Search for an element with sequential search  

### 4. Doubly Circular Linked List  
Implements a **doubly-linked circular list** (`ListaEnlazada`) of integers.  
Features:  
- Nodes have pointers to previous and next  
- Optimized access with caching last accessed node  
- Supports insertion, deletion, concatenation, and search  
- Efficient O(1) access in sequential operations  

### 5. No Collision  
Implements a **simple hash table without collisions** for student records.  
Features:  
- Direct insertion at the ideal hashed position  
- Query, insert, delete, and print operations  
- Dynamic memory management  

### 6. Open Addressing  
Extends hash tables using **open addressing with linked lists**.  
Features:  
- Each bucket is a doubly circular linked list of students  
- Collision handling by inserting into the smaller list  
- Two hash positions per key for load balancing  
- Reuses `ListaEnlazada` implementation  

### 7. Singly Linked List  
Implements a **simple singly-linked list** of integers.  
Features:  
- Basic insertion, deletion, get, and set operations  
- Dynamic memory allocation for nodes  
- Separate printing interface  
- Serves as a base for more advanced linked structures  

### 8. Sorted List  
Implements a **dynamic contiguous list that maintains order** (`ListaContiguaOrdenada`).  
Features:  
- Insertion keeps list sorted using binary search  
- Search with recursive binary search  
- Delete element by value, not index  
- Ensures list consistency at all times  

### 9. Stack  
Implements a **stack ADT** (`Pila`) using the previously implemented **doubly circular linked list**.  
Features:  
- Push, pop, peek (`verCima`) operations  
- Constant-time O(1) operations  
- Stack operations reuse `ListaEnlazada` without modifying it  
- Menu-driven main program for testing  

---

## Learning Goals  
- Understand different types of **lists** (contiguous, singly-linked, doubly-linked) and their trade-offs  
- Implement **stacks** and explore **LIFO semantics**  
- Design and implement **hash tables** with closed and open addressing  
- Practice **collision resolution techniques** and efficiency considerations  
- Gain experience with **dynamic memory management** and modular programming  
- Apply **searching and ordering algorithms**, including sequential and binary search  
- Strengthen understanding of **data abstraction, encapsulation, and reusable code**
