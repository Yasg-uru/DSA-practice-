#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;  // Number of vertices
    vector<vector<int>> adj;  // Adjacency list

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add a directed edge u -> v
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Function to detect cycles using DFS
    bool detectCycleUtil(int node, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[node] = true;
        inRecursion[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (detectCycleUtil(neighbor, visited, inRecursion))
                    return true;
            } else if (inRecursion[neighbor]) {
                return true;  // Cycle detected
            }
        }

        inRecursion[node] = false; // Backtracking
        return false;
    }

    // Wrapper function to detect cycle in the entire graph
    bool hasCycle() {
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (detectCycleUtil(i, visited, inRecursion))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1); // Cycle here (1 → 2 → 3 → 1)

    if (g.hasCycle()) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle found." << endl;
    }

    return 0;
}
