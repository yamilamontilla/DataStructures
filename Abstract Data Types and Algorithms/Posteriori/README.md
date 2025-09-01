# Posteriori

## Problem Statement  
Compare *a posteriori* the execution time required to sort an array using a bad algorithm (Selection Sort) versus a good algorithm (Quick Sort), regardless of the computer’s performance.  

The program must implement both algorithms, generate arrays of random integers, measure the sorting times, and compare results for small and large arrays.  


## Objective  
- Implement Selection Sort from scratch.  
- Use the standard C library’s `qsort()` to apply Quick Sort.  
- Compare their performance on arrays of different sizes (e.g., 5 vs. 30,000 elements).  
- Understand how algorithmic complexity affects execution time.  


## Program Files  

- **`main.c`** – Orchestrates the program: reads input size, allocates memory dynamically, generates random arrays, calls sorting methods, and prints results with timing information.  
- **`impresionVectores.c` / `impresionVectores.h`** – Implements a printing function to display arrays with ≤10 elements, or a message when too large.  
- **`ordenacionQuickSort.c` / `ordenacionQuickSort.h`** – Provides the comparison function required by `qsort()` to sort integer arrays.  
- **`ordenacionSeleccion.c` / `ordenacionSeleccion.h`** – Implements Selection Sort and a helper function to find the minimum element in a subarray.  

All modules are interconnected:  
`main.c` calls the printing and sorting functions declared in the header files. Selection Sort is fully implemented, while Quick Sort relies on the C standard library (`stdlib.h`).  


## Output  
- Prints the randomly generated array.  
- Displays the array after sorting with Selection Sort, along with the execution time.  
- Displays the array after sorting with Quick Sort (`qsort()`), along with the execution time.  
- Produces two sets of results: one for a small array (5 elements) and one for a large array (30,000 elements).  


## Potential Applications  
- Demonstrates the practical difference between algorithmic complexities: **O(n²)** for Selection Sort vs. **O(n log n)** for Quick Sort.  
- Highlights the importance of algorithm choice in performance-critical systems.  
- Serves as an educational example of modular programming, memory management with `malloc()`/`free()`, and the use of standard library functions (`qsort()`, `clock()`).  
