#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, w;
    Edge(int from, int to, int weight) : u(from), v(to), w(weight) {}
};

class BellmanFord {
public:
    int V; // Number of vertices
    vector<Edge> edges;

    BellmanFord(int vertices) {
        V = vertices;
    }

    void addEdge(int u, int v, int w) {
        edges.emplace_back(u, v, w);
    }

    vector<int> shortestPath(int src) {
        vector<int> dist(V, INF);
        dist[src] = 0;

        // Relax all edges (V - 1) times
        for (int i = 1; i <= V - 1; ++i) {
            for (const auto& e : edges) {
                if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                }
            }
        }

        // Check for negative weight cycles
        for (const auto& e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                cout << "Graph contains a negative weight cycle\n";
                return {}; // or throw error
            }
        }

        return dist;
    }
};
