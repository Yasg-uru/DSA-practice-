/*
    Problem: Shortest Path Visiting All Nodes (LeetCode 847)
    Approach: BFS + Bitmasking

    - We use BFS to explore paths while maintaining a bitmask to track visited nodes.
    - Each node is represented as (currentNode, visitedNodesMask).
    - The goal is to visit all nodes, which means reaching the state where all bits in the mask are set.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, int> P;
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;  // Edge case: Single node, no path needed
        
        queue<P> q;
        set<P> visited; // Stores visited (node, bitmask) pairs
        
        // Initialize BFS queue with all nodes as starting points
        for (int i = 0; i < n; i++) {
            int mask = (1 << i); // Set only the i-th bit in the mask
            q.push({i, mask});
            visited.insert({i, mask});
        }
        
        int destinationMask = (1 << n) - 1; // All nodes visited when mask == 2^n - 1
        int pathLength = 0; // Tracks BFS levels (steps)
        
        while (!q.empty()) {
            int size = q.size();
            pathLength++;
            
            while (size--) {
                int currNode = q.front().first;
                int currMask = q.front().second;
                q.pop();
                
                // Explore neighbors
                for (int& neighbor : graph[currNode]) {
                    int nextMask = currMask | (1 << neighbor); // Mark neighbor as visited
                    
                    // If we visited all nodes, return the path length
                    if (nextMask == destinationMask) return pathLength;
                    
                    // If this (node, mask) state is new, add it to queue
                    if (visited.find({neighbor, nextMask}) == visited.end()) {
                        q.push({neighbor, nextMask});
                        visited.insert({neighbor, nextMask});
                    }
                }
            }
        }
        return -1; // Should never reach here for a connected graph
    }
};

// Example Usage
int main() {
    Solution solution;
    vector<vector<int>> graph = {{1,2,3}, {0}, {0}, {0}};
    cout << "Shortest Path Length: " << solution.shortestPathLength(graph) << endl;
    return 0;
}
