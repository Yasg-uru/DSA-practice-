/*
    Problem: Minimum Number of Buses to Destination (LeetCode 815)
    Approach: Breadth-First Search (BFS)

    - The problem is modeled as a **graph traversal**.
    - Each **bus stop** is a node, and each **bus route** connects multiple stops.
    - We perform a **BFS traversal** to find the shortest path (minimum buses) from `source` to `target`.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // If the source and target are the same, no buses are needed
        if (source == target) return 0;

        // Step 1: Build a mapping of bus stops to routes that pass through them
        unordered_map<int, vector<int>> stopToRoutes;
        for (int route = 0; route < routes.size(); route++) {
            for (int stop : routes[route]) {
                stopToRoutes[stop].push_back(route);
            }
        }

        // Step 2: Initialize BFS
        queue<int> q;                      // Queue to store stops
        unordered_set<int> visitedStops;    // Stops we've already visited
        unordered_set<int> visitedRoutes;   // Routes we've already taken
        q.push(source);
        visitedStops.insert(source);
        
        int buses = 0; // Number of buses taken

        // Step 3: Perform BFS
        while (!q.empty()) {
            int size = q.size();
            buses++; // Each level in BFS represents taking a new bus

            while (size--) {
                int currStop = q.front();
                q.pop();

                // Explore all routes that pass through the current stop
                for (int route : stopToRoutes[currStop]) {
                    if (visitedRoutes.count(route)) continue; // Skip if route already used
                    visitedRoutes.insert(route);

                    // Check all stops in this bus route
                    for (int stop : routes[route]) {
                        if (stop == target) return buses; // Reached the destination

                        if (!visitedStops.count(stop)) {
                            visitedStops.insert(stop);
                            q.push(stop);
                        }
                    }
                }
            }
        }

        // If we cannot reach the target stop, return -1
        return -1;
    }
};

// Example Usage
int main() {
    Solution sol;
    vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
    int source = 1, target = 6;
    cout << "Minimum buses required: " << sol.numBusesToDestination(routes, source, target) << endl;
    return 0;
}
