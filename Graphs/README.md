# Graphs

## Overview  
This folder contains a series of projects focused on the implementation and manipulation of **graph data structures** in C.  
Each project explores different graph representations and algorithms, emphasizing modular design through `.c` and `.h` files and structured testing in `main.c`.  

The main objective is to develop skills in modeling complex networks, understanding graph traversal strategies, and implementing algorithms on both adjacency lists and adjacency matrices.  

---

## Projects  

### 1. Adjacency List  
Implements the ADT `EspacioAereo` (Airspace) using an **adjacency list** representation.  
- Represents airports as nodes (`Aeropuerto`) and routes as edges (`Ruta`) with distance and airline information.  
- Supports insertion and deletion of airports and routes.  
- Provides methods to query the existence of airports and routes, and print the network (**red de aeropuertos y rutas aéreas / network of airports and air routes**).  
This project emphasizes **dynamic memory management**, linked lists, and modular programming for complex graph structures.  

### 2. Adjacency Matrix  
Implements the ADT `Grafo` using a **boolean adjacency matrix**.  
- Nodes are represented by single letters, edges by `1` (exists) or `0` (does not exist).  
- Supports insertion and deletion of nodes and edges.  
- Prints the adjacency matrix in a well-formatted way.  
This project highlights **contiguous memory structures**, efficient edge checking, and matrix manipulation.  

### 3. Graph Traversal  
Extends the adjacency matrix graph to implement **Depth-First Search (DFS)**.  
- Includes a private recursive method to explore nodes.  
- Public method initiates traversal from a given node and returns the DFS order.  
- Demonstrates traversal starting from multiple nodes to verify correctness.  
This project reinforces **recursive algorithms**, traversal logic, and the practical use of adjacency matrices for graph exploration.  

### 4. Topology  
Extends DFS to implement **Topological Sorting**.  
- Private method computes in-degree and recursive traversal for topological order.  
- Public method allows non-destructive topological traversal by working on a temporary copy of the graph.  
- Verifies correctness with sample graphs while preserving the original structure.  
This project illustrates **dependency resolution**, ordering of tasks, and recursive graph algorithms.  

---

## Learning Goals  
- Understand and implement **graph data structures** using lists and matrices.  
- Practice **dynamic memory management** and modular programming.  
- Explore **graph algorithms** including DFS and topological sorting.  
- Model real-world networks (airports, routes) and abstract graph problems.  
- Gain experience with recursive algorithms, adjacency structures, and edge-case handling.
