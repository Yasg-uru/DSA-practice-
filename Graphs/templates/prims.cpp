#include <iostream>
#include <vector>
#include <queue>
#include <utility> // for pair
using namespace std;

class PrimMST {
public:
    // Function to find the MST total weight
    static int primMST(int V, vector<vector<pair<int, int>>>& adj) {
        vector<bool> inMST(V, false);      // To track nodes in MST
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // {weight, node}
        int totalWeight = 0;

        // Start from node 0
        pq.push({0, 0}); // (weight, vertex)

        while (!pq.empty()) {
            auto [weight, u] = pq.top();
            pq.pop();

            if (inMST[u]) continue;

            inMST[u] = true;
            totalWeight += weight;

            for (auto &[v, w] : adj[u]) {
                if (!inMST[v]) {
                    pq.push({w, v});
                }
            }
        }

        return totalWeight;
    }
};

int main() {
    int V = 5; // number of vertices
    vector<vector<pair<int, int>>> adj(V);

    // Example: undirected weighted edges (u, v, w)
    vector<tuple<int, int, int>> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3},
        {1, 3, 8}, {1, 4, 5}, {2, 4, 7}
    };

    // Build adjacency list
    for (auto &[u, v, w] : edges) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // since the graph is undirected
    }

    int mstWeight = PrimMST::primMST(V, adj);
    cout << "Total weight of MST: " << mstWeight << endl;

    return 0;
}
