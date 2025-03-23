#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;
    int components; // Number of connected components

public:
    // Constructor: Initialize the DSU with 'n' elements
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0); // Initially, all ranks are 0
        components = n; // Initially, each node is its own component
        
        // Each node is its own parent (self-loop)
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find function with Path Compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union by Rank: Merge two sets
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false; // Already in the same set
        
        // Attach smaller tree under larger tree
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        components--; // Reduce component count
        return true;
    }

    // Check if two nodes belong to the same component
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

    // Get the number of connected components
    int getComponentCount() {
        return components;
    }
};

// Driver Code
int main() {
    int n = 7; // Number of nodes
    UnionFind uf(n);

    // Sample Unions
    uf.unite(0, 1);
    uf.unite(1, 2);
    uf.unite(3, 4);
    uf.unite(5, 6);

    cout << "Connected Components: " << uf.getComponentCount() << endl;
    cout << "Are 0 and 2 connected? " << (uf.isConnected(0, 2) ? "Yes" : "No") << endl;
    cout << "Are 3 and 5 connected? " << (uf.isConnected(3, 5) ? "Yes" : "No") << endl;

    // Merge components
    uf.unite(2, 3);
    cout << "Connected Components after merging (2,3): " << uf.getComponentCount() << endl;

    return 0;
}
