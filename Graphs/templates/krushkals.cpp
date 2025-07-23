#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    // Constructor for convenience
    Edge(int from, int to, int w) : u(from), v(to), weight(w) {}
};

// DSU (Disjoint Set Union) class with path compression and union by rank
class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        // Initially, every vertex is its own parent (each vertex is in its own set)
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }
    
    bool unionSet(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);
        if (xroot == yroot) return false; // already in the same set
        
        // Union by rank
        if (rank[xroot] < rank[yroot]) {
            parent[xroot] = yroot;
        } else if (rank[xroot] > rank[yroot]) {
            parent[yroot] = xroot;
        } else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
        return true;
    }
};

class KruskalMST {
public:
    // Returns the weight of the MST.
    // The graph has V vertices and a list of edges
    static int kruskal(int V, vector<Edge>& edges) {
        // Sort edges based on weight
        sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
            return a.weight < b.weight;
        });
        
        DSU dsu(V);
        int mstWeight = 0;
        vector<Edge> mstEdges;
        
        for (auto &edge : edges) {
            // If including the edge does not form a cycle
            if (dsu.unionSet(edge.u, edge.v)) {
                mstWeight += edge.weight;
                mstEdges.push_back(edge);
            }
        }
        
        // Optional: Check if we've formed a spanning tree (if graph is connected)
        if (mstEdges.size() != V - 1) {
            cout << "Graph is not connected. MST cannot be formed for all vertices.\n";
            return -1;
        }
        
        return mstWeight;
    }
};

int main() {
    int V = 4;  // number of vertices
    vector<Edge> edges;
    // Example graph:
    // Edge from vertex 0 to 1 with weight 10
    // Edge from vertex 0 to 2 with weight 6
    // Edge from vertex 0 to 3 with weight 5
    // Edge from vertex 1 to 3 with weight 15
    // Edge from vertex 2 to 3 with weight 4
    edges.push_back(Edge(0, 1, 10));
    edges.push_back(Edge(0, 2, 6));
    edges.push_back(Edge(0, 3, 5));
    edges.push_back(Edge(1, 3, 15));
    edges.push_back(Edge(2, 3, 4));

    int mstWeight = KruskalMST::kruskal(V, edges);
    if (mstWeight != -1)
        cout << "Total weight of MST is: " << mstWeight << endl;
    return 0;
}
