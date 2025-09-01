# Adjacency Matrix

## Problem Statement  
Implement the Abstract Data Type (ADT) **Graph** in C using a boolean adjacency matrix.  
The graph is directed, non-acyclic, not a multigraph, pseudograph, not necessarily connected, and unlabeled. Each node is represented by a unique letter, which cannot be repeated.  

## Objective  
Develop a graph ADT that supports node and edge insertion/deletion, existence checks, and visualization using a boolean adjacency matrix.  

## Program Files  

- **`Grafo.c`** – Implements the Graph ADT: construction/destruction, insert/delete nodes, insert/delete edges, check existence of nodes/edges, print adjacency matrix.  
- **`ListaContigua.c`** – Provides a reusable contiguous list module used internally to store rows of the adjacency matrix.  
- **`main.c`** – Test program that exercises all operations of the Graph ADT.  

The files are interconnected: `main.c` calls the public interface in `Grafo.h`, which is implemented in `Grafo.c` using `ListaContigua` for internal storage.  

## Output  
- Prints the adjacency matrix of the graph, with row and column labels for each node.  
- Shows updated matrices after inserting and deleting nodes and edges according to the test cases.  
- Demonstrates handling of directed edges, including self-loops and multiple insertions/deletions.  

## Potential Applications  
- Modeling networks such as computer networks, social networks, or transport networks.  
- Algorithms for pathfinding, connectivity, and graph analysis.  
- Educational tool to understand graph representations and operations using adjacency matrices.
