# Point2D

## Problem Statement  
Implement the Abstract Data Type (ADT) **Point2D** in C and test all its methods with a `main` program.  
The ADT represents a point in 2D space with coordinates **x** and **y**, and provides basic operations to manipulate and analyze points.  


## Objective  
Develop a reusable data structure to model two-dimensional points, allowing creation, transformation, visualization, and computation of geometric properties.  


## Program Files  

- **`Point2D.c`** – Contains the implementation of the Point2D functions (constructor, translation, distance to origin, visualization).  
- **`Point2D.h`** – Header file with the structure definition and function prototypes, ensuring modularity and code reuse.  
- **`main.c`** – Test program that demonstrates the functionality of the Point2D ADT by creating points, applying operations, and printing results.  

These files are interconnected: `main.c` uses the interface defined in `Point2D.h`, which is implemented in `Point2D.c`.  


## Output  
- Prints the coordinates of the points created.  
- Displays the new position of a point after being translated along the x and y axes.  
- Shows the computed distance from a point to the origin using the Pythagorean theorem.  


## Potential Applications  
- Geometric and algebraic computations in 2D space.  
- Foundation for vector operations, physics simulations, or computer graphics.  
- A reusable building block for more advanced data structures and algorithms involving spatial data.  
