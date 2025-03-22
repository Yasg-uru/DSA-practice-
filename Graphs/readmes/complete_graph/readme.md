# Complete Graph - Placement Practice

## 📌 What is a Complete Graph?
A **complete graph** is a type of graph in which every pair of distinct vertices is connected by an edge. It is denoted as **Kₙ**, where **n** represents the number of vertices.

### ✨ Properties of a Complete Graph:
1. **Number of Edges**:
   - A complete graph with **n** vertices has **(n * (n - 1)) / 2** edges.
2. **Degree of Each Vertex**:
   - Every vertex in a complete graph has a degree of **(n - 1)**.
3. **Connectivity**:
   - A complete graph is fully connected and has the highest possible connectivity.
4. **Chromatic Number**:
   - The chromatic number of **Kₙ** is **n** (each vertex needs a different color).
5. **Planarity**:
   - A complete graph is **not planar** for **n ≥ 5** (it cannot be drawn without edge crossings).
6. **Eulerian and Hamiltonian Properties**:
   - **Eulerian Circuit** exists if **n is odd**.
   - **Hamiltonian Circuit** always exists for **n ≥ 3**.

## 🚀 How to Identify a Complete Graph?
To check if a given graph is complete:
1. Count the **number of vertices (V)**.
2. Count the **number of edges (E)**.
3. Verify if:
   
   \[ E = \frac{V (V - 1)}{2} \]
4. Ensure each node has **V-1 neighbors**.

## 🛠️ Code Template for Connected Components
We use **DFS (Depth-First Search)** to explore connected components and check if they are complete graphs.

- The provided C++ template helps find complete components in a given graph.
- It constructs an **adjacency list**, performs **DFS traversal**, and counts **nodes and edges** in each component.
- If the number of edges in a component matches the required formula, it is a complete component.

## 📂 Usage
- This template is useful for solving **graph-related problems** in coding interviews.
- Modify the condition inside `countConnectedComponents()` to adapt to different **connected component** problems.



