# Abstract Data Types and Algorithms

## Overview  
This folder contains a collection of projects focused on the design and implementation of **Abstract Data Types (ADTs)** and basic **algorithm analysis** in C.  
Each project introduces a specific data abstraction or algorithmic concept, highlighting modular design through the use of `.c` and `.h` files, as well as structured testing in `main.c`.  

The main objective is to strengthen problem-solving skills in computer science by modeling mathematical concepts (e.g., points, rationals) and evaluating algorithmic efficiency (e.g., sorting methods).  

---

## Projects  

### 1. Point2D  
Implements the ADT `Point2D` to represent points in a 2D Cartesian plane.  
Includes operations such as creation, coordinate manipulation, and distance calculation.  
This project emphasizes encapsulation and modularity when handling geometric data.  


### 2. Posteriori  
Compares sorting algorithms **a posteriori**, analyzing execution times with different input sizes.  
- Selection Sort (inefficient) implemented manually.  
- Quick Sort (efficient) using the C standard library (`qsort`).  
The project demonstrates how algorithmic complexity directly impacts execution time, especially with large datasets.  


### 3. Rational  
Implements the ADT `Rational` to model fractions with integer numerator and denominator.  
Includes:  
- Normalized creation of rationals (denominator always positive).  
- Arithmetic operations (addition, multiplication).  
- Simplification using the Euclidean Algorithm.  
- Display function with special formatting rules.  
This project highlights modular programming, preconditions with `assert()`, and the separation of model (`struct` and logic) from interface.  

---

## Learning Goals  
- Understand the concept and design of **Abstract Data Types**.  
- Practice **modular programming** using headers and implementation files.  
- Evaluate **algorithm efficiency** through experimental comparison.  
- Strengthen mathematical modeling in programming (geometry, fractions).  
- Gain experience with dynamic memory allocation, input validation, and assertions.  
