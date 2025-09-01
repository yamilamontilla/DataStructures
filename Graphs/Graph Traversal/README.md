# Graph Traversal

## Problem Statement  
Extend the previous **Adjacency Matrix** exercise by implementing **Depth-First Search (DFS)** on a graph represented with a boolean adjacency matrix.  

## Objective  
Add functionality to traverse the graph recursively, starting from a given node, and return the order of visited nodes. This enhances the Graph ADT with a standard graph traversal algorithm.  

## Program Files  

- **`Grafo.c`** – Implements the Graph ADT and the DFS algorithm. Includes a private recursive DFS method and a public method that initializes traversal from a given node.  
- **`ListaContigua.c`** – Reusable contiguous list module used internally by the graph to store the adjacency matrix rows.  
- **`main.c`** – Test program that exercises DFS starting from various nodes and prints the traversal order.  

The files are interconnected: `main.c` calls the public DFS method in `Grafo.h`, which internally uses the private recursive DFS implemented in `Grafo.c`.  

## Output  
- Prints the nodes in the order they are visited during a depth-first traversal starting from nodes C, G, and H.  
- Demonstrates proper handling of previously visited nodes to avoid cycles.  
- Shows traversal behavior for a directed, non-acyclic, pseudograph represented by an adjacency matrix.  

## Potential Applications  
- Exploring connectivity and paths in networks, such as transport, communication, or social networks.  
- Foundation for graph algorithms like topological sorting, cycle detection, and pathfinding.  
- Educational demonstration of recursive traversal techniques on matrix-based graph representations.
