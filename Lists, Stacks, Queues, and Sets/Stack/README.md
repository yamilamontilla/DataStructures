# Stack (Pila)

## Problem Statement  
Implement the Abstract Data Type (ADT) **Pila** in C using the **Doubly Circular Linked List (ListaEnlazada)** from the previous exercise.  
The stack will reuse the existing linked list without modifying it. The stack interface interprets the list as a LIFO (Last In, First Out) structure.

## Objective  
Develop a reusable stack ADT that provides constant-time operations for insertion, removal, and inspection of the top element using a linked list as the underlying storage.  
The focus is on **reusability**, **modular design**, and **efficient O(1) stack operations**.

## Program Files  

- **`ListaEnlazada.c`** – Doubly circular linked list implementation from the previous exercise.  
- **`Pila.c`** – Implements the stack ADT using `ListaEnlazada` as storage. Methods include:  
  - `push()` – Insert an element at the top of the stack  
  - `pop()` – Remove and return the top element (precondition: stack is not empty)  
  - `verCima()` – Return the top element without removing it (precondition: stack is not empty)  
  - `isVacia()` – Check if the stack is empty, returning 1 (true) or 0 (false)  
- **`impresionListasEnlazadas.c`** – Prints the linked list, used to visualize the stack  
- **`main.c`** – Menu-driven test program allowing the user to:  
  1. Push an element onto the stack  
  2. Pop the top element  
  3. View the top element  
  4. Exit the program  

## Output  
- Displays the stack after each operation using `imprimirListaEnlazada()`  
- Shows the top element when requested  
- Provides error messages if pop or verCima are called on an empty stack  

## Potential Applications  
- Typical LIFO use cases such as undo mechanisms, expression evaluation, and function call management  
- Foundation for more advanced data structures like queues, deques, or priority stacks  
- Demonstrates **reuse of existing data structures** to implement new ADTs efficiently
