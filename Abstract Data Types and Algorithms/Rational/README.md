# Rational

## Problem Statement  
Implement the Abstract Data Type (ADT) "Rational" in C. The ADT models fractions with an integer numerator and denominator, including functions for creation, arithmetic operations, simplification, and display.  

## Objective  
- Define a `struct` with numerator and denominator fields.  
- Create rationals with sign normalization (denominator always positive).  
- Implement arithmetic operations: addition and multiplication.  
- Implement Euclidean Algorithm (`calcularMCD`) for simplification.  
- Provide a function to simplify fractions in place.  
- Implement a display function (`escribir`) with formatting rules.  
- Validate preconditions using `assert()`.  
- Test the ADT with multiple input/output scenarios in `main.c`.  


## Program Files  

- **`Racional.c` / `Racional.h`** – Define the `Racional` structure and implement all related functions:  
  - Creation of rationals with normalized sign.  
  - Arithmetic operations: addition and multiplication.  
  - Simplification using the Euclidean Algorithm.  
  - Display function with formatting rules (0 if numerator = 0, only numerator if denominator = 1).  
  - Internal use of `assert()` to enforce preconditions.  

- **`main.c`** – Provides a testing interface:  
  - Reads user input for two rationals (`a` and `b`), ensuring denominators are non-zero.  
  - Displays them in fraction format.  
  - Performs addition and multiplication, showing results before and after simplification.  
  - Tests edge cases: invalid denominators, zero numerator, negative signs handling.  


## Output  
The program prompts the user for input and displays fractions according to rules. Sample outputs include:  
- Display of correctly formatted fractions (e.g., `2/3`, `0`, `5`).  
- Addition and multiplication results, before and after simplification.  
- Handling of invalid inputs (repeated request if denominator = 0).  
- Correct sign normalization (e.g., `-3/-4` becomes `3/4`, `2/-5` becomes `-2/5`).  


## Potential Applications  
- Educational tool for understanding ADTs in C.  
- Demonstrates modular programming with headers and implementations.  
- Illustrates arithmetic with fractions and the importance of simplification.  
- Provides a basis for extending rational arithmetic into larger projects (e.g., symbolic computation).  
