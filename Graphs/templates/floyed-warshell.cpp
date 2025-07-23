#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class FloydWarshall {
public:
    int V;
    vector<vector<int>> dist;

    FloydWarshall(int n) : V(n) {
        dist.assign(V, vector<int>(V, INF));
        for (int i = 0; i < V; ++i)
            dist[i][i] = 0;
    }

    void addEdge(int u, int v, int w) {
        dist[u][v] = w; // For undirected graph, add dist[v][u] = w as well
    }

    void computeShortestPaths() {
        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    bool hasNegativeCycle() {
        for (int i = 0; i < V; ++i) {
            if (dist[i][i] < 0) return true;
        }
        return false;
    }
};
