# Topology

## Problem Statement  
Extend the previous **Graph Traversal** exercise by implementing **Topological Sorting** on a directed graph represented with a boolean adjacency matrix. The traversal can be destructive, meaning the graph may be modified or destroyed during the process.  

## Objective  
Add a recursive method to compute a topological order of the nodes, while optionally preserving the original graph, and demonstrate its correctness using a test graph.  

## Program Files  

- **`Grafo.c`** – Implements the Graph ADT and the topological sorting methods. Includes:  
  - Private method to compute the **in-degree** of a node.  
  - Recursive topological traversal method that may destructively modify the graph.  
  - Public non-recursive topological method that uses an internal copy of the graph to preserve the original.  
- **`ListaContigua.c`** – Reusable contiguous list module used internally to manage the adjacency matrix.  
- **`main.c`** – Test program that demonstrates the topological traversal on a sample graph, prints the resulting order, and verifies that the original graph remains intact when using the non-destructive method.  

These files are interconnected: `main.c` calls the public topological traversal methods in `Grafo.h`, which internally use the private in-degree and recursive traversal methods implemented in `Grafo.c`.  

## Output  
- Prints the topological order of nodes for the sample graph.  
- Demonstrates both destructive and non-destructive traversal, verifying that the original graph can remain unchanged.  
- Illustrates correct handling of dependencies (in-degree) during topological sorting.  

## Potential Applications  
- Scheduling tasks with dependencies in project management.  
- Resolving compilation order in software build systems.  
- Analyzing precedence relations in workflows, manufacturing processes, or course prerequisites.  
