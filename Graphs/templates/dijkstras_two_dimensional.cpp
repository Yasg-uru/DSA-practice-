#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include<algorithm>
using namespace std;

// Alias for priority queue elements: {cost/distance, {row, col}}
typedef pair<int, pair<int, int>> P;

class GridDijkstra {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; // 4-way movement

    int shortestPath(vector<vector<int>>& grid, int sourceValue, int targetValue, bool isEffortBased) {
        int m = grid.size();
        int n = grid[0].size();

        // Step 1: Initialize distance matrix with INT_MAX
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));

        // Min-Heap (Priority Queue): {cost, {row, col}}
        priority_queue<P, vector<P>, greater<P>> pq;
        distance[0][0] = 0;
        pq.push({0, {0, 0}});

        // Step 2: Dijkstra’s Algorithm
        while (!pq.empty()) {
            int dist = pq.top().first;
            auto [i, j] = pq.top().second;
            pq.pop();

            // If destination is reached, return the cost
            if (i == m - 1 && j == n - 1) return dist;

            // Step 3: Traverse all possible directions
            for (auto& dir : directions) {
                int ni = i + dir[0], nj = j + dir[1];

                // Check boundary conditions
                if (ni >= 0 && nj >= 0 && ni < m && nj < n) {
                    int cost = isEffortBased ? max(abs(grid[i][j] - grid[ni][nj]), dist) 
                                             : grid[ni][nj] + dist;

                    // Step 4: Relaxation step
                    if (cost < distance[ni][nj]) {
                        distance[ni][nj] = cost;
                        pq.push({cost, {ni, nj}});
                    }
                }
            }
        }

        return -1; // If no path is found
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    GridDijkstra obj;
    
    // Case 1: Minimum Effort Path (Dijkstra on absolute difference)
    int minEffort = obj.shortestPath(grid, 2, 1, true);
    cout << "Minimum Effort Required: " << minEffort << endl;

    // Case 2: Minimum Cost Path (Dijkstra with weighted sum)
    int minCost = obj.shortestPath(grid, 1, 0, false);
    cout << "Minimum Cost Path: " << minCost << endl;

    return 0;
}
