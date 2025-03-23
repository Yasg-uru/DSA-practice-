/*
    Problem: Number of Ways to Arrive at Destination
    Approach: Dijkstra’s Algorithm (Modified for Counting Paths)
    
    Explanation:
    - We use a **priority queue (Min-Heap)** to implement **Dijkstra’s Algorithm**.
    - `result[i]` stores the **shortest time** to reach node `i`.
    - `count[i]` stores the **number of ways** to reach node `i` in the shortest time.
    
    **Concept:**
    - If we find a **shorter path** to a node `v` from `u`, we:
      - Update `result[v] = result[u] + travel_time`
      - Copy the number of ways: `count[v] = count[u]`
    - If we find **another shortest path** (equal distance), we:
      - Increase the count: `count[v] = (count[v] + count[u]) % MOD`
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<long long, int> P;
    const int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        // Min-Heap for Dijkstra’s Algorithm (stores {time, node})
        priority_queue<P, vector<P>, greater<P>> pq;
        
        // Stores shortest time to reach each node
        vector<long long> result(n, LLONG_MAX);
        result[0] = 0;
        
        // Stores the number of shortest paths to each node
        vector<int> count(n, 0);
        count[0] = 1;

        // Adjacency list representation of the graph
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        // Start Dijkstra from node 0
        pq.push({0, 0});

        while (!pq.empty()) {
            long long currTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int travelTime = neighbor.second;
                long long newTime = currTime + travelTime;

                // Found a shorter path to nextNode
                if (newTime < result[nextNode]) {
                    result[nextNode] = newTime;
                    count[nextNode] = count[node];  // Copy the number of ways
                    pq.push({newTime, nextNode});
                }
                // Found another shortest path to nextNode
                else if (newTime == result[nextNode]) {
                    count[nextNode] = (count[nextNode] + count[node]) % MOD;
                }
            }
        }

        return count[n - 1];  // Return number of ways to reach node (n-1)
    }
};
