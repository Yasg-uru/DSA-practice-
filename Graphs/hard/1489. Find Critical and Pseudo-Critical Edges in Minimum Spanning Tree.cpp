/*
    Problem: Find Critical and Pseudo-Critical Edges in a Minimum Spanning Tree (MST)
    Approach: Using Kruskal’s Algorithm with Union-Find (Disjoint Set Union - DSU)

    Steps:
    1. **Sort edges** by weight.
    2. **Find MST weight** using Kruskal’s Algorithm.
    3. **Identify Critical Edges**:
       - Remove one edge and check if MST weight increases.
    4. **Identify Pseudo-Critical Edges**:
       - Force include an edge and check if MST weight remains the same.

    Complexity: **O(E^2 logV)**
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int N;

    /*** 🔹 Union-Find (Disjoint Set Union - DSU) with Path Compression ***/
    class UnionFind {
    private:
        vector<int> parent, rank;
        int components; // Number of connected components

    public:
        // Constructor: Initialize DSU with `n` nodes
        UnionFind(int n) {
            parent.resize(n);
            rank.resize(n, 0); // All ranks initially 0
            components = n;     // Each node is its own component

            // Each node is its own parent
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        // Find function with **Path Compression**
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        }

        // Union function with **Rank Optimization**
        void Union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
                components--; // Reduce the number of connected components
            }
        }

        // Returns the number of connected components
        int getComponentCount() {
            return components;
        }
    };

    /*** 🔹 Kruskal’s Algorithm to find Minimum Spanning Tree (MST) ***/
    int Kruskal(vector<vector<int>>& edges, int skip_edge, int add_edge) {
        int sum = 0;
        UnionFind uf(N);

        // If we have an additional edge to add, process it first
        if (add_edge != -1) {
            vector<int> edge = edges[add_edge];
            int u = edge[0], v = edge[1], wt = edge[2];
            sum += wt;
            uf.Union(u, v);
        }

        // Sorting edges by weight
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        // Process each edge and construct the MST
        for (int i = 0; i < edges.size(); i++) {
            if (i == skip_edge) continue; // Skip this edge

            vector<int> edge = edges[i];
            int u = edge[0], v = edge[1], wt = edge[2];

            // Only add edge if it doesn't form a cycle
            if (uf.find(u) != uf.find(v)) {
                uf.Union(u, v);
                sum += wt;
            }
        }

        // If we still have more than one connected component, return an invalid MST weight
        return (uf.getComponentCount() > 1) ? INT_MAX : sum;
    }

    /*** 🔹 Find Critical and Pseudo-Critical Edges in MST ***/
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;

        // Step 1: Add the original index to each edge
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        // Step 2: Sort edges by weight (for Kruskal's Algorithm)
        sort(edges.begin(), edges.end(), [&](vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];
        });

        // Step 3: Find the MST weight
        int MIN_WEIGHT = Kruskal(edges, -1, -1);

        vector<int> criticalEdges, pseudoEdges;

        // Step 4: Identify Critical and Pseudo-Critical Edges
        for (int i = 0; i < edges.size(); i++) {
            // Check if edge `i` is **Critical**
            if (Kruskal(edges, i, -1) > MIN_WEIGHT) {
                criticalEdges.push_back(edges[i][3]);
            }
            // Check if edge `i` is **Pseudo-Critical**
            else if (Kruskal(edges, -1, i) == MIN_WEIGHT) {
                pseudoEdges.push_back(edges[i][3]);
            }
        }

        return {criticalEdges, pseudoEdges};
    }
};
